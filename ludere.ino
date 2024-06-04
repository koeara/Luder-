#include <MD_MAX72xx.h>
#include <SPI.h>
#include <SD.h>
#include <stdlib.h>

#define PRINT(s, v) { Serial.print(F(s)); Serial.print(v); }

// Define o tipo de hardware conectado
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW

// Define o número de dispositivos conectados
#define MAX_DEVICES 4

// Pinos de conexão no Arduino
#define CLK_PIN   7
#define DATA_PIN  9
#define CS_PIN    8

#define COL_SIZE 8  // Número de colunas por módulo

#define BTN_VERDE_PIN 5
#define BTN_VERMELHO_PIN 3
#define BTN_AZUL_PIN 10
#define BTN_AMARELO_PIN 2

const int buzzerPin = 6;

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);
File myFile;

char currentChars[MAX_DEVICES];
int currentIndexes[MAX_DEVICES] = {0};
char* groups[] = {"ABCD", "EFGH", "IJKL", "MNOP", "QRST", "UVWX", "YZ  "};
int currentGroupIndex = 0;

unsigned long lastUpdateTime = 0;
unsigned long debounceDelay = 50;
unsigned long lastDebounceTime = 0;

enum ToneState { IDLE, PLAYING };
ToneState toneState = IDLE;
unsigned long toneStartTime = 0;
int currentToneFrequency = 0;
int currentToneDuration = 0;

void printLetterOnMatrix(char letter, int matrixIndex) {
  uint8_t cBuf[8];

  if (letter != '\0') {
    int charWidth = mx.getChar(letter, sizeof(cBuf) / sizeof(cBuf[0]), cBuf);
    
    // Mirroring and flipping the character vertically
    for (int col = 0; col < charWidth; col++) {
      uint8_t colData = cBuf[col];
      uint8_t mirroredData = 0;

      for (int row = 0; row < 8; row++) {
        if (colData & (1 << row)) {
          mirroredData |= (1 << (7 - row));
        }
      }
      
      mx.setColumn((matrixIndex * COL_SIZE) + col, mirroredData);
    }

    // Clear the remaining columns if any
    for (int col = charWidth; col < COL_SIZE; col++) {
      mx.setColumn((matrixIndex * COL_SIZE) + col, 0);
    }
  } else {
    for (int col = 0; col < COL_SIZE; col++) {
      mx.setColumn((matrixIndex * COL_SIZE) + col, 0);
    }
  }
  mx.update();
}

void clearMatrix() {
  mx.clear();
  mx.update();
}

void playTone(int frequency, int duration) {
  toneState = PLAYING;
  toneStartTime = millis();
  currentToneFrequency = frequency;
  currentToneDuration = duration;
  tone(buzzerPin, frequency, duration);
}

void stopTone() {
  noTone(buzzerPin);
  toneState = IDLE;
}

void playErrorSound() {
  playTone(300, 150);
  delay(100);
  playTone(300, 150);
}

void playSuccessSound() {
  playTone(880, 100);
  delay(100);
  playTone(988, 100);
  delay(100);
  playTone(1047, 100);
  delay(100);
  playTone(1175, 200);
}

void playCorrectLetterSound() {
  playTone(660, 100);
  delay(50);
  playTone(880, 100);
}

void setup() {
  mx.begin();
  mx.control(MD_MAX72XX::INTENSITY, MAX_INTENSITY / 4);
  Serial.begin(9600);
  Serial.println("\n[Mensagens com modulo MAX7219]\n");
  SD.begin();

  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");

    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close();
  } else {
    Serial.println("error opening test.txt");
  }

  mx.clear();

  pinMode(BTN_VERDE_PIN, INPUT_PULLUP);
  pinMode(BTN_VERMELHO_PIN, INPUT_PULLUP);
  pinMode(BTN_AZUL_PIN, INPUT_PULLUP);
  pinMode(BTN_AMARELO_PIN, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);                                                                 

  randomSeed(analogRead(0));

  for (int i = 0; i < MAX_DEVICES; i++) {
    currentIndexes[i] = random(0, strlen(groups[currentGroupIndex]));
    currentChars[i] = groups[currentGroupIndex][currentIndexes[i]];
    printLetterOnMatrix(currentChars[i], i);
  }
}

void loop() {
  unsigned long currentTime = millis();
  bool updated = false;
  bool correctLetterPlaced = false;

  if (currentTime - lastDebounceTime > debounceDelay) {
    if (digitalRead(BTN_AZUL_PIN) == LOW) {
      currentIndexes[0] = (currentIndexes[0] + 1) % strlen(groups[currentGroupIndex]);
      currentChars[0] = groups[currentGroupIndex][currentIndexes[0]];
      updated = true;
      lastDebounceTime = currentTime;
      if (currentChars[0] == groups[currentGroupIndex][0]) correctLetterPlaced = true;
    }

    if (digitalRead(BTN_AMARELO_PIN) == LOW) {
      currentIndexes[1] = (currentIndexes[1] + 1) % strlen(groups[currentGroupIndex]);
      currentChars[1] = groups[currentGroupIndex][currentIndexes[1]];
      updated = true;
      lastDebounceTime = currentTime;
      if (currentChars[1] == groups[currentGroupIndex][1]) correctLetterPlaced = true;
    }

    if (digitalRead(BTN_VERMELHO_PIN) == LOW) {
      currentIndexes[2] = (currentIndexes[2] + 1) % strlen(groups[currentGroupIndex]);
      currentChars[2] = groups[currentGroupIndex][currentIndexes[2]];
      updated = true;
      lastDebounceTime = currentTime;
      if (currentChars[2] == groups[currentGroupIndex][2]) correctLetterPlaced = true;
    } 

    if (digitalRead(BTN_VERDE_PIN) == LOW) {
      currentIndexes[3] = (currentIndexes[3] + 1) % strlen(groups[currentGroupIndex]);
      currentChars[3] = groups[currentGroupIndex][currentIndexes[3]];
      updated = true;
      lastDebounceTime = currentTime;
      if (currentChars[3] == groups[currentGroupIndex][3]) correctLetterPlaced = true;

      if (strncmp(currentChars, groups[currentGroupIndex], MAX_DEVICES) == 0) {
        playSuccessSound();

        unsigned long blinkStartTime = millis();
        for (int i = 0; i < 3; i++) {
          clearMatrix();
          while (millis() - blinkStartTime < 200);
          for (int i = 0; i < MAX_DEVICES; i++) {
            printLetterOnMatrix(currentChars[i], i);
          }
          blinkStartTime = millis();
          while (millis() - blinkStartTime < 200);
        }

        currentGroupIndex = (currentGroupIndex + 1) % (sizeof(groups) / sizeof(groups[0]));
        for (int i = 0; i < MAX_DEVICES; i++) {
          currentIndexes[i] = random(0, strlen(groups[currentGroupIndex]));
          currentChars[i] = groups[currentGroupIndex][currentIndexes[i]];
          printLetterOnMatrix(currentChars[i], i);
        }
        delay(1000);
      } else {
        playErrorSound();
      }
    }
  }

  if (updated) {
    for (int i = 0; i < MAX_DEVICES; i++) {
      printLetterOnMatrix(currentChars[i], i);
    }
    lastUpdateTime = currentTime;

    if (correctLetterPlaced) {
      playCorrectLetterSound();
    }
  }

  if (toneState == PLAYING && currentTime - toneStartTime >= currentToneDuration) {
    stopTone();
  }
}
