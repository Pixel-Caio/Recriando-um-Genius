# 🤖 [Genius] 
> Genius é um jogo de memorização, principalmente ativando a memória de curto prazo, onde o jogador é apresentado uma sequência que há de repetir, a cada partida a fazendo mais longa. 
### 👥 Equipe (Colaboradores)
> * [Caio](https.github.com/Pixel-Caio)
> * [Daniel](https.github.com/Danmax1331)
> * [Paulo](https.github.com/PaulinBacana)
### 📖 Descrição do Projeto.
> * Qual problema ele resolve?
> * 
> * Qual era o desafio da Semana Industrial?
> * Como ele funciona (visão geral)?
> * Quais tecnologias (hardware e software) foram centrais?
### 🔧 Hardware (Componentes Utilizados) Lista de todos os componentes físicos necessários para montar o projeto. 
* **Controlador:** 1x Arduino Uno R3 (ou Raspberry Pi, ESP32, etc.)
* **Sensores:** 1x Sensor Ultrassônico HC-SR04 * 2x Sensores de Fim de Curso *
* **Atuadores:**     * 3x Servo Motores MG996R (Eixo X, Y, Garra)     * 1x Motor de Passo NEMA 17 *
* **Outros:**     * 1x Protoboard     * Jumpers (Macho-Macho, Macho-Fêmea)     * Fonte de alimentação externa 5V/2A     * Peças 3D (disponibilizar o .STL se possível)
### 💻 Software e Dependências O que é necessário para rodar o código? 
* **Firmware/Código:**
* O código principal está na pasta `/codigo-arduino/`. <o diretório do seu github onde você disponibilizou o código
* Linguagem: C++ (Arduino)
* **Software PC:**     * Arduino IDE (versão 1.8.19 ou superior)     * Processing (para a interface gráfica, se houver)
* **Bibliotecas (Libraries):**     * `Servo.h` (padrão da IDE)     * `AccelStepper.h` (para o motor de passo)     * `NewPing.h` (para o sensor ultrassônico)
###  diagrama: "width="600px" /> *(Substitua `caminho/para/imagem_do_diagrama.png` pelo link ou caminho da imagem do esquema elétrico. Pode ser um print do Fritzing, Tinkercad ou até uma foto nítida do caderno).* 
### ⚙️ Instalação e Montagem Passo a passo de como alguém pode replicar o projeto de vocês. 
1.  **Montagem:** Siga o esquema elétrico acima para conectar todos os componentes.
2.  **Bibliotecas:** Abra a Arduino IDE, vá em "Sketch" > "Include Library" > "Manage Libraries" e instale a `AccelStepper` e `NewPing`. 3.
3.  **Upload do Código:**     * Conecte o Arduino ao computador.     * Abra o arquivo `projeto_semana_industrial/projeto_semana_industrial.ino`.     * Selecione a Placa (Arduino Uno) e a Porta COM correta.     * Clique em "Upload".
### ▶️ Como Usar Depois de montado e programado, como o projeto funciona?
1.  Ligue a fonte de alimentação externa.
2.  O braço robótico irá para a posição "Home" (inicial).
3.  Abra o "Serial Monitor" na Arduino IDE (Baud Rate 9600).
4.  Envie '1' para iniciar o ciclo automático ou '0' para parar.
### 🎥 Vídeo/GIF do Projeto em Ação *(É recomendado colocar um GIF ou link para um vídeo curto do projeto funcionando. Isso valoriza muito o README!)* 
![Texto alternativo do GIF](link/para/o/video_ou_gif.gif)
