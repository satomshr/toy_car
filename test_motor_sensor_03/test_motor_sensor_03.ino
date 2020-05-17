
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
#define LOW_SPEED 76 // 255 / 5V * 1.5V
#define STOP_SPEED 0

#define STOP_DISTANCE 35 // cm
#define BACK_DISTANCE 20 // cm

Drv8835 mt_r(PIN_MT_R1, PIN_MT_R2); // motor of right wheel
Drv8835 mt_l(PIN_MT_L1, PIN_MT_L2); // motor of left wheel
Hcsr04 us_f(PIN_F_TRIG, PIN_F_ECHO); // ultrasonic ssensor for front
Hcsr04 us_r(PIN_R_TRIG, PIN_R_ECHO); // ultrasonic ssensor for right side
Hcsr04 us_l(PIN_L_TRIG, PIN_L_ECHO); // ultrasonic ssensor for left side
float cm_f, cm_r, cm_l; // distance

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:

  cm = us_f.distance();

  if(cm > STOP_DISTANCE){
    // Go forwards (CW, High speed)
    mt_r.cw(HIGH_SPEED);
    mt_l.cw(HIGH_SPEED);
  } else if(cm > BACK_DISTANCE){
    // Turn to the Right
    mt_r.stop();
    mt_l.cw(HIGH_SPEED);
    delay(DELAY_TURN_MSEC);
  } else{
    // Go backwards slowly (CCW, Low speed)
    mt_r.ccw(LOW_SPEED);
    mt_l.ccw(LOW_SPEED);
  }

  delay(DELAY_MSEC);
}
