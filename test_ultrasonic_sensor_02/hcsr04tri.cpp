// hcsr04.cpp
// author ; sato.mshr@gmail.com
#include "Arduino.h"
#include "hcsr04tri.h"

Hcsr04tri::Hcsr04tri(int p1_t, int p1_e, int p2_t, int p2_e, int p3_t, int p3_e)
{
  _p1_t = p1_t; _p1_e = p1_e;
  _p2_t = p2_t; _p2_e = p2_e;
  _p3_t = p3_t; _p3_e = p3_e;

  pinMode(_p1_t, OUTPUT); pinMode(_p1_e, INPUT);
  pinMode(_p2_t, OUTPUT); pinMode(_p2_e, INPUT);
  pinMode(_p3_t, OUTPUT); pinMode(_p3_e, INPUT);

  _distance1 = 0; _distance2 = 0; _distance3 = 0;
}

void Hcsr04tri::measure(void){
//  digitalWrite(_p1_t, LOW); digitalWrite(_p2_t, LOW); digitalWrite(_p3_t, LOW);
//  delayMicroseconds(2);
//  digitalWrite(_p1_t, HIGH); digitalWrite(_p2_t, HIGH); digitalWrite(_p3_t, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(_p1_t, LOW); digitalWrite(_p2_t, LOW); digitalWrite(_p3_t, LOW);
// _distance1 = pulseIn(_p1_e, HIGH) / 58.0;
// _distance2 = pulseIn(_p2_e, HIGH) / 58.0;
// _distance3 = pulseIn(_p3_e, HIGH) / 58.0;

  digitalWrite(_p1_t, LOW);
  delayMicroseconds(2);
  digitalWrite(_p1_t, HIGH);
  delayMicroseconds(10);
  digitalWrite(_p1_t, LOW);
  _distance1 = pulseIn(_p1_e, HIGH) / 58.0;

  digitalWrite(_p2_t, LOW);
  delayMicroseconds(2);
  digitalWrite(_p2_t, HIGH);
  delayMicroseconds(10);
  digitalWrite(_p2_t, LOW);
  _distance2 = pulseIn(_p2_e, HIGH) / 58.0;

  digitalWrite(_p3_t, LOW);
  delayMicroseconds(2);
  digitalWrite(_p3_t, HIGH);
  delayMicroseconds(10);
  digitalWrite(_p3_t, LOW);
  _distance3 = pulseIn(_p3_e, HIGH) / 58.0;
}

float Hcsr04tri::distance1(void)
{
  return _distance1;
}

float Hcsr04tri::distance2(void)
{
  return _distance2;
}

float Hcsr04tri::distance3(void)
{
  return _distance3;
}

float Hcsr04tri::distance(int ch){
  float f;

  switch(ch){
    case 1:
      f = _distance1;
      break;
    case 2:
      f = _distance2;
      break;
    case 3:
      f = _distance3;
      break;
    default:
      f = 0;
      break;
  }

  return f;
}
