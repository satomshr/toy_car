
// test_motor_sensor_12.ico ; test program of DRV8835
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

// connection of HC-SR04
// Vcc = 5V (from Arduino)
// GND = GND
// TRIG = D2 (front)
// ECHO = D3 (front)

// PWM ; 3, 5, 6, 9, 10, 11
//       5, 6 ; 980MHz
//       3, 9, 10, 11 ; 490MHz

// include file
#include "drv8835.h"
#include "hcsr04.h"

// Arduino Pin assign
#define PIN_MT_R1 9
#define PIN_MT_R2 3
#define PIN_MT_L1 11
#define PIN_MT_L2 10
#define PIN_F_TRIG 5
#define PIN_F_ECHO 6

#define FWD_DELAY_MSEC 1000
#define TRN_DELAY_MSEC 700
#define HIGH_SPEED 153 // 255 / 5V * 3V
#define LOW_SPEED 76 // 255 / 5V * 1.5V
#define STOP_SPEED 0

#define TURN_DISTANCE 30 // cm
#define STOP_DISTANCE 20 // cm

#define MY_DEBUG 1

Drv8835 mt_r(PIN_MT_R1, PIN_MT_R2); // motor of right wheel
Drv8835 mt_l(PIN_MT_L1, PIN_MT_L2); // motor of left wheel
Hcsr04 us_f(PIN_F_TRIG, PIN_F_ECHO); // ultrasonic ssensor for front

float cm_f; // distance

#ifdef MY_DEBUG
int loop_count; // loop counting
#endif

void setup() {
  // put your setup code here, to run once:
  mt_r.stop();
  mt_l.stop();
  delay(FWD_DELAY_MSEC * 5);


#ifdef MY_DEBUG
  Serial.begin(9600);
  loop_count = 0;
#endif
}

void loop() {
  // put your main code here, to run repeatedly:

  cm_f = us_f.distance();

  if(cm_f < TURN_DISTANCE){
    // turn to the left (right; backward, left; forward)
    mt_r.ccw(HIGH_SPEED);
    mt_l.cw(HIGH_SPEED);
    delay(TRN_DELAY_MSEC);
  } else{
    // go forward
    mt_r.cw(HIGH_SPEED);
    mt_l.cw(HIGH_SPEED);
    delay(FWD_DELAY_MSEC);
  }

/*
#ifdef MY_DEBUG
  if(loop_count == 0){
    Serial.print("F = ");
    Serial.print(cm_f);
    Serial.println();
  }
  if(++loop_count == (int)(1000 / DELAY_MSEC)){
    loop_count = 0;
  }
#endif
  delay(DELAY_MSEC);
*/

  // right wheel, forward
/*
  mt_r.cw(HIGH_SPEED);
  mt_l.stop();
  delay(DELAY_MSEC * 5);
*/

  // left wheel, forward
/*
  mt_r.stop();
  mt_l.cw(HIGH_SPEED);
  delay(DELAY_MSEC * 5);
*/

  // right wheel, backward
/*
  mt_r.ccw(HIGH_SPEED);
  mt_l.stop();
  delay(DELAY_MSEC * 5);
*/

  // left wheel, backward
/*
  mt_r.stop();
  mt_l.ccw(HIGH_SPEED);
  delay(DELAY_MSEC * 5);
*/

  // stop once
/*
  mt_r.stop();
  mt_l.stop();
  delay(DELAY_MSEC * 2);
*/


  // both wheels, forward
/*
  mt_r.cw(HIGH_SPEED);
  mt_l.cw(HIGH_SPEED);
  delay(DELAY_MSEC * 3);
*/

  // stop once
/*
  mt_r.stop();
  mt_l.stop();
  delay(DELAY_MSEC * 2);
*/

  // turn to the right (right; forward, left; backward)
/*
  mt_r.cw(HIGH_SPEED);
  mt_l.ccw(HIGH_SPEED);
  delay(DELAY_MSEC * 3);
*/

  // stop once
/*
  mt_r.stop();
  mt_l.stop();
  delay(DELAY_MSEC * 2);
*/

  // turn to the left (right; backward, left; forward)
/*
  mt_r.ccw(HIGH_SPEED);
  mt_l.cw(HIGH_SPEED);
  delay(DELAY_MSEC * 3);
*/

  // stop once
/*
  mt_r.stop();
  mt_l.stop();
  delay(DELAY_MSEC * 2);
*/
}
