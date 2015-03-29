
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
void MatDecomp();



// Main program 
int main() {
  printf("\nRunning Matlib demo \n");
  //MatIO();
  //MatManip();
  //MatArith();
  MatDecomp();
  printf("Program complete\n\n");
  return 0 ;
}




// Matrix Input and Output
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

  matrix* M = mat_eye(4);
  mat_print(M);
  matrix* N = mat_scale(M,3);
  mat_print(N);
  matrix* P = mat_copy(N);
  mat_print(P);
  mat_set( P, 1, 4, 14.0 );
  mat_set( P, 3, 2, 32.0 );
  mat_print(P);
  double val;
  val = mat_get( P, 1, 4 );
  printf( "Element value: %f\n", val );
  val = mat_get( P, 3, 2 );
  printf( "Element value: %f\n", val );
  matrix* Q = mat_ones(5,2);
  mat_print(Q);
  mat_clear(M); mat_clear(N); mat_clear(P); mat_clear(Q);

  // printf("MatManip error checking");
  // mat_eye(n);
  // mat_ones(n,m);

}




// Matrix Arithmetic
void MatArith() {

  /*//  Define A matrix
  matrix* A = mat_init(2,2);
  mat_set(A,1,1,3);  mat_set(A,1,2,5);
  mat_set(A,2,1,7);  mat_set(A,2,2,9);
  mat_print(A);
  */
  /*//  Define B matrix
  matrix* B = mat_init(2,2);
  mat_set(B,1,1,8);  mat_set(B,1,2,2);
  mat_set(B,2,1,6);  mat_set(B,2,2,4);
  mat_print(B);
  */  
  /*//  Define C vector
  matrix* C = mat_init(3,1);
  mat_set(C,1,1,6);
  mat_set(C,2,1,2);
  mat_set(C,3,1,9);
  mat_print(C);
  */
  /*//  Define D matrix
  matrix* D = mat_init(3,2);
  mat_set(D,1,1,6);  mat_set(D,1,2,7);
  mat_set(D,2,1,2);  mat_set(D,2,2,5);
  mat_set(D,3,1,9);  mat_set(D,3,2,4);
  mat_print(D);
  */
  /*//  Define E vector
  matrix* E = mat_init(3,1);
  mat_set(E,1,1,7);
  mat_set(E,2,1,8);
  mat_set(E,3,1,4);
  mat_print(E);
  */
  /*//  Define F vector
  matrix* F = mat_init(4,1);
  mat_set(F,1,1,4);
  mat_set(F,2,1,3);
  mat_set(F,3,1,7);
  mat_set(F,4,1,2);
  mat_print(F);
  */
  /*//  Addition
  matrix* Madd = mat_add(A,B);
  mat_print(Madd);
  mat_clear(Madd);
  A = mat_add(A,B);
  mat_print(A);
  //mat_add(A,C);
  */
  /*//  Subtraction
  matrix* Msub = mat_sub(A,B);
  mat_print(Msub);
  mat_clear(Msub);
  //mat_sub(A,C);
  */
  /*//  Multiplication
  matrix* Mmul = mat_mul(A,B);
  mat_print(Mmul);
  mat_clear(Mmul);
  //mat_mul(A,C);
  */
  /*//  Power
  matrix* Mpow;
  for ( int i=0; i<=2; i++ ) {
    Mpow= mat_pow(A,i);
    mat_print(Mpow);
  }
  mat_clear(Mpow);
  //mat_pow(A,-1);
  //mat_pow(C,2);
  */
  /*//  Transpose
  matrix* TA = mat_tran(A);
  mat_print(TA);
  mat_clear(TA);
  matrix* TB = mat_tran(B);
  mat_print(TB);
  mat_clear(TB);
  matrix* TC = mat_tran(C);
  mat_print(TC);
  mat_clear(TC);
  matrix* TD = mat_tran(D);
  mat_print(TD);
  mat_clear(TD);
  */
  /*//  Skew Symmetric
  matrix* SC = mat_skew(C);
  mat_print(SC);
  mat_clear(SC);
  //mat_skew(A);
  //mat_skew(D);
  */
  /*//  Cross product
  matrix* VC;
  VC = mat_cross(C,C);
  mat_print(VC);
  VC = mat_cross(C,E);
  mat_print(VC);
  mat_clear(VC);
  //mat_cross(A,C);
  //mat_cross(C,B);
  */
  /*//  Dot product
  double dot;
  dot = mat_dot(C,E);
  printf("dot: %f \n", dot);
  dot = mat_dot(F,F);
  printf("dot: %f \n", dot);
  //mat_dot(A,C);
  //mat_dot(C,F);
  */

  //  Clear matrices
  //mat_clear(A);
  //mat_clear(B);
  //mat_clear(C);
  //mat_clear(D);
  //mat_clear(E);
  //mat_clear(F);

}



// Matrix Decomposition
void MatDecomp() {

  //  Define A matrix
  matrix* A = mat_init(3,3);
  mat_set(A,1,1,3);  mat_set(A,1,2,1);  mat_set(A,1,3,2);
  mat_set(A,2,1,5);  mat_set(A,2,2,8);  mat_set(A,2,3,6);
  mat_set(A,3,1,7);  mat_set(A,3,2,4);  mat_set(A,3,3,9);
  mat_print(A);
  
  // Decomp matrices
  matrix* L = NULL;
  matrix* U = NULL;

  // LU decomposition
  mat_LU( A, &L, &U);
  mat_print(L) ;mat_print(U);
  A = mat_mul( L, U );
  mat_print(A);
  mat_clear(L); mat_clear(U);

  // Clear matrices
  mat_clear(A);

}



