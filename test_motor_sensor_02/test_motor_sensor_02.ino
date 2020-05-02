
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

// connection of HC-Hcsr04
// Vcc = 5V (from Arduino)
// TRIG = D2
// ECHO = D3
// GND = GND

// include file
#include "drv8835.h"
#include "hcsr04.h"

// Arduino Pin assign
#define PIN_MT_R1 5
#define PIN_MT_R2 6
#define PIN_MT_L1 10
#define PIN_MT_L2 11
#define PIN_TRIG 2
#define PIN_ECHO 3


#define DELAY_MSEC 100
#define HIGH_SPEED 153 // 255 / 5V * 3V
#define LOW_SPEED 76 // 255 / 5V * 1.5V
#define STOP_SPEED 0

#define STOP_DISTANCE 17 // cm
#define BACK_DISTANCE 7 // cm

Drv8835 mt_r(PIN_MT_R1, PIN_MT_R2); // motor of right wheel
Drv8835 mt_l(PIN_MT_L1, PIN_MT_L2); // motor of left wheel
Hcsr04 us_f(PIN_TRIG, PIN_ECHO); // ultrasonic ssensor for front
float cm; // distance

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
  } else{
    // Go backwards slowly (CCW, Low speed)
    mt_r.ccw(LOW_SPEED);
    mt_l.ccw(LOW_SPEED);
  }

  delay(DELAY_MSEC);
}
