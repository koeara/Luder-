<h1>Luderê: Mini Fliperama Educacional 🎮📚</h1>
    <h2>Visão Geral 🌍</h2>
    <p>O projeto Luderê é um mini fliperama educacional desenvolvido para auxiliar na educação de crianças na Ilha do Combu, no estado do Pará. Ele utiliza um display de matriz de LEDs controlado por um Arduino, botões coloridos e um buzzer para criar uma experiência interativa de aprendizado. O principal objetivo é tornar a educação mais divertida e envolvente, ajudando as crianças a aprenderem através do jogo.</p>
    <h2>Funcionalidades Principais 🚀</h2>
    <ul>
        <li><strong>Display de Matriz de LEDs:</strong> Exibe letras e grupos de letras que as crianças devem identificar e formar corretamente.</li>
        <li><strong>Botões de Interação:</strong> Botões coloridos (verde, vermelho, azul e amarelo) permitem que as crianças interajam com o jogo, alterando as letras exibidas.</li>
        <li><strong>Feedback Sonoro:</strong> Utiliza um buzzer para dar feedback sonoro, indicando erros e acertos, bem como tocando sons de sucesso quando a tarefa é concluída corretamente.</li>
    </ul>
    <div> 
        <img src="https://github.com/henriquepmartins/ludere/assets/125284120/d38efc47-11be-4af2-ad41-9359457bb48c" width="200px"/>
    </div>
    <h2>Diferenciais do Projeto ✨</h2>
    <ul>
        <li><strong>Educação Gamificada:</strong> O Luderê combina elementos de jogo com aprendizado, tornando a experiência educacional mais atrativa e motivadora para as crianças.</li>
        <li><strong>Integração de Hardware Simples:</strong> Utiliza componentes comuns e acessíveis, como o Arduino e a matriz de LEDs, facilitando a replicação e a manutenção do projeto.</li>
        <li><strong>Feedback Imediato:</strong> Sons de erro e sucesso fornecem um feedback instantâneo, ajudando as crianças a entenderem seus acertos e erros em tempo real.</li>
        <li><strong>Ciclagem Automática de Tarefas:</strong> Após cada sequência correta, o sistema automaticamente apresenta um novo desafio, mantendo as crianças engajadas e desafiadas.</li>
    </ul>
    <h2>Componentes Utilizados 🛠️</h2>
    <ul>
        <li><strong>Arduino UNO:</strong> Microcontrolador que controla todo o sistema.</li>
        <li><strong>Matriz de LEDs MAX7219:</strong> Utilizada para exibir letras e mensagens.</li>
        <li><strong>Botões Coloridos:</strong> Utilizados para interação (pinos 2, 3, 5 e 10).</li>
        <li><strong>Buzzer:</strong> Utilizado para sons de feedback (pino 6).</li>
        <li><strong>Cartão SD:</strong> Armazena dados e mensagens (pino 4).</li>
        <li><strong>Componentes Adicionais:</strong> Resistores, jumpers, breadboard.</li>
    </ul>
    <h2>Configuração do Hardware 🔧</h2>
    <h3>Conexões da Matriz de LEDs:</h3>
    <ul>
        <li>Pino de Dados (DIN) -> Pino 9 do Arduino</li>
        <li>Pino de Clock (CLK) -> Pino 7 do Arduino</li>
        <li>Pino de Chip Select (CS) -> Pino 8 do Arduino</li>
    </ul>
    <h3>Conexões dos Botões:</h3>
    <ul>
        <li>Botão Verde -> Pino 5 do Arduino</li>
        <li>Botão Vermelho -> Pino 3 do Arduino</li>
        <li>Botão Azul -> Pino 10 do Arduino</li>
        <li>Botão Amarelo -> Pino 2 do Arduino</li>
    </ul>
    <h3>Conexão do Buzzer:</h3>
    <ul>
        <li>Buzzer -> Pino 6 do Arduino</li>
    </ul>
    <h3>Conexão do Cartão SD:</h3>
    <ul>
        <li>Cartão SD -> Pino 4 do Arduino</li>
    </ul>
    <h2>Configuração do Software 💻</h2>
    <h3>Bibliotecas Necessárias 📚</h3>
    <p>Para que o código funcione corretamente, é necessário instalar algumas bibliotecas no Arduino IDE. Abaixo estão as bibliotecas necessárias:</p>
    <ul>
        <li><strong>MD_MAX72XX:</strong> Biblioteca para controlar a matriz de LEDs.</li>
        <li><strong>SPI:</strong> Biblioteca para comunicação SPI.</li>
        <li><strong>SD:</strong> Biblioteca para leitura e escrita em cartão SD.</li>
    </ul>
    <h3>Como Instalar as Bibliotecas 📦</h3>
    <ol>
        <li><strong>Instale o Arduino IDE:</strong> Baixe e instale a IDE do Arduino a partir do site oficial <a href="https://www.arduino.cc/en/software">Arduino</a>.</li>
        <li><strong>Instale as Bibliotecas:</strong>
            <ul>
                <li><strong>MD_MAX72XX:</strong>
                    <ul>
                        <li>Vá em <strong>Sketch > Incluir Biblioteca > Gerenciar Bibliotecas...</strong></li>
                        <li>Pesquise por <strong>MD_MAX72XX</strong> e clique em <strong>Instalar</strong>.</li>
                    </ul>
                </li>
                <li><strong>SPI:</strong> Esta biblioteca já vem instalada com a IDE do Arduino.</li>
                <li><strong>SD:</strong>
                    <ul>
                        <li>Vá em <strong>Sketch > Incluir Biblioteca > Gerenciar Bibliotecas...</strong></li>
                        <li>Pesquise por <strong>SD</strong> e clique em <strong>Instalar</strong>.</li>
                    </ul>
                </li>
            </ul>
        </li>
    </ol>
    <h3>Configuração do Código 📝</h3>
    <ol>
        <li><strong>Copie o código fonte:</strong> O código fonte completo está disponível no repositório do projeto. Copie o código e cole na IDE do Arduino.</li>
        <li><strong>Selecione a placa e a porta:</strong> Na IDE do Arduino, selecione a placa <strong>Arduino UNO</strong> e a porta correta para o seu dispositivo.</li>
        <li><strong>Carregue o código:</strong> Carregue o código na placa Arduino clicando no botão <strong>Upload</strong>.</li>
    </ol>
    <h3>Teste do Sistema 🧪</h3>
    <ol>
        <li><strong>Conecte todos os componentes:</strong> Certifique-se de que todos os componentes estão conectados corretamente conforme descrito na seção de configuração do hardware.</li>
        <li><strong>Ligue o Arduino:</strong> Conecte o Arduino à fonte de alimentação ou à porta USB do computador.</li>
        <li><strong>Verifique a funcionalidade:</strong> O sistema deve começar a exibir letras na matriz de LEDs. Pressione os botões para alterar as letras e formar as sequências corretas.</li>
        <li><strong>Feedback Sonoro:</strong> Ouça os sons de feedback ao interagir com o sistema para garantir que o buzzer está funcionando corretamente.</li>
    </ol>
    <h2>Contribuindo 🤝</h2>
    <p>Se você deseja contribuir com o projeto Luderê, siga as etapas abaixo:</p>
    <ol>
        <li><strong>Fork o Repositório:</strong> Faça um fork deste repositório para sua conta no GitHub.</li>
        <li><strong>Clone o Repositório:</strong> Clone o repositório para sua máquina local.</li>
        <li><strong>Crie uma Branch:</strong> Crie uma nova branch para suas modificações (<code>git checkout -b minha-branch</code>).</li>
        <li><strong>Faça as Modificações:</strong> Faça suas modificações e adições ao código.</li>
        <li><strong>Commit:</strong> Faça commit das suas alterações (<code>git commit -m 'Minha contribuição'</code>).</li>
        <li><strong>Push:</strong> Envie suas alterações para o repositório remoto (<code>git push origin minha-branch</code>).</li>
        <li><strong>Pull Request:</strong> Abra um pull request para revisar e mesclar suas alterações.</li>
    </ol>
    <h2>Licença 📜</h2>
    <p>Este projeto está licenciado sob a <a href="LICENSE">Licença MIT</a>.</p>
    <h2>Agradecimentos 🙏</h2>
    <p>Agradecemos a todos os que contribuíram para o desenvolvimento deste projeto e aos educadores da Ilha do Combu que nos inspiraram a criar o Luderê.</p>
    <h2>👥Equipe</h2>
    <p>Antônio Heitor, Cauã Maia, Elissandra Abdon, Giovanni Braga, Henrique Pereira, Matheus Azevedo, Meg Nicolle de Borborema, Rafael Verde e Renan Almeida </p>
