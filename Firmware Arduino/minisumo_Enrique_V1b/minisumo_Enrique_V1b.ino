#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <Servo.h>

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
Servo servo_9;
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
Servo servo_10;



void setup(){
    Serial.begin(115200);
    servo_9.attach(9); // init pin
    servo_10.attach(10); // init pin
    pinMode(12,OUTPUT);
    pinMode(4,INPUT);
    servo_9.write(95); // write to servo
    
}

void loop(){
    
    Serial.println(getDistance(5,6));
    if((getDistance(12,13)) < ( 10 )){
        servo_9.write(0); // write to servo
        servo_10.write(180); // write to servo
        Serial.println("para");
    }else{
        servo_9.write(95); // write to servo
        servo_10.write(95); // write to servo
        Serial.println("marcha");
        tone(12,262,250); // write to buzzer
        delay(250);
    }
    if(((digitalRead(4))==(0  ))){
        Serial.println("blanco");
    }else{
        Serial.println("negro");
    }
    
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    
}
