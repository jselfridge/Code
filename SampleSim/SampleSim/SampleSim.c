
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
  float duration = 0.1;
  float D = 0.001;
  int N = (int)(duration/D);
  //printf("Steps: %d, Delta: %f, Dur: %f \n", steps, delta, duration );

  // Set up the storage array
  matrix* simdata = mat_init(2,N+1);
  matrix* time    = mat_init(1,N+1);
  double  T = 0.0;
  double  E = 0.0;
  matrix* X = mat_init(2,1);
  mat_set( X,1,1, 1.0 );
  mat_set( X,2,1, 1.0 );

  // Run the simulation
  //printf("t = %f, x = %f, e = %f\n" , t, x, e);
  for ( int i=1; i<=N; i++ ) {
    for ( int j=1; j<=2; j++ ) {
      mat_set(simdata,j,i,mat_get(X,j,1));
    }
    mat_set(time,1,i,T);
    ODE( derivative, &T, &X, D, &E );
    printf("t = %f, x1 = %f, x2 = %f \n", T, mat_get(X,1,1), mat_get(X,2,1) );
  }
  for ( int j=1; j<=2; j++ ) {
    mat_set(simdata,j,N+1,mat_get(X,j,1));
  }
  mat_set(time,1,N+1,T);
  mat_write(simdata,"simdata");
  mat_write(time,"time");

  // Setup the plotting function
  system("gnuplot ../PlotSim");



  printf("Program complete\n\n");

  return 0 ;
}




matrix* derivative ( double t, matrix* x ) {
  matrix* deriv = mat_init(x->rows,x->cols);
  double X1 = -2*exp(-2*t);  mat_set(deriv,1,1,X1);
  double X2 = -3*exp(-3*t);  mat_set(deriv,2,1,X2);
  return deriv;
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
