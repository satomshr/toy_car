
// test_drv8835_01.ico ; test program of DRV8835
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

// Arduino Pin assign
#define PIN_LED 13
#define PIN_MT_A 5
#define PIN_MT_B 6

#define DELAY_SEC 5
#define HIGH_SPEED 153 // 255 / 5V * 3V
#define LOW_SPEED 76 // 255 / 5V * 1.5V
#define STOP_SPEED 0

void mydelay(int s) // for delaying
{
  int i;

  for(i=0; i<s; i++){
    digitalWrite(PIN_LED, HIGH);
    delay(500);
    digitalWrite(PIN_LED, LOW);
    delay(500);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // CW, High speed
  analogWrite(PIN_MT_A, HIGH_SPEED);
  analogWrite(PIN_MT_B, STOP_SPEED);
  mydelay(DELAY_SEC);

  // CW, Low speed

  analogWrite(PIN_MT_A, LOW_SPEED);
  analogWrite(PIN_MT_B, STOP_SPEED);
  mydelay(DELAY_SEC);


  // CW, STOP (Coast)

  analogWrite(PIN_MT_A, STOP_SPEED);
  analogWrite(PIN_MT_B, STOP_SPEED);
  mydelay(DELAY_SEC);


  // CCW, High speed

  analogWrite(PIN_MT_A, STOP_SPEED);
  analogWrite(PIN_MT_B, HIGH_SPEED);
  mydelay(DELAY_SEC);


  // CCW, Low speed

  analogWrite(PIN_MT_A, STOP_SPEED);
  analogWrite(PIN_MT_B, LOW_SPEED);
  mydelay(DELAY_SEC);


  // CCW, STOP (Coast)

  analogWrite(PIN_MT_A, STOP_SPEED);
  analogWrite(PIN_MT_B, STOP_SPEED);
  mydelay(DELAY_SEC);


  // CW, High speed

  analogWrite(PIN_MT_A, HIGH_SPEED);
  analogWrite(PIN_MT_B, STOP_SPEED);
  mydelay(DELAY_SEC);


  // Brake

  analogWrite(PIN_MT_A, HIGH_SPEED);
  analogWrite(PIN_MT_B, HIGH_SPEED);
  mydelay(1);
  analogWrite(PIN_MT_A, STOP_SPEED);
  analogWrite(PIN_MT_B, STOP_SPEED);
  mydelay(DELAY_SEC - 1);

}
