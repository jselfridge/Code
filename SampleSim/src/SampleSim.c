
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

  // Initialize time
  double t = T0;
  time = mat_init(1,STEPS+1);

  // Initialize states
  matrix* x = mat_init(N,1);
  mat_set( x,1,1, 0.0 );
  mat_set( x,2,1,-1.0 );
  mat_set( x,3,1, 1.0 );
  mat_set( x,4,1, 1.0 );
  mat_set( x,5,1, 0.0 );
  mat_set( x,6,1, 0.0 );
  state = mat_init(N,STEPS+1);

  // Initialize simulation error
  matrix* e = mat_init(N,1);
  for ( int i=1; i<=N; i++ )  {  mat_set( e,i,1, 0.0 );  }
  simerr = mat_init(N,STEPS+1);


  /*
  // Initialize controls
  matrix* u = mat_init(M,1);
  mat_set( u,1,1, 0.0 );
  mat_set( u,2,1, 0.0 );
  mat_set( u,3,1, 0.0 );
  ctrl = mat_init(M,STEPS+1);
  */
  /*
  // Initialize reference signals
  reference = mat_init(M,STEPS+1);
  matrix* r = mat_init(M,1);
  mat_set( r,1,1, 0.0 );
  mat_set( r,2,1, 0.0 );
  mat_set( r,3,1, 0.0 );
  */
  /*
  // Initialize disturbance signals
  dist = mat_init(M,STEPS+1);
  matrix* d = mat_init(M,1);
  mat_set( d,1,1, 0.0 );
  mat_set( d,2,1, 0.0 );
  mat_set( d,3,1, 0.0 );
  */

  // Assign initial conditions
  mat_set(time,1,1,t);
  for ( int i=1; i<=N; i++ )  {  mat_set( state, i,1, mat_get(x,i,1) );  }
  //for ( int i=1; i<=M; i++ )  {  mat_set( ctrl,  i,1, mat_get(u,i,1) );  }
  //for ( int i=1; i<=M; i++ )  {  mat_set( ref,   i,1, mat_get(u,i,1) );  }
  //for ( int i=1; i<=M; i++ )  {  mat_set( dist,  i,1, mat_get(u,i,1) );  }

  // Run the simulation
  for ( step=2; step<=STEPS+1; step++ ) {
    ODE( Deriv, &t, &x, DT, &e );
    for ( int i=1; i<=N; i++ ) {  mat_set( simerr, i,step, mat_get(e,i,1) );  }
    printf("t = %f \n", t );
  }

  // Form plotting matrix
  plot = mat_appc( mat_trans(time), mat_trans(state) );

  // Store the sim data to file
  mat_write( time,   "data/time"   );
  mat_write( state,  "data/state"  );
  mat_write( simerr, "data/simerr" );
  mat_write( plot,   "data/plot"   );

  // Plot the simulation
  system("gnuplot PlotSim");

  // Complete the simulation
  printf("Program complete\n\n");
  return 0 ;
}




matrix* Deriv ( double t, matrix* x ) {

  // Initialize derivative matrix
  matrix* dx = mat_init(N,1);

  // Collect states
  double px = mat_get(x,1,1);
  double py = mat_get(x,2,1);
  double pz = mat_get(x,3,1);
  double vx = mat_get(x,4,1);
  double vy = mat_get(x,5,1);
  double vz = mat_get(x,6,1);

  /*
  // Determine reference signals
  matrix* r = Ref(t);
  double rx = mat_get(r,1,1);
  double ry = mat_get(r,2,1);
  double rz = mat_get(r,3,1);
  */
  /*
  // Determine disturbance signals
  matrix* d = Dist(t);
  double dx = mat_get(r,1,1);
  double dy = mat_get(r,2,1);
  double dz = mat_get(r,3,1);
  */
  /*
  // Determine control inputs
  matrix* u = Ctrl(t);
  double ux = mat_get(u,1,1);
  double uy = mat_get(u,2,1);
  double uz = mat_get(u,3,1);
  */

  // Calculate derivatives
  double dpx = vx;
  double dpy = vy;
  double dpz = vz;
  double dvx = (1/MASS)*(-KX*px -CX*vx +0);
  double dvy = (1/MASS)*(-KY*py -CY*vy +0);
  double dvz = (1/MASS)*(-KZ*pz -CZ*vz +0);

  // Assign to storage matrices
  mat_set(time,1,step,t);
  for ( int i=1; i<=N; i++ ) {  mat_set( state,  i,step, mat_get(x,i,1) );  }
  
  // Assign values to derivative 
  mat_set( dx,1,1, dpx );
  mat_set( dx,2,1, dpy );
  mat_set( dx,3,1, dpz );
  mat_set( dx,4,1, dvx );
  mat_set( dx,5,1, dvy );
  mat_set( dx,6,1, dvz );

  return dx;
}



/*
matrix* Ctrl ( double t ) {
  matrix* u = mat_init(3,1);
  mat_set(u,1,1,0.0);
  mat_set(u,2,1,0.0);
  mat_set(u,3,1,0.0);
  return u;
}
*/


/*
matrix* Ref ( double t ) {
  matrix* r = mat_init(3,1);
  mat_set(r,1,1,0.0);
  mat_set(r,2,1,0.0);
  mat_set(r,3,1,0.0);
  return r;
}
*/
/*
matrix* Dist ( double t ) {
  matrix* d = mat_init(3,1);
  mat_set(d,1,1,0.0);
  mat_set(d,2,1,0.0);
  mat_set(d,3,1,0.0);
  return d;
}
*/


