
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  ODE.c
//  Justin M Selfridge
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "../inc/ODE.h"

void ODE( matrix* f( double, matrix* ), double* t, matrix** x, double d, double* e ) {

  mat_err( (*x)->cols!=1, "Error (ODE): State vector (X) must be a column vector." );

  int n = (*x)->rows;

  matrix* K1 = mat_init(n,1);
  matrix* K2 = mat_init(n,1);
  matrix* K3 = mat_init(n,1);
  matrix* K4 = mat_init(n,1);
  matrix* K5 = mat_init(n,1);
  matrix* K6 = mat_init(n,1);
  matrix* X0 = mat_init(n,1);
 
  K1 = mat_scale( f ( *t, *x ), d);

  K2 = mat_scale( f (
        *t + C20 * d, 
        mat_add(
         *x,
        mat_scale(K1,C21) )
       ), d);

  K3 = mat_scale( f (
        *t + C30 * d, 
        mat_add(
         mat_add(
          *x,
         mat_scale(K1,C31) ),
        mat_scale(K2,C32) )
       ), d);

  K4 = mat_scale( f (
        *t + C40 * d, 
        mat_add(
         mat_add(
          mat_add(
           *x,
          mat_scale(K1,C41) ),
         mat_scale(K2,C42) ),
        mat_scale(K3,C43) )
       ), d);

  K5 = mat_scale( f ( *t, 
        mat_add(
         mat_add(
          mat_add(
           mat_add(
            *x,
           mat_scale(K1,C51) ),
          mat_scale(K2,C52) ),
         mat_scale(K3,C53) ),
        mat_scale(K4,C54) )
       ), d);

  K6 = mat_scale( f (
        *t + C60 * d, 
        mat_add(
         mat_add(
          mat_add(
           mat_add(
            mat_add(
             *x,
            mat_scale(K1,C61) ),
           mat_scale(K2,C62) ),
          mat_scale(K3,C63) ),
         mat_scale(K4,C64) ),
        mat_scale(K5,C65) )
       ), d);

  *x = mat_add(
        mat_add(
         mat_add(
          mat_add(
           mat_add(
            *x,
           mat_scale(K1,B1) ),
          mat_scale(K3,B3) ),
         mat_scale(K4,B4) ),
        mat_scale(K5,B5) ),
       mat_scale(K6,B6) );

  *e = fabs( *x - X0 );
  *t += d;

  mat_clear(K1);
  mat_clear(K2);
  mat_clear(K3);
  mat_clear(K4);
  mat_clear(K5);
  mat_clear(K6);

}



