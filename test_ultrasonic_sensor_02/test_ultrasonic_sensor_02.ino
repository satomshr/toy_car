// test_ultrasonic_sensor_02.ino ; test of 3 ultrasonic senors in 1 object
// author ; sato.mshr@gmail.com

#include "hcsr04tri.h"

// Arduino pin assign
#define US_A_T 2
#define US_A_E 3
#define US_B_T 4
#define US_B_E 5
#define US_C_T 6
#define US_C_E 7

Hcsr04tri us3(US_A_T, US_A_E, US_B_T, US_B_E, US_C_T, US_C_E);

void setup(){
  Serial.begin(9600);
}

void loop(){
  float cm_a, cm_b, cm_c;

  us3.measure();
  cm_a = (int(us3.distance1() * 100.0)) / 100.0;
  cm_b = (int(us3.distance2() * 100.0)) / 100.0;
  cm_c = (int(us3.distance3() * 100.0)) / 100.0;

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
