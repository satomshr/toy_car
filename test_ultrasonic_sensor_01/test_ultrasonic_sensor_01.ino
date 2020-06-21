// test_ultrasonic_sensor_01.ino ; test program for ultrasonic sensors
// author ; sato.mshr@gmail.com

// include files
#include "hcsr04.h"

// Arduino pin assign
#define US_A_T 2
#define US_A_E 3
#define US_B_T 7
#define US_B_E 8
#define US_C_T 11
#define US_C_E 12

Hcsr04 us_a(US_A_T, US_A_E);
Hcsr04 us_b(US_B_T, US_B_E);
Hcsr04 us_c(US_C_T, US_C_E);

float cm_a, cm_b, cm_c;

void setup(){
  Serial.begin(9600);
}

void loop(){
  cm_a = us_a.distance();
  cm_b = us_b.distance();
  cm_c = us_c.distance();

  cm_a = (int(cm_a * 100.0)) / 100.0;
  cm_b = (int(cm_b * 100.0)) / 100.0;
  cm_c = (int(cm_c * 100.0)) / 100.0;

  Serial.print("Distance\t=\t");
  Serial.print(cm_a);
  Serial.print("cm,\t");
  Serial.print(cm_b);
  Serial.print("cm,\t");
  Serial.print(cm_c);
  Serial.print("cm");

  Serial.println();
  delay(1000);
}
