#include "driver.h"
#define adur  2
#define aju   3
#define bdur  8
#define bju   11
#define cdur  7
#define cju   6
#define ddur  4
#define dju   5

void motor_depan(int lpwm, int rpwm){
  int invers1, invers2;
  if(lpwm>=0){
    digitalWrite(adur,LOW);
    analogWrite(aju,lpwm);  
  }  
  else {
    invers1= 255 + lpwm;
    digitalWrite(adur,HIGH);
    analogWrite(aju,invers1);
  }
  if(rpwm>=0){
    digitalWrite(bdur,LOW);
    analogWrite(bju,rpwm);  
  }  
  else {
    invers2= 255 + rpwm;
    digitalWrite(bdur,HIGH);
    analogWrite(bju,invers2);
  }
}

void motor_belakang(int lpwm, int rpwm){
  int invers1, invers2;
  if(lpwm>=0){
    digitalWrite(ddur,LOW);
    analogWrite(dju,lpwm);  
  }  
  else {
    invers1= 255 + lpwm;
    digitalWrite(ddur,HIGH);
    analogWrite(dju,invers1);
  }
  if(rpwm>=0){
    digitalWrite(cdur,LOW);
    analogWrite(cju,rpwm);  
  }  
  else {
    invers2= 255 + rpwm;
    digitalWrite(cdur,HIGH);
    analogWrite(cju,invers2);
  }
}

