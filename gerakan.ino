#include "gerakan.h"

void rem(unsigned char type){
  if(type==0){
    mundur();  
  }
  else if(type==1){
    maju();  
  }
}

void maju(){
  motor_depan(1.5*spd,1.42*spd);
  motor_belakang(1.45*spd,1.45*spd);  
}

void mundur(){
  motor_depan(-1.4*spd,-1.4*spd);
  motor_belakang(-1.45*spd,-1.4*spd);  
}

void kiri(){
  motor_depan(-1.9*spd,1.9*spd);
  motor_belakang(1.9*spd,-1.9*spd);
}

void kanan(){
  motor_depan(1.9*spd,-1.8*spd);
  motor_belakang(-1.9*spd,1.9*spd);
}

void putarkiri(){
  motor_depan(-1.45*spd,1.45*spd);
  motor_belakang(-1.20*spd,1.20*spd); 
}

void putarkanan(){
  motor_depan(1.45*spd,-1.45*spd);
  motor_belakang(1.20*spd,-1.20*spd);
}

void putarkanan1(){
  motor_depan(1.35*spd,-1.35*spd);
  motor_belakang(1.10*spd,-1.10*spd); 
}

void putarkiri1(){
  motor_depan(-1.35*spd,1.35*spd);
  motor_belakang(-1.10*spd,1.10*spd); }

void naik(){
  bawah.write(133);
}

void turun(){
  bawah.write(5);
}

void capit(){
  atas.write(30);
}

void lepas(){
  atas.write(5);
}

void berhenti(){
  motor_depan(0,0);
  motor_belakang(0,0);  
}

/*
void servo_1 (unsigned char nilai)
{
  atas.write(nilai);
}
void servo_2 (unsigned char nilai)
{
  bawah.write(nilai);
}*/
