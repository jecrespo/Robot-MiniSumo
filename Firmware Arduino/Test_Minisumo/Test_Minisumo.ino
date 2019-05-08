#include <Servo.h>
Servo servo_9;
Servo servo_10;

void setup() {
  Serial.begin(115200);
  servo_9.attach(9); // init pin
  servo_10.attach(10); // init pin
  pinMode(12, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  Serial.println("Inicio");
}

void loop() {
  Adelante();
  delay(2000);
  Para();
  delay(500);
  Atras();
  delay(2000);
  Para();
  delay(1000);
  Gira_Derecha();
  Para();
  delay(1000);
  Gira_Izquierda();
  Para();
  delay(1000);
  Pita();

}

void Adelante()
{
  Serial.println("Adelante");
  servo_9.write(0); // write to servo
  servo_10.write(180); // write to servo
}

void Atras()
{
  Serial.println("Atras");
  servo_9.write(180); // write to servo
  servo_10.write(0); // write to servo
}

void Para()
{
  servo_9.write(90); // write to servo
  servo_10.write(90); // write to servo
}

void Gira_Derecha()
{
  servo_9.write(180); // write to servo
  servo_10.write(180); // write to servo
  delay(500);
}

void Gira_Izquierda()
{
  servo_9.write(0); // write to servo
  servo_10.write(0); // write to servo
  delay(500);
}

void Pita()
{
  tone(12, 262, 500); // write to buzzer
  delay(500);
}
