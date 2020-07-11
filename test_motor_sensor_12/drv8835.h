// drv8835.h
// header for drv8835.cpp
// author ; sato.mshr@gmail.com

#ifndef DRV8835_H
#define DRV8835_H

#define DRV8835_CW 0
#define DRV8835_CCW 1
#define DRV8835_STOP 2
#define DRV8835_BRAKE 3

class Drv8835
{
public:
  Drv8835(int ina, int inb); // constructor
  void cw(int speed); // speed ; 0 - 255 (0V - 5V)
  void ccw(int speed); // speed ; 0 - 255 (0V - 5V)
  void stop(void);
  void brake(int speed); // speed ; 0 - 255 (0V - 5V)
  int status(void);
  int speed(void);
private:
  int _ina, _inb, _status, _speed;
};

#endif
