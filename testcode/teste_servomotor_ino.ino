#include <Servo.h>

Servo meuServo;

void setup() {
  meuServo.attach(9);
}

void loop() {
  for (int pos = 0; pos <= 180; pos += 1) {
    meuServo.write(pos);              
    delay(5);  //ajustes para teste de velocidade de movimentaçao do servo                      
  }

  for (int pos = 180; pos >= 0; pos -= 1) {
    meuServo.write(pos);              
    delay(5);  //ajuste para teste de velocidade de movimentaçao do servo                 
  }
}
