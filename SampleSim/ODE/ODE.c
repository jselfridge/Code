
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  ODE.c
//  Justin M Selfridge
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "ODE.h"

void ODE( double f(double,double), double* t, double* x, double delta, double* err ) {


  double c20, c21;
  double c30, c31, c32;
  double c40, c41, c42, c43;
  double c50, c51, c52, c53, c54;
  double c60, c61, c62, c63, c64, c65;
  double  a1,  a2,  a3,  a4,  a5;
  double  b1,  b2,  b3,  b4,  b5,  b6;
  double  F1,  F2,  F3,  F4,  F5,  F6,  x4;

  c20 = 1.0 / 4.0;
  c21 = 1.0 / 4.0;

  c30 =       3.0 /    8.0;
  c31 =       3.0 /   32.0;
  c32 =       9.0 /   32.0;

  c40 =      12.0 /   13.0;
  c41 =    1932.0 / 2197.0;
  c42 =  - 7200.0 / 2197.0;
  c43 =    7296.0 / 2197.0;

  c50 =       0.0 /    1.0;
  c51 =     439.0 /  216.0;
  c52 =  -    8.0 /    1.0;
  c53 =    3680.0 /  513.0;
  c54 =  -  845.0 / 4104.0;

  c60 =       1.0 /    2.0;
  c61 =  -    8.0 /   27.0;
  c62 =       2.0 /    1.0;
  c63 =  - 3544.0 / 2565.0;
  c64 =    1859.0 / 4104.0;
  c65 =  -   11.0 /   40.0;
  

  // CHECK THESE!!!
  a1  = (double ) 25/(double ) 216;
  a2 = 0.0;
  a3  = (double ) 1408/(double ) 2565;
  a4  = (double ) 2197/(double ) 4104;
  a5 = -0.2;

  b1  = (double ) 16/(double ) 135;
  b2 = 0.0;
  b3  = (double ) 6656/(double ) 12825;
  b4  = (double ) 28561/(double ) 56430;
  b5 = -0.18;
  b6  = (double ) 2/(double ) 55;

  F1 = delta * f(*t, *x);
  F2 = delta * f(*t + c20 * delta, *x + c21 * F1);
  F3 = delta * f(*t + c30 * delta, *x + c31 * F1 + c32 * F2);
  F4 = delta * f(*t + c40 * delta, *x + c41 * F1 + c42 * F2 + c43 * F3);
  F5 = delta * f(*t + delta, *x + c51 * F1 + c52 * F2 + c53 * F3 + c54 * F4 );
  F6 = delta * f(*t + c60 * delta, *x + c61 * F1 + c62 * F2 + c63 * F3 + c64 * F4 + c65 * F5);

  x4 = *x + a1 * F1 + a3 * F3 + a4 * F4 + a5 * F5;
  *x += b1 * F1 + b3 * F3 + b4 * F4 + b5 * F5 + b6 * F6;
  *t += delta;
  *err = fabs(*x - x4);

}



