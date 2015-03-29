
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Main.c - Matlib Library Development
//  Justin M Selfridge
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Standard include files
#include <stdio.h>

// Custom include files
#include "Temp.h"

// Function prototypes
void MatIO();
void MatManip();
void MatArith();




// Main program 
int main() {
  printf("\nRunning Matlib demo \n");
  //MatIO();
  //MatManip();
  MatArith();
  printf("Program complete\n\n");
  return 0 ;
}




// Matrix input and Output
void MatIO() {

  printf("MatIO function testing  \n");
  matrix* M = mat_init(5,2);
  mat_print(M);
  mat_write(M,"matM");
  matrix* N = mat_read("matM");
  mat_print(N);
  mat_clear(M); mat_clear(N);
  
  // printf("MatIO error checking \n");
  //mat_init(0,4);
  //mat_read("matM");

}




// Matrix Manipulation
void MatManip() {

  printf("MatManip function testing  \n");
  matrix* M = mat_eye(4);
  mat_print(M);
  matrix* N = mat_scale(M,3);
  mat_print(N);
  matrix* P = mat_copy(N);
  mat_print(P);
  mat_set( P, 1, 4, 14.0 );
  mat_set( P, 3, 2, 32.0 );
  mat_print(P);
  double val = mat_get( P, 3, 2 );
  printf( "Element value: %f\n", val );
  matrix* Q = mat_ones(5,2);
  mat_print(Q);
  mat_clear(M); mat_clear(N); mat_clear(P); mat_clear(Q);

  // printf("MatManip error checking");
  // mat_eye(n);
  // mat_ones(n,m);

}




// Matrix arithmetic
void MatArith() {

  printf("MatManip function testing  \n");

  matrix* A = mat_init(2,2);
  mat_set(A,1,1,3);
  mat_set(A,1,2,5);
  mat_set(A,2,1,7);
  mat_set(A,2,2,9);
  mat_print(A);

  matrix* B = mat_init(2,2);
  mat_set(B,1,1,8);
  mat_set(B,1,2,2);
  mat_set(B,2,1,6);
  mat_set(B,2,2,4);
  mat_print(B);

  matrix* Madd = mat_add(A,B);
  mat_print(Madd);
  matrix* Msub = mat_sub(A,B);
  mat_print(Msub);
  matrix* Mmul = mat_mul(A,B);
  mat_print(Mmul);
  A = mat_add(A,B);
  mat_print(A);
  matrix* Mpow0 = mat_pow(A,0);
  mat_print(Mpow0);
  matrix* Mpow1 = mat_pow(A,1);
  mat_print(Mpow1);
  matrix* Mpow2 = mat_pow(A,2);
  mat_print(Mpow2);

  mat_clear(A);
  mat_clear(B);
  mat_clear(Madd);
  mat_clear(Msub);
  mat_clear(Mmul);
  mat_clear(Mpow0);
  mat_clear(Mpow1);
  mat_clear(Mpow2);

  //printf("MatManip error checking  \n");
  //mat_add();
  //mat_sub();
  //mat_mul();
  //mat_pow();

}
