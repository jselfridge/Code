
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  ODE.c
//  Justin M Selfridge
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "ODE.h"

void ODE( double f(double,double), double* t, double* x, double d, double* e ) {

  double K1, K2, K3, K4, K5, K6, X;

  K1 = d* f( *t        , *x );
  K2 = d* f( *t + C20*d, *x + C21*K1 );
  K3 = d* f( *t + C30*d, *x + C31*K1 + C32*K2 );
  K4 = d* f( *t + C40*d, *x + C41*K1 + C42*K2 + C43*K3 );
  K5 = d* f( *t        , *x + C51*K1 + C52*K2 + C53*K3 + C54*K4 );
  K6 = d* f( *t + C60*d, *x + C61*K1 + C62*K2 + C63*K3 + C64*K4 + C65*K5 );

   X  = *x + A1*K1 + A3*K3 + A4*K4 + A5*K5;
  *x +=      B1*K1 + B3*K3 + B4*K4 + B5*K5 + B6*K6;
  *t += d;
  *e  = fabs( *x - X );

}



