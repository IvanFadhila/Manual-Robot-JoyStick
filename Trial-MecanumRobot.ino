#include <Servo.h>
//#include <PS2X_lib.h>
#include "driver.h"
#include "gerakan.h"
#include "joystick.h"

//PS2X joy;
Servo bawah;
Servo atas;

byte pinmotor[8]={2,3,4,5,6,7,8,11}; //pwm: 3',5',6',9,10,12
byte spd=100, arah, tb; //cpt=0, lgn=0;

unsigned char atas1=0, bawah1=133;


void setup() {
  Serial.begin(9600);
  for(byte a=0;a<8;a++){
    pinMode(pinmotor[a],OUTPUT);
    digitalWrite(pinmotor[a],LOW);  
  }
  joy.config_gamepad(A2,9,10,12,true,true); //A2,9,10,12 -- clock(pwm), command, attention(pwm), data
  atas.attach(A0);
  bawah.attach(A1);
  atas.write(atas1);
  bawah.write(bawah1);
}

void loop() {
  readbutton();
  }

/*
if(Serial.available()>0){
    char IncomingByte=Serial.read();
    //atoi (IncomingByte);
    if(IncomingByte=='Q'){
      capit(5);
      Serial.print("atas");
      Serial.print(posisi1);
      Serial.println();
    }if(IncomingByte=='W'){
      angkat(5);
      Serial.print("bawah");
      Serial.print(posisi2);
      Serial.println();
    }if(IncomingByte=='A'){
      capit(-5);
      Serial.print("atas");
      Serial.print(posisi1);
      Serial.println();
     }if(IncomingByte=='S'){
      angkat(-5);
      Serial.print("bawah");
      Serial.print(posisi2);
      Serial.println();
     }
}*/
