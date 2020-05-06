// hcsr04.h
// header for hcsr04.cpp
// author ; sato.mshr@gmail.com

#ifndef HCSR04TRI_H
#define HCSR04TRI_H

class Hcsr04tri
{
public:
  Hcsr04tri(int p1_t, int p1_e, int p2_t, int p2_e, int p3_t, int p3_e); // constructor
  void measure(void);
  float distance1(void);
  float distance2(void);
  float distance3(void);
  float distance(int ch);
private:
  int _p1_t, _p1_e, _p2_t, _p2_e, _p3_t, _p3_e;
  float _distance1, _distance2, _distance3;
};

#endif
