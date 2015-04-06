
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  SampleSim.c
//  Justin M Selfridge
//  Main source code to run the sample simulation
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "../inc/SampleSim.h"

// Main program loop
int main() {

  printf("\n");
  printf("Starting Sample Simulation!\n");

  // Define time variables
  float duration = 0.1;
  float D = 0.001;
  int N = (int)(duration/D);

  // Set up the storage array
  matrix* simdata = mat_init(2,N+1);
  matrix* time    = mat_init(1,N+1);
  double  T = 0.0;
  double  E = 0.0;
  matrix* X = mat_init(2,1);
  mat_set( X,1,1, 1.0 );
  mat_set( X,2,1, 1.0 );

  // Run the simulation
  for ( int i=1; i<=N; i++ ) {
    for ( int j=1; j<=2; j++ ) {
      mat_set( simdata,j,i, mat_get(X,j,1) );
    }
    mat_set(time,1,i,T);
    ODE( derivative, &T, &X, D, &E );
    printf("t = %f, x1 = %f, x2 = %f \n", T, mat_get(X,1,1), mat_get(X,2,1) );
  }
  for ( int j=1; j<=2; j++ ) {
    mat_set( simdata,j,N+1, mat_get(X,j,1) );
  }
  mat_set(time,1,N+1,T);

  matrix* plotdata = mat_init(N+1,3);
  for ( int i=1; i<=N+1; i++ ) {
    mat_set( plotdata,i,1, mat_get(time,1,i) );
    for ( int j=1; j<=2; j++ ) {
      mat_set( plotdata,i,j+1, mat_get(simdata,j,i) );
    }
  }

  mat_write(simdata,"data/simdata");
  mat_write(time,"data/time");
  mat_write(plotdata,"data/plotdata");

  system("gnuplot PlotSim");



  printf("Program complete\n\n");

  return 0 ;
}




matrix* derivative ( double t, matrix* x ) {
  matrix* deriv = mat_init(x->rows,x->cols);
  double X1 = sin(PI2*t);    mat_set(deriv,1,1,X1);
  double X2 = -3*exp(-3*t);  mat_set(deriv,2,1,X2);
  return deriv;
}



