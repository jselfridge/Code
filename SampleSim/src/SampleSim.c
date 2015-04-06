
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
  float duration = 10.0;
  float D = 0.001;
  int N = (int)(duration/D);

  // Set up the storage array
  matrix* sim  = mat_init(2,N+1);
  matrix* time = mat_init(1,N+1);
  double  T = 0.0;
  double  E = 0.0;
  matrix* X = mat_init(2,1);
  mat_set( X,1,1, 2.0 );
  mat_set( X,2,1, 0.0 );

  // Run the simulation
  for ( int i=1; i<=N; i++ ) {
    for ( int j=1; j<=2; j++ ) {
      mat_set( sim,j,i, mat_get(X,j,1) );
    }
    mat_set(time,1,i,T);
    ODE( derivative, &T, &X, D, &E );
    printf("t = %f, x1 = %f, x2 = %f \n", T, mat_get(X,1,1), mat_get(X,2,1) );
  }
  for ( int j=1; j<=2; j++ ) {
    mat_set( sim,j,N+1, mat_get(X,j,1) );
  }
  mat_set(time,1,N+1,T);

  // Form plotting matrix
  matrix* plot = mat_init(N+1,3);
  plot = mat_appc( mat_trans(time), mat_trans(sim) );

  // Store the sim data to file
  mat_write(sim,"data/sim");
  mat_write(time,"data/time");
  mat_write(plot,"data/plot");

  // Plot the simulation
  system("gnuplot PlotSim");

  // Complete the simulation
  printf("Program complete\n\n");
  return 0 ;
}




matrix* derivative ( double t, matrix* x ) {
  matrix* deriv = mat_init(x->rows,x->cols);
  double X1 = -2*exp(-2*t);    mat_set(deriv,1,1,X1);
  double X2 = (PI2)*cos(PI2*0.2*t);  mat_set(deriv,2,1,X2);
  return deriv;
}



