
// test_motor_sensor_01.ico ; test program of mortor (DRV8835) and
//                            ultrasonic sensor (HC-SR04)
// author ; sato.mshr@gmail.com

// connection of DRV8835
// Vcc = 5V
// MODE = GND (using IN/IN mode)
// AIN1 = D5 (arduino)
// AIN2 = D6 (arduino)
// BIN1 = GND
// BIN2 = GND
// VM = 3V
// AOUT1 = Motor
// AOUT2 = Motor
// BOUT1 = open
// BOUT2 = open
// GND = GND

// connection of HCSR04
// Vcc = 5V
// Trig = D2 (arduino)
// Echo = D3 (arduino)
// GND = GND

// Arduino Pin assign
#define PIN_LED 13
#define PIN_MT_A 6
#define PIN_MT_B 5

#define PIN_TRIG 2
#define PIN_ECHO 3

#define DELAY_MSEC 100
#define HIGH_SPEED 153 // 255 / 5V * 3V
#define LOW_SPEED 76 // 255 / 5V * 1.5V
#define STOP_SPEED 0

#define STOP_DISTANCE 15 // cm
#define BACK_DISTANCE 10 // cm

float cm;

void setup() {
  // put your setup code here, to run once:
  analogWrite(PIN_MT_A, STOP_SPEED);
  analogWrite(PIN_MT_B, STOP_SPEED);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  cm = pulseIn(PIN_ECHO, HIGH) / 58.0; //The echo time is converted into cm

  if(cm > STOP_DISTANCE){
    // CW, High speed
    analogWrite(PIN_MT_A, HIGH_SPEED);
    analogWrite(PIN_MT_B, STOP_SPEED);
  } else if(cm > BACK_DISTANCE){
    // Brake
    analogWrite(PIN_MT_A, HIGH_SPEED);
    analogWrite(PIN_MT_B, HIGH_SPEED);
/*
    delay(100);
    analogWrite(PIN_MT_A, STOP_SPEED);
    analogWrite(PIN_MT_B, STOP_SPEED);
*/
  } else{
    // CCW, High speed
    analogWrite(PIN_MT_A, STOP_SPEED);
    analogWrite(PIN_MT_B, HIGH_SPEED);
  }

  delay(DELAY_MSEC);
}
