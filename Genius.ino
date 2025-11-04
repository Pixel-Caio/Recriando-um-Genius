#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// --- LCD I2C ---
LiquidCrystal_I2C lcd(0x27, 16, 2);

// --- Notas musicais ---
#define NOTE_C3  131
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_B3  247
#define NOTE_C4  262

// --- Pinos ---
int speakerpin = 12;
int ledpin[] = {8, 9, 10, 11};  // Vermelho, verde, amarelo, azul
int button[] = {2, 3, 4, 5};    // Botões correspondentes

// --- Variáveis do jogo ---
int turn = 0;
int randomArray[100];
int inputArray[100];
int ultimoBotao = -1; // armazena o último botão apertado

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Jogo Genius");
  lcd.setCursor(0, 1);
  lcd.print("Fase: 1");

  // Define pinos dos LEDs
  for (int x = 0; x < 4; x++) {
    pinMode(ledpin[x], OUTPUT);
    digitalWrite(ledpin[x], LOW);
  }

  // Define pinos dos botões com pullup interno
  for (int x = 0; x < 4; x++) {
    pinMode(button[x], INPUT_PULLUP);
  }

  randomSeed(analogRead(A0));
}

void loop() {
  randomArray[turn] = random(1, 5);

  lcd.setCursor(0, 1);
  lcd.print("Fase: ");
  lcd.print(turn + 1);
  lcd.print("   ");

  for (int x = 0; x <= turn; x++) {
    tocarLed(randomArray[x]);
    delay(200);
  }

  if (!input()) {
    fail(ultimoBotao);
  } else {
    turn++;
    delay(700);
  }
}

// --- Função para tocar nota e acender LED ---
void tocarLed(int valor) {
  int nota = 0;
  switch (valor) {
    case 1: nota = NOTE_G3; break;
    case 2: nota = NOTE_A3; break;
    case 3: nota = NOTE_B3; break;
    case 4: nota = NOTE_C4; break;
  }

  digitalWrite(ledpin[valor - 1], HIGH);
  tone(speakerpin, nota, 300);
  delay(300);
  digitalWrite(ledpin[valor - 1], LOW);
  noTone(speakerpin);
}

// --- Entrada do jogador (com debounce e espera por release) ---
bool input() {
  for (int x = 0; x <= turn; x++) {
    bool correto = false;
    while (!correto) {
      for (int y = 0; y < 4; y++) {
        if (digitalRead(button[y]) == LOW) { // LOW = pressionado
          delay(30); // debounce inicial
          // confirma que ainda está pressionado após debounce
          if (digitalRead(button[y]) == LOW) {
            // feedback visual e sonoro
            tocarLed(y + 1);

            // registra entrada
            inputArray[x] = y + 1;
            ultimoBotao = y;

            // espera o botão ser liberado antes de continuar (evita leituras duplicadas)
            while (digitalRead(button[y]) == LOW) {
              delay(10); // espera curta para não travar a CPU
            }

            // checa se errou
            if (inputArray[x] != randomArray[x]) {
              return false; // errou
            }

            correto = true;
            delay(50); // pequeno intervalo antes de aceitar próxima entrada
          }
        }
      }
    }
  }
  return true; // acertou toda a sequência
}

// --- Função de falha ---
void fail(int botaoErro) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Errou!");
  lcd.setCursor(0, 1);
  lcd.print("Reiniciando...");

  // Se botaoErro inválido (por segurança), pisca todos como fallback
  if (botaoErro < 0 || botaoErro > 3) {
    for (int i = 0; i < 3; i++) {
      for (int y = 0; y < 4; y++) digitalWrite(ledpin[y], HIGH);
      tone(speakerpin, NOTE_C3, 200);
      delay(200);
      for (int y = 0; y < 4; y++) digitalWrite(ledpin[y], LOW);
      noTone(speakerpin);
      delay(200);
    }
  } else {
    for (int i = 0; i < 3; i++) {
      digitalWrite(ledpin[botaoErro], HIGH);
      tone(speakerpin, NOTE_C3, 200);
      delay(200);
      digitalWrite(ledpin[botaoErro], LOW);
      noTone(speakerpin);
      delay(200);
    }
  }

  // Mensagem e reinício
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Errou!");
  lcd.setCursor(0, 1);
  lcd.print("Aperte o Verde");

  while (digitalRead(button[0]) == HIGH) {
    // espera o botão vermelho ser pressionado
    delay(10);
  }

  // aguarda liberação do botão vermelho antes de reiniciar
  while (digitalRead(button[0]) == LOW) {
    delay(10);
  }

  turn = 0;
  lcd.clear();
  lcd.print("Jogo Genius");
  lcd.setCursor(0, 1);
  lcd.print("Fase: 1");
}