
// test_motor_sensor_03.ico ; test program of DRV8835
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

// connection of HC-Hcsr04
// Vcc = 5V (from Arduino)
// GND = GND
// TRIG = D2 (front), D7 (right), D9 (left)
// ECHO = D3 (front), D8 (right), D12 (left)


// include file
#include "drv8835.h"
#include "hcsr04.h"

// Arduino Pin assign
#define PIN_MT_R1 5
#define PIN_MT_R2 6
#define PIN_MT_L1 10
#define PIN_MT_L2 11
#define PIN_F_TRIG 2
#define PIN_F_ECHO 3
#define PIN_R_TRIG 7
#define PIN_R_ECHO 8
#define PIN_L_TRIG 9
#define PIN_L_ECHO 12

#define DELAY_MSEC 100
#define DELAY_TURN_MSEC 650 // When turning, delays DELAY_TURN_MSEC + DELAY_MSEC
#define HIGH_SPEED 153 // 255 / 5V * 3V
#define LOW_SPEED 51 // 255 / 5V * 1V
#define STOP_SPEED 0

#define STOP_DISTANCE_FRONT 35 // cm
#define STOP_DISTANCE_SIDE 35 // cm
#define BACK_DISTANCE 20 // cm

#define MY_DEBUG 2

Drv8835 mt_r(PIN_MT_R1, PIN_MT_R2); // motor of right wheel
Drv8835 mt_l(PIN_MT_L1, PIN_MT_L2); // motor of left wheel
Hcsr04 us_f(PIN_F_TRIG, PIN_F_ECHO); // ultrasonic ssensor for front
Hcsr04 us_r(PIN_R_TRIG, PIN_R_ECHO); // ultrasonic ssensor for right side
Hcsr04 us_l(PIN_L_TRIG, PIN_L_ECHO); // ultrasonic ssensor for left side

float cm_f, cm_r, cm_l; // distance
boolean f_ok, r_ok, l_ok; // far from obstacles? or not

#ifdef MY_DEBUG
int loop_count; // loop counting
#endif

void setup() {
  // put your setup code here, to run once:
#ifdef MY_DEBUG
  Serial.begin(9600);
  loop_count = 0;
#endif
}

void loop() {
  // put your main code here, to run repeatedly:

  cm_f = us_f.distance();
  cm_r = us_r.distance();
  cm_l = us_l.distance();

#ifdef MY_DEBUG
  if(loop_count == 0){
    Serial.print("F = ");
    Serial.print(cm_f);
    Serial.print("cm,\tR = ");
    Serial.print(cm_r);
    Serial.print("cm,\tL = ");
    Serial.print(cm_l);
    Serial.print("cm");
    Serial.println();
  }
  if(++loop_count == 10){
    loop_count = 0;
  }
#endif

  f_ok = (cm_f > STOP_DISTANCE_FRONT);
  r_ok = (cm_r > STOP_DISTANCE_SIDE);
  l_ok = (cm_l > STOP_DISTANCE_SIDE);

/*
  algorithm
    F ok, R ok, L ok -> go ahead
    F ok, R ok, L ng -> turn right
    F ok, R ng, L ok -> turn left
    F ok, R ng, L ng -> go ahead
    F ng, R ok, L ok -> stop once, go backward and turn right (or left)
    F ng, R ok, L ng -> stop once, go backward and turn right
    F ng, R ng, L ok -> stop once, go backward and turn left
    F ng, R ng, L ng -> stop once, go backward and backward, and turn right (or left)
*/

  if(f_ok){
    if(r_ok && l_ok){
      mt_r.cw(HIGH_SPEED);
      mt_l.cw(HIGH_SPEED);
    } else if(r_ok && !l_ok){
      mt_r.cw(LOW_SPEED);
      mt_l.cw(HIGH_SPEED);
    } else if(!r_ok && l_ok){
      mt_r.cw(HIGH_SPEED);
      mt_l.cw(LOW_SPEED);
    } else{ // !r_ok && !l_ok
      mt_r.cw(HIGH_SPEED);
      mt_l.cw(HIGH_SPEED);
    }
    delay(DELAY_MSEC);
  } else{
    // stop once
    mt_r.stop();
    mt_l.stop();
    delay(DELAY_MSEC * 2);

    // go backward
    mt_r.ccw(HIGH_SPEED);
    mt_l.ccw(HIGH_SPEED);
    delay(DELAY_MSEC * 5);

    // stop once
    mt_r.stop();
    mt_l.stop();
    delay(DELAY_MSEC * 2);

    // turn
    if(r_ok){
      mt_r.cw(LOW_SPEED);
      mt_l.cw(HIGH_SPEED);
    } else{
      mt_r.cw(HIGH_SPEED);
      mt_l.cw(LOW_SPEED);
    }
    delay(DELAY_MSEC * 5);
  }
}
