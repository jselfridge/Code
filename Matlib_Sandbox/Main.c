
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
void MatProp();
void MatDecomp();



// Main program 
int main() {
  printf("\nRunning Matlib demo \n");
  //MatIO();
  //MatManip();
  //MatArith();
  //MatProp();
  MatDecomp();
  printf("Program complete\n\n");
  return 0 ;
}




// Matrix Input and Output
void MatIO() {

  matrix* M = mat_init(5,2);
  mat_print(M);
  mat_write(M,"matM");
  matrix* N = mat_read("matM");
  mat_print(N);
  mat_clear(M); 
  mat_clear(N);

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
  mat_clear(M); 
  mat_clear(N); 
  mat_clear(P); 
  mat_clear(Q);

}




// Matrix Arithmetic
void MatArith() {

  //  Define A matrix
  matrix* A = mat_init(2,2);
  mat_set(A,1,1,3);  mat_set(A,1,2,5);
  mat_set(A,2,1,7);  mat_set(A,2,2,9);
  mat_print(A);
  
  //  Define B matrix
  matrix* B = mat_init(2,2);
  mat_set(B,1,1,8);  mat_set(B,1,2,2);
  mat_set(B,2,1,6);  mat_set(B,2,2,4);
  mat_print(B);
  
  //  Define C vector
  matrix* C = mat_init(3,1);
  mat_set(C,1,1,6);
  mat_set(C,2,1,2);
  mat_set(C,3,1,9);
  mat_print(C);
  
  //  Define D matrix
  matrix* D = mat_init(3,2);
  mat_set(D,1,1,6);  mat_set(D,1,2,7);
  mat_set(D,2,1,2);  mat_set(D,2,2,5);
  mat_set(D,3,1,9);  mat_set(D,3,2,4);
  mat_print(D);
  
  //  Define E vector
  matrix* E = mat_init(3,1);
  mat_set(E,1,1,7);
  mat_set(E,2,1,8);
  mat_set(E,3,1,4);
  mat_print(E);
  
  //  Define F vector
  matrix* F = mat_init(4,1);
  mat_set(F,1,1,4);
  mat_set(F,2,1,3);
  mat_set(F,3,1,7);
  mat_set(F,4,1,2);
  mat_print(F);
  
  //  Addition
  matrix* Madd = mat_add(A,B);
  mat_print(Madd);
  mat_clear(Madd);
  A = mat_add(A,B);
  mat_print(A);
  
  //  Subtraction
  matrix* Msub = mat_sub(A,B);
  mat_print(Msub);
  mat_clear(Msub);
  
  //  Multiplication
  matrix* Mmul = mat_mul(A,B);
  mat_print(Mmul);
  mat_clear(Mmul);
  
  //  Power
  matrix* Mpow;
  for ( int i=0; i<=2; i++ ) {
    Mpow= mat_pow(A,i);
    mat_print(Mpow);
  }
  mat_clear(Mpow);
  
  //  Transpose
  matrix* TA = mat_trans(A);
  mat_print(TA);
  mat_clear(TA);
  matrix* TB = mat_trans(B);
  mat_print(TB);
  mat_clear(TB);
  matrix* TC = mat_trans(C);
  mat_print(TC);
  mat_clear(TC);
  matrix* TD = mat_trans(D);
  mat_print(TD);
  mat_clear(TD);
  
  //  Skew Symmetric
  matrix* SC = mat_skew(C);
  mat_print(SC);
  mat_clear(SC);
  
  //  Cross product
  matrix* VC;
  VC = mat_cross(C,C);
  mat_print(VC);
  VC = mat_cross(C,E);
  mat_print(VC);
  mat_clear(VC);
  
  //  Dot product
  double dot;
  dot = mat_dot(C,E);
  printf("dot: %f \n", dot);
  dot = mat_dot(F,F);
  printf("dot: %f \n", dot);

  //  Clear matrices
  mat_clear(A);
  mat_clear(B);
  mat_clear(C);
  mat_clear(D);
  mat_clear(E);
  mat_clear(F);

}




// Matrix Properties
void MatProp() {

  //  Define A matrix
  matrix* A = mat_init(3,3);
  mat_set(A,1,1,3);  mat_set(A,1,2,5);  mat_set(A,1,3,8);
  mat_set(A,2,1,7);  mat_set(A,2,2,9);  mat_set(A,2,3,4);
  mat_set(A,3,1,1);  mat_set(A,3,2,6);  mat_set(A,3,3,2);
  mat_print(A);

  //  Define B matrix
  matrix* B = mat_init(2,3);
  mat_set(B,1,1,7);  mat_set(B,1,2,9);  mat_set(B,1,3,4);
  mat_set(B,2,1,1);  mat_set(B,2,2,6);  mat_set(B,2,3,2);
  mat_print(B);

  //  Define C matrix
  matrix* C = mat_init(3,2);
  mat_set(C,1,1,5);  mat_set(C,1,2,8);
  mat_set(C,2,1,9);  mat_set(C,2,2,4);
  mat_set(C,3,1,1);  mat_set(C,3,2,2);
  mat_print(C);

  // Trace
  double TA = mat_trace(A);  printf( "Trace of A: %f \n", TA );
  double TB = mat_trace(B);  printf( "Trace of B: %f \n", TB );
  double TC = mat_trace(C);  printf( "Trace of C: %f \n", TC );
  
  // Clear matrices
  mat_clear(A);
  mat_clear(B);
  mat_clear(C);

}




// Matrix Decomposition
void MatDecomp() {

  //  Define A matrix
  matrix* A = mat_init(3,3);
  mat_set(A,1,1,3);  mat_set(A,1,2,1);  mat_set(A,1,3,2);
  mat_set(A,2,1,5);  mat_set(A,2,2,8);  mat_set(A,2,3,6);
  mat_set(A,3,1,7);  mat_set(A,3,2,4);  mat_set(A,3,3,9);
  mat_print(A);

  //  Define B matrix
  matrix* B = mat_init(4,4);
  mat_set(B,1,1,3);  mat_set(B,1,2,1);  mat_set(B,1,3,2);  mat_set(B,1,4,7);
  mat_set(B,2,1,5);  mat_set(B,2,2,8);  mat_set(B,2,3,6);  mat_set(B,2,4,3);
  mat_set(B,3,1,7);  mat_set(B,3,2,4);  mat_set(B,3,3,9);  mat_set(B,3,4,9);
  mat_set(B,4,1,4);  mat_set(B,4,2,8);  mat_set(B,4,3,1);  mat_set(B,4,4,2);
  mat_print(B);
  
  // Decomp matrices
  matrix* La = NULL;
  matrix* Ua = NULL;
  matrix* Lb = NULL;
  matrix* Ub = NULL;

  // LU decomposition [3x3]
  mat_LU( A, &La, &Ua );
  mat_print(La); mat_print(Ua);
  A = mat_mul( La, Ua );
  mat_print(A);

  // LU decomposition [4x4]
  mat_LU( B, &Lb, &Ub );
  mat_print(Lb); mat_print(Ub);
  B = mat_mul( Lb, Ub );
  mat_print(B);

  // Determinant
  double detA = mat_det(A);
  printf( "detA: %f \n", detA );
  double detB = mat_det(B);
  printf( "detB: %f \n", detB );

  // Clear matrices
  mat_clear(A);
  mat_clear(B);
  mat_clear(La); 
  mat_clear(Ua);
  mat_clear(Lb); 
  mat_clear(Ub);

}



