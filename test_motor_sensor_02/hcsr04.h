// hcsr04.h
// header for hcsr04.cpp
// author ; sato.mshr@gmail.com

#ifndef HCSR04_H
#define HCSR04_H

class Hcsr04
{
public:
  Hcsr04(int p_trig, int p_echo); // constructor
  int distance(void);
private:
  int _p_trig, _p_echo, _distance;
};

#endif
