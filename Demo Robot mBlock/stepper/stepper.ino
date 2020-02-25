#include <Stepper.h>
#define STEPS 2048
const int stepsPerRevolution = 32 * 64;
Stepper stepper(STEPS, 8, 9, 10, 11);
int velocidad;

void setup() {
  stepper.setSpeed(10);
  Serial.begin(9600);
}

void loop() {
  velocidad = map(analogRead(A0), 0, 1023, 1, 13);
  Serial.println(velocidad);
  if (velocidad > 0) {
    stepper.setSpeed(velocidad);
    stepper.step(2);
  }
}
