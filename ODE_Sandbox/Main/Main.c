
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  ODE Demonstration Project
//  Justin M Selfridge
//  Main.c
//  Main source code to run the ODE demo
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "Main.h"

// Main program loop
int main() {

  printf("\nHello ODE Demo! \n");

  printf("Initializing the ODE solver! \n");
  ODE_Demo();

  printf("Program complete\n\n");

  return 0 ;

}

float f(float t, float x) {
  return (2 + (x - t - 1) * (x - t - 1));
}

void ODE_Demo() {

  const float a = 1.0, b = 1.5625;
  float x = 2.0, t, h, e;
  const int n = 72;
  int i;

  h = (b - a) / (float) n;
  t = a;

  for (i = 1; i <= n;  i++) {
    ODE(f, &t, &x, h, &e);
    printf("t = %f, x = %f, e = %f\n" , t, x, e);
  }

}



