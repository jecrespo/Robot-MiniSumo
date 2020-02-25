#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <Servo.h>

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
void Atras();
Servo servo_9;
Servo servo_10;
void Adelante();
void Para();
void Gira();
void Busca();
float getDistance(int trig,int echo){
    pinMode(trig,OUTPUT);
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    pinMode(echo, INPUT);
    return pulseIn(echo,HIGH,30000)/58.0;
}

void Atras()
{
    servo_9.write(0); // write to servo
    servo_10.write(180); // write to servo
}

void Adelante()
{
    servo_9.write(180); // write to servo
    servo_10.write(0); // write to servo
}

void Para()
{
    servo_9.write(90); // write to servo
    servo_10.write(90); // write to servo
}

void Gira()
{
    servo_9.write(135); // write to servo
    servo_10.write(135); // write to servo
    _delay(1);
}

void Busca()
{
    while(!((getDistance(5,6)) < (  15)))
    {
        _loop();
        Gira();
    }
    Adelante();
}

void setup(){
    servo_9.attach(9); // init pin
    servo_10.attach(10); // init pin
    pinMode(3,INPUT);
    pinMode(2,INPUT);
}

void loop(){
    if((digitalRead(3)) && (digitalRead(2))){
        Adelante();
    }else{
        Atras();
        _delay(1);
        Gira();
    }
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
}
