#include <Servo.h>


Servo meuServo;

void setup() {
  meuServo.attach(9); // Pino D9 do seu Nano
}

void loop() {
  // Posição de 0 graus (Limite de inclinação/passo)
  meuServo.write(0);
  delay(1500);

  // Posição de 90 graus (CALIBRAÇÃO - Otto em pé)
  // É aqui que você deve encaixar as peças plásticas do Otto!
  meuServo.write(90);
  delay(1500);

  // Posição de 180 graus (Outro limite)
  meuServo.write(180);
  delay(1500);
}