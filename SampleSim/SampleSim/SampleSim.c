
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  SampleSim Program
//  Justin M Selfridge
//  SampleSim.c
//  Main source code to run the sample simulation code
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "SampleSim.h"

// Main program loop
int main() {

  printf("\nHello Sample Simulation Demo!\n");
  
  printf("Demonstrating the RKF solver!\n");
  DemoRFK();

  printf("\nProgram complete\n\n");

  return 0 ;
}

float f(float t, float x) {
  return (2 + (x - t - 1) * (x - t - 1));
}

void DemoRFK() {
  const float a = 1.0, b = 1.5625;
  float x = 2.0, t, h, e;
  const int n = 72;
  int i;

  h = (b - a) / (float) n;
  t = a;
  for (i = 1; i <= n;  i++) {
    RKF(f, &t, &x, h, &e);
    printf("t = %f, x = %f, e = %f\n" , t, x, e);
  }

}
