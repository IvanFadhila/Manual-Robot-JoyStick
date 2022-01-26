#include "joystick.h"
#include "gerakan.h"

#define tutup 25
#define buka  5
//#define angkat 130
//#define taruh  0

//=============================================
#define ex        joy.Button(PSB_BLUE)
#define kotak     joy.Button(PSB_PINK)
#define bunder    joy.Button(PSB_RED)
#define segitiga  joy.Button(PSB_GREEN)
#define ex1       joy.ButtonPressed(PSB_BLUE)
#define kotak1    joy.ButtonPressed(PSB_PINK)
#define bunder1   joy.ButtonPressed(PSB_RED)
#define segitiga1 joy.ButtonPressed(PSB_GREEN)
//=============================================
#define up        joy.Button(PSB_PAD_UP)
#define left      joy.Button(PSB_PAD_LEFT)
#define right     joy.Button(PSB_PAD_RIGHT)
#define down      joy.Button(PSB_PAD_DOWN)
#define rx        joy.Analog(PSS_RX)
#define ry        joy.Analog(PSS_RY)
#define lx        joy.Analog(PSS_LX)
#define ly        joy.Analog(PSS_LY)
#define L1        joy.Button(PSB_L1)
#define L2        joy.Button(PSB_L2)
#define R1        joy.Button(PSB_R1)
#define R2        joy.Button(PSB_R2)
#define strt      joy.Button(PSB_START)
#define slct      joy.Button(PSB_SELECT)

void readbutton() {
  joy.read_gamepad();
  if (ex) {
    if (L1) {
      motor_depan(spd, 1.75 * spd);
      motor_belakang(spd, 1.75 * spd);
    }
    else if (R1) {
      motor_depan(1.75 * spd, spd);
      motor_belakang(1.75 * spd, spd);
    }
    else maju();
    tb = 1; arah = 0;
  }
  else if (segitiga) {
    if (L1) {
      motor_depan(-spd, -1.75 * spd);
      motor_belakang(-spd, -1.75 * spd);
    }
    else if (R1) {
      motor_depan(-1.75 * spd, -spd);
      motor_belakang(1 - .75 * spd, -spd);
    }
    else mundur();
    tb = 1; arah = 1;
  }
  else if (left) {
    if (L1) {
      motor_depan(0, 0);
      motor_belakang(0, 1.75 * spd);
    }
    else if (R1) {
      motor_depan(0, 0);
      motor_belakang(1.75 * spd, 0);
    }
    else kiri();
  }
  else if (right) {
    if (L1) {
      motor_depan(0, 0);
      motor_belakang(0, 1.75 * spd);
    }
    else if (R1) {
      motor_depan(0, 0);
      motor_belakang(1.75 * spd, 0);
    }
    else kanan();
  }
  else if (L1) {
    putarkiri();
  }
  else if (R1) {
    putarkanan();
  }
  else if (R2) {
    putarkanan1();
  }
  else if (L2) {
    putarkiri1();
  }
  else if (up) {
    naik();
  }
  else if (down) {
    turun();
  }
  else if (bunder) {
    capit();
    delay(300);
    naik();
  }
  else if (kotak) {
    lepas();
  }
  else {
    if (tb == 1) {
      rem(arah);
      tb = 0;
      delay(30);
    }
    berhenti();
  }
  delay(10);
}
