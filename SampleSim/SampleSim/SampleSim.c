
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  SampleSim.c
//  Justin M Selfridge
//  Main source code to run the sample simulation
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "SampleSim.h"

// Main program loop
int main() {

  printf("\n");
  printf("Starting Sample Simulation!\n");

  // Define time variables
  float duration = 0.10;
  float delta = 0.10;
  int steps = (int)(duration/delta);
  printf("Steps: %d, Delta: %f, Dur: %f \n", steps, delta, duration );

  // Set up the storage array
  //matrix* simdata = mat_init(1,steps+1);
  double x = 1.0;
  double t = 0.0;
  double e = 0.0;

  // Run the simulation
  printf("t = %f, x = %f, e = %f\n" , t, x, e);
  for ( int i=0; i<steps; i++ ) {
    ODE( f, &t, &x, delta, &e);
    printf("t = %f, x = %f, e = %f\n" , t, x, e);
  }



  printf("Program complete\n\n");

  return 0 ;
}




double f(double t, double x) {
  return pow((x-t-1),2)+2;
}




/*
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
*/
