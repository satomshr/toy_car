
// test_drv8835_02.ico ; test program of DRV8835
// author ; sato.mshr@gmail.com

// connection of DRV8835
// Vcc = 5V (from Arduino)
// MODE = GND (using IN/IN mode)
// AIN1 = D5 (arduino)
// AIN2 = D6 (arduino)
// BIN1 = D10
// BIN2 = D11
// VM = 3V (from battery)
// AOUT1 = Motor
// AOUT2 = Motor
// BOUT1 = Motor
// BOUT2 = Motor
// GND = GND

// include file
#include "drv8835.h"

// Arduino Pin assign
#define PIN_LED 13
#define PIN_MT_R1 5
#define PIN_MT_R2 6
#define PIN_MT_L1 10
#define PIN_MT_L2 11

#define DELAY_SEC 3
#define HIGH_SPEED 153 // 255 / 5V * 3V
#define LOW_SPEED 76 // 255 / 5V * 1.5V
#define STOP_SPEED 0

void mydelay(int s) // for delaying
{
  int i;

  for(i=0; i<s; i++){
    digitalWrite(PIN_LED, HIGH);
    delay(500);
    digitalWrite(PIN_LED, LOW);
    delay(500);
  }
}

Drv8835 mt_r(PIN_MT_R1, PIN_MT_R2);
Drv8835 mt_l(PIN_MT_L1, PIN_MT_L2);

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // CW, High speed
//  mt_r.cw(HIGH_SPEED);
//  mt_l.cw(HIGH_SPEED);
//  mydelay(DELAY_SEC);

  // CW, STOP (Coast)
//  mt_r.stop();
//  mt_l.stop();
//  mydelay(DELAY_SEC);

  // CCW, High speed
//  mt_r.ccw(HIGH_SPEED);
//  mt_l.ccw(HIGH_SPEED);
//  mydelay(DELAY_SEC);

  // Brake
//  mt_r.brake(HIGH_SPEED);
//  mt_l.brake(HIGH_SPEED);
//  mydelay(1);
//  mt_r.stop();
//  mt_l.stop();
//  mydelay(DELAY_SEC - 1);

  // CW (Right), CCW (Left)
//  mt_r.cw(HIGH_SPEED);
//  mt_l.ccw(HIGH_SPEED);
//  mydelay(DELAY_SEC);

  // Stop (Coast)
//  mt_r.stop();
//  mt_l.stop();
//  mydelay(DELAY_SEC);

  // CCW (Right), CW (Left)
//  mt_r.ccw(HIGH_SPEED);
//  mt_l.cw(HIGH_SPEED);
//  mydelay(DELAY_SEC);

// CW, High speed
//  mt_r.cw(HIGH_SPEED);
//  mt_l.cw(HIGH_SPEED);
//  mydelay(DELAY_SEC);

  // Turn to the Right
  mt_r.stop();
  mt_l.cw(HIGH_SPEED);
  mydelay(DELAY_SEC);

  // Brake
  mt_r.brake(HIGH_SPEED);
  mt_l.brake(HIGH_SPEED);
  mydelay(1);
  mt_r.stop();
  mt_l.stop();
  mydelay(DELAY_SEC - 1);

  // Turn to the Left
  mt_r.cw(HIGH_SPEED);
  mt_l.stop();
  mydelay(DELAY_SEC);

  // Brake
  mt_r.brake(HIGH_SPEED);
  mt_l.brake(HIGH_SPEED);
  mydelay(1);
  mt_r.stop();
  mt_l.stop();
  mydelay(DELAY_SEC - 1);
}
