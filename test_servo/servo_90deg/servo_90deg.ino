// servo_90deg.ino ; set servo motor at 90deg
// author ; sato.mshr@gmail.com
// Thanks to SMRAZA demo program

#include <Servo.h>
// https://www.arduino.cc/en/Reference/Servo
// On boards other than the Mega, use of the library disables
// analogWrite() (PWM) functionality on pins 9 and 10,
// whether or not there is a Servo on those pins.

#define SERVO_PIN 9
#define DEG 90
Servo myservo;
int pos;

void setup()
{
  myservo.attach(SERVO_PIN);

  for (pos = 30; pos <= 150; pos += 1) { // goes from 30 degrees to 150 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 150; pos >= 30; pos -= 1) { // goes from 150 degrees to 30 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  myservo.write(DEG);
}

void loop()
{
}
