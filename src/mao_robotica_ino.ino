#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

void setup() {
  servo1.attach(3);  // Defina os pinos de acordo com sua conexão
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);

  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  servo4.write(0);
  servo5.write(0);

  Serial.begin(9600);
}

void loop() {
  int sensorA0 = analogRead(A0);
  int sensorA1 = analogRead(A5);
  int sensorA2 = analogRead(A2);
  int sensorA3 = analogRead(A3);
  int sensorA4 = analogRead(A4);

  // Mapear valores dos sensores para ângulo de servo, com 1023 como 0º e 300 como 180º
  int angle1 = map(sensorA0, 1023, 300, 0, 180);
  int angle2 = map(sensorA1, 1023, 700, 0, 180);
  int angle3 = map(sensorA2, 1023, 500, 0, 180);
  int angle4 = map(sensorA3, 1023, 700, 0, 180);
  int angle5 = map(sensorA4, 1023, 500, 0, 180);

  // Limitar os ângulos para manter dentro da faixa 0-180 graus
  angle1 = constrain(angle1, 0, 180);
  angle2 = constrain(angle2, 0, 180);
  angle3 = constrain(angle3, 0, 180);
  angle4 = constrain(angle4, 0, 180);
  angle5 = constrain(angle5, 0, 180);

  // Mover os servos para os ângulos mapeados
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);
  servo4.write(angle4);
  servo5.write(angle5);

  // Imprimir o estado de todos os sensores e servos
  Serial.print("Sensor A0: ");
  Serial.print(sensorA0);
  Serial.print(" | Servo1: ");
  Serial.print(angle1);

  Serial.print(" || Sensor A1: ");
  Serial.print(sensorA1);
  Serial.print(" | Servo2: ");
  Serial.print(angle2);

  Serial.print(" || Sensor A2: ");
  Serial.print(sensorA2);
  Serial.print(" | Servo3: ");
  Serial.print(angle3);

  Serial.print(" || Sensor A3: ");
  Serial.print(sensorA3);
  Serial.print(" | Servo4: ");
  Serial.print(angle4);

  Serial.print(" || Sensor A4: ");
  Serial.print(sensorA4);
  Serial.print(" | Servo5: ");
  Serial.println(angle5);

  delay(50);  // Ajuste o delay para sua taxa de leitura ideal
}
