// Programado por Ignacio Herreros y Arturo Martínez
// Dudas o sugerencias:
// hmmi@ieslaboral.edu.es
// mfa@ieslaboral.edu.es

#include <Servo.h>
// definición de pines
#define irR 2
#define irL 3
#define irB 4
#define pintrig 5
#define pinecho 6
#define buzz 7
#define mot1 8
#define mot2 9

// Variables
int marcha=1; // Estado del robot: 0->atrás,1->adelante,2->giro 
float distancia; // medida en cm del sensor ultrasónico
Servo motor1,motor2; //instanciación de los motores de la clase Servo
void setup() {
  // inicialización de pines como entrada o salida
  pinMode(irR, INPUT);
  pinMode(irL, INPUT);
  pinMode(irB, INPUT);
  pinMode(pintrig, OUTPUT);
  pinMode(pinecho, INPUT);
  // declaración de los pines a los que estan conectados los servos
  motor1.attach(mot1);
  motor2.attach(mot2);  
  // inicialización del monitor serie
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  
  // programación de cambios de estado
  
  if(digitalRead(irR)==0 || digitalRead(irL)==0){
    // Si detecto el borde por delante, marcha atras
    // durante un segundo y empiezo a girar
    marcha=0;
    delay(1000); //debería ajustarse hasta llegar al centro +o-
    marcha=2;
  }
  if(digitalRead(irB)==0 ){
    // Si detecto el borde por detras, marcha adelante
    // durante un segundo y empiezo a girar
    marcha=1;
    delay(1000); //debería ajustarse hasta llegar al centro +o-
    marcha=2;
  }
  if(distancia< 10){
    // Si detecto un objeto delante a menos de 10cm,
    // marcha adelante
    marcha=1;
  }

 // Declaración de acciones en cada estado
  if (marcha==1){
    //los dos motores hacia adelante a maxima velocidad
    //dependerá de las conexiones
    motor1.write(0); 
    motor2.write(255);
  }
  if (marcha==0){
    //los dos motores hacia atrás a maxima velocidad
    motor2.write(0);
    motor1.write(255);
  }
 if (marcha==2){
    //los dos motores girando a media velocidad
    motor2.write(64);
    motor1.write(192);
  }
  
  distancia= medirDistancia(pintrig,pinecho);
  Serial.println(distancia);
}

float medirDistancia(int trigger, int echo){
  float distcm;
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  
  unsigned long tiempo=pulseIn(echo,HIGH);  
  distcm= tiempo*0.000001*34000/2;
  return distcm;
  }
