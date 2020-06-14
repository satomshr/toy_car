// test_servo01.ino ; test of servo motor
// author ; sato.mshr@gmail.com

#include <Servo.h>
// https://www.arduino.cc/en/Reference/Servo
// On boards other than the Mega, use of the library disables
// analogWrite() (PWM) functionality on pins 9 and 10,
// whether or not there is a Servo on those pins.

#define SERVO_PIN 9
#define D_CENTER 90
#define D_RANGE 15
#define MY_DELAY 100

Servo myservo;
int pos;
int str, stp;

void setup()
{
  str = D_CENTER - D_RANGE;
  stp = D_CENTER + D_RANGE;

  myservo.attach(SERVO_PIN);

}

void loop()
{
  for (pos = str; pos <= stp; pos++) { // goes from 30 degrees to 150 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(MY_DELAY);                       // waits 15ms for the servo to reach the position
  }
  for (pos = stp; pos >= str; pos--) { // goes from 150 degrees to 30 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(MY_DELAY);                       // waits 15ms for the servo to reach the position
  }
}
