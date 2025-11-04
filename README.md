# 🤖 [Genius] 
  Genius é um jogo de memorização, principalmente ativando a memória de curto prazo, onde o jogador é apresentado uma sequência que há de repetir, a cada partida a fazendo mais longa. 
### 👥 Equipe (Colaboradores)
> * [Caio](https://github.com/Pixel-Caio)
> * [Daniel](https://github.com/Danmax1331)
> * [Paulo](https://github.com/PaulinBacana)
### 📖 Descrição do Projeto.
* Qual problema ele resolve?
   * O projeto auxilia a memorização, a coordenação motora, e engaja o usuário a testar seus limites frequentemente.
* Qual era o desafio da Semana Industrial?
   * Era criar um jogo eletrônico, o maior ou menor que seja, e apresentá-lo.
* Como ele funciona (visão geral)?
   * A programação gera uma sequência de números, variando de 0 a 4, cada número condizendo com um led, essa sequência é apresentada e o usuário deve repetí-la.
* Quais tecnologias (hardware e software) foram centrais?
   * Arduino IDE, Display 16x2, Botões e LEDs e o uso de USB-C ao contrário da entrada especial do Arduino. 
### 🔧 Hardware (Componentes Utilizados) Lista de todos os componentes físicos necessários para montar o projeto. 
* **Controlador:** 1x Arduino Uno R3.
* **Sensores:** 4x Botões; 2x Sensores de Fim de Curso.
* **Atuadores:** 4x LEDs; 1x Display LCD I2C 16x2.
* **Outros:** 1x Protoboard; Jumpers (Macho-Macho, Macho-Fêmea); Fonte de alimentação externa 5V/2A; Piezo; Resistores de 220 Ohms.
### 💻 Software e Dependências O que é necessário para rodar o código? 
* **Firmware/Código:** O código principal está na pasta `codigo-arduino/`.
* **Linguagem:** C++ (Arduino)
* **Software PC:** Arduino IDE (versão 1.8.19 ou superior)
* **Bibliotecas (Libraries):** `Wire.h` (Habilita a comunicação do módulo I2C por meio do A4 e A5) e `LiquidCrystal_I2C.h` (Para o Display LCD I2C).    
<img src="imagens/imagem do diagrama.png" width="600px" alt="Imagem do projeto montado no Tinkercad" />
<img src="imagens/esquema eletrico.png" width="600px" alt="Esquema elétrico do projeto" />

### ⚙️ Instalação e Montagem Passo a Passo
1.  **Montagem:** Siga o esquema elétrico acima para conectar todos os componentes.
2.  **Bibliotecas:** Abra a Arduino IDE, vá em "Sketch" > "Include Library" > "Manage Libraries" e instale a `Wire.h` e `LiquidCrystal_I2C.h`.
3.  **Upload do Código:** Conecte o Arduino ao computador, abra o arquivo `/codigo-arduino/Genius.ino`, selecione a Placa (Arduino Uno) e a Porta COM correta, clique em "Upload".

### ▶️ Como Usar Depois de montado e programado, como o projeto funciona?
1.  Ligue a fonte de alimentação externa.
2.  O visor irá acender, mostrar a fase atual e então o jogo irá começar assim que um dos LEDs piscar um única vez.
### 🎥 Vídeo/GIF do Projeto em Ação 
https://github.com/user-attachments/assets/4dbf020a-20d2-46ab-b813-76ad44d3775e

