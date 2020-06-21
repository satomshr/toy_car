
// test_motor_sensor_11.ico ; test program of DRV8835
// author ; sato.mshr@gmail.com

// connection of DRV8835
// Vcc = 5V (from Arduino)
// MODE = GND (using IN/IN mode)
// AIN1 = D5 (arduino)
// AIN2 = D6 (arduino)
// BIN1 = GND
// BIN2 = GND
// VM = 3V (from battery)
// AOUT1 = Motor
// AOUT2 = Motor
// BOUT1 = open
// BOUT2 = open
// GND = GND

// connection of SG90 (Servo motor)
// PWM = D9 (Arduino) Orange
// Vcc = 5V (from Arduino) Red
// GND = GND (Brown)

// connection of HC-Hcsr04
// Vcc = 5V (from Arduino)
// GND = GND
// TRIG = D2 (front), D7 (right), D11 (left)
// ECHO = D3 (front), D8 (right), D12 (left)


// include file
#include <Servo.h>
// https://www.arduino.cc/en/Reference/Servo
// On boards other than the Mega, use of the library disables
// analogWrite() (PWM) functionality on pins 9 and 10,
// whether or not there is a Servo on those pins.

#include "drv8835.h"
#include "hcsr04.h"

// Arduino Pin assign
#define PIN_MT_1 5
#define PIN_MT_2 6

#define PIN_SERVO 9

#define PIN_F_TRIG 2
#define PIN_F_ECHO 3
#define PIN_R_TRIG 7
#define PIN_R_ECHO 8
#define PIN_L_TRIG 11
#define PIN_L_ECHO 12

#define DELAY_MSEC 100
#define HIGH_SPEED 153 // 255 / 5V * 3V
#define LOW_SPEED 51 // 255 / 5V * 1V
#define STOP_SPEED 0

#define STOP_DISTANCE_FRONT 40 // cm
#define STOP_DISTANCE_SIDE 25 // cm

#define SERVO_CENTER 90 // degree
#define SERVO_RIGHT 78 // degree (90-12)
#define SERVO_LEFT 102 // degree (90+12)

#define MY_DEBUG 1

Drv8835 mt_r(PIN_MT_1, PIN_MT_2); // motor of wheel
Servo myservo; // servo motor
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

  myservo.attach(PIN_SERVO);
  myservo.write(SERVO_CENTER);
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
    Serial.println("cm");
  }
  if(++loop_count == (int)(1000 / DELAY_MSEC)){
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
    #ifdef MY_DEBUG
      Serial.print("\tF OK!");
    #endif
    if(r_ok && l_ok){
      #ifdef MY_DEBUG
        Serial.print("\tStraight!");
      #endif
      mt_r.cw(HIGH_SPEED);
      mt_l.cw(HIGH_SPEED);
    } else if(r_ok && !l_ok){
      #ifdef MY_DEBUG
        Serial.print("\tRight!");
      #endif
      mt_r.cw(LOW_SPEED);
      mt_l.cw(HIGH_SPEED);
    } else if(!r_ok && l_ok){
      #ifdef MY_DEBUG
        Serial.print("\tLeft!");
      #endif
      mt_r.cw(HIGH_SPEED);
      mt_l.cw(LOW_SPEED);
    } else{ // !r_ok && !l_ok
      #ifdef MY_DEBUG
        Serial.print("\tstraight...");
      #endif
      mt_r.cw(HIGH_SPEED);
      mt_l.cw(HIGH_SPEED);
    }
    #ifdef MY_DEBUG
      Serial.println();
    #endif
    delay(DELAY_MSEC);
  } else{
    #ifdef MY_DEBUG
      Serial.print("\tF NG!");
    #endif

    // stop once
    #ifdef MY_DEBUG
      Serial.print("\tStop!");
    #endif
    mt_r.stop();
    mt_l.stop();
    delay(DELAY_MSEC * 2);

    // go backward
    #ifdef MY_DEBUG
      Serial.print("\tBack!");
    #endif
    mt_r.ccw(HIGH_SPEED);
    mt_l.ccw(HIGH_SPEED);
    delay(DELAY_MSEC * 5);

    // stop once
    #ifdef MY_DEBUG
      Serial.print("\tStop!");
    #endif
    mt_r.stop();
    mt_l.stop();
    delay(DELAY_MSEC * 2);

    // turn
    if(r_ok){
      #ifdef MY_DEBUG
        Serial.print("\tRight!");
      #endif
      mt_r.stop();
      mt_l.cw(HIGH_SPEED);
    } else{
      #ifdef MY_DEBUG
        Serial.print("\tLeft!");
      #endif
      mt_r.cw(HIGH_SPEED);
      mt_l.stop();
    }
    delay(DELAY_MSEC * 5);

    #ifdef MY_DEBUG
      Serial.println();
    #endif
  }
}
