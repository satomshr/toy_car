// drv8835.cpp
// author ; sato.mshr@gmail.com
#include "Arduino.h"
#include "drv8835.h"

Drv8835::Drv8835(int ina, int inb)
{
  _ina = ina;
  _inb = inb;
  _speed = 0;
  analogWrite(_ina, 0);
  analogWrite(_inb, 0);
  _status = DRV8835_STOP;
}

void Drv8835::cw(int speed)
{
  _speed = speed;
  analogWrite(_ina, _speed);
  analogWrite(_inb, 0);
  _status = DRV8835_CW;
}

void Drv8835::ccw(int speed)
{
  _speed = speed;
  analogWrite(_ina, 0);
  analogWrite(_inb, _speed);
  _status = DRV8835_CCW;
}

void Drv8835::stop(void)
{
  _speed = 0;
  analogWrite(_ina, 0);
  analogWrite(_inb, 0);
  _status = DRV8835_STOP;
}

void Drv8835::brake(int speed)
{
  _speed = speed;
  analogWrite(_ina, speed);
  analogWrite(_inb, speed);
  _status = DRV8835_BRAKE;
}

int Drv8835::status(void)
{
  return _status;
}

int Drv8835::speed(void)
{
  return _speed;
}
