
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Main.c - Matlib Library Development
//  Justin M Selfridge
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Standard include files
#include <stdio.h>

// Custom include files
#include "Temp.h"

// Function prototypes
void InitMat();
void ClearMat();
void MatIO();
void MatManip();
void MatArith();
void MatProp();
void MatDecomp();

// Global variables
matrix* V3a;
matrix* V3b;
matrix* V4;
matrix* M22;
matrix* M23;
matrix* M32;
matrix* M33a;
matrix* M33b;
matrix* M34;
matrix* M43;
matrix* M44;




// Main program 
int main() {

  printf("\nRunning Matlib demo \n");
  InitMat();
  //MatIO();
  //MatManip();
  //MatArith();
  //MatProp();
  MatDecomp();
  ClearMat();
  printf("Program complete\n\n");

  return 0 ;
}




// InitMat (initialize the matrices for demo)
void InitMat() {
  printf("\nInitializing the matrices for demo program \n");

  //  Define first 3x1 vector
  V3a = mat_init(3,1);
  mat_set(V3a,1,1,6);
  mat_set(V3a,2,1,2);
  mat_set(V3a,3,1,9);
  printf("V3a: ");  mat_print(V3a);

  //  Define second 3x1 vector
  V3b = mat_init(3,1);
  mat_set(V3b,1,1,4);
  mat_set(V3b,2,1,8);
  mat_set(V3b,3,1,3);
  printf("V3b: ");  mat_print(V3b);
  
  //  Define 4x1 vector
  V4 = mat_init(4,1);
  mat_set(V4,1,1,5);
  mat_set(V4,2,1,2);
  mat_set(V4,3,1,7);
  mat_set(V4,4,1,1);
  printf("V4: ");  mat_print(V4);
  
  //  Define 2x2 matrix
  M22 = mat_init(2,2);
  mat_set(M22,1,1,3);  mat_set(M22,1,2,5);
  mat_set(M22,2,1,7);  mat_set(M22,2,2,9);
  printf("M22: ");  mat_print(M22);

  //  Define 2x3 matrix
  M23 = mat_init(2,3);
  mat_set(M23,1,1,7);  mat_set(M23,1,2,9);  mat_set(M23,1,3,4);
  mat_set(M23,2,1,1);  mat_set(M23,2,2,6);  mat_set(M23,2,3,2);
  printf("M23: ");  mat_print(M23);

  //  Define 3x2 matrix
  M32 = mat_init(3,2);
  mat_set(M32,1,1,6);  mat_set(M32,1,2,7);
  mat_set(M32,2,1,2);  mat_set(M32,2,2,5);
  mat_set(M32,3,1,9);  mat_set(M32,3,2,4);
  printf("M32: ");  mat_print(M32);
  
  // Define first 3x3 matrix
  M33a = mat_init(3,3);
  mat_set(M33a,1,1,3);  mat_set(M33a,1,2,5);  mat_set(M33a,1,3,8);
  mat_set(M33a,2,1,7);  mat_set(M33a,2,2,9);  mat_set(M33a,2,3,4);
  mat_set(M33a,3,1,1);  mat_set(M33a,3,2,6);  mat_set(M33a,3,3,2);
  printf("M33a: ");  mat_print(M33a);

  // Define second 3x3 matrix
  M33b = mat_init(3,3);
  mat_set(M33b,1,1,3);  mat_set(M33b,1,2,1);  mat_set(M33b,1,3,2);
  mat_set(M33b,2,1,5);  mat_set(M33b,2,2,8);  mat_set(M33b,2,3,6);
  mat_set(M33b,3,1,7);  mat_set(M33b,3,2,4);  mat_set(M33b,3,3,9);
  printf("M33b: ");  mat_print(M33b);

  // Define 3x4 matrix
  M34 = mat_init(3,4);
  mat_set(M34,1,1,3);  mat_set(M34,1,2,7);  mat_set(M34,1,3,6);  mat_set(M34,1,4,7);
  mat_set(M34,2,1,5);  mat_set(M34,2,2,4);  mat_set(M34,2,3,2);  mat_set(M34,2,4,3);
  mat_set(M34,3,1,1);  mat_set(M34,3,2,8);  mat_set(M34,3,3,5);  mat_set(M34,3,4,9);
  printf("M34: ");  mat_print(M34);

  // Define 4x3 matrix
  M43 = mat_init(4,3);
  mat_set(M43,1,1,8);  mat_set(M43,1,2,1);  mat_set(M43,1,3,5);
  mat_set(M43,2,1,2);  mat_set(M43,2,2,3);  mat_set(M43,2,3,6);
  mat_set(M43,3,1,4);  mat_set(M43,3,2,7);  mat_set(M43,3,3,8);
  mat_set(M43,4,1,8);  mat_set(M43,4,2,9);  mat_set(M43,4,3,1);
  printf("M43: ");  mat_print(M43);

  // Define 4x4 matrix
  M44 = mat_init(4,4);
  mat_set(M44,1,1,3);  mat_set(M44,1,2,1);  mat_set(M44,1,3,2);  mat_set(M44,1,4,7);
  mat_set(M44,2,1,5);  mat_set(M44,2,2,8);  mat_set(M44,2,3,6);  mat_set(M44,2,4,3);
  mat_set(M44,3,1,7);  mat_set(M44,3,2,4);  mat_set(M44,3,3,9);  mat_set(M44,3,4,9);
  mat_set(M44,4,1,4);  mat_set(M44,4,2,8);  mat_set(M44,4,3,1);  mat_set(M44,4,4,2);
  printf("M44: ");  mat_print(M44);

  printf("\n\n");
}




// ClearMat (clear the matrices used in demo)
void ClearMat() {

  mat_clear(V3a);
  mat_clear(V3b);
  mat_clear(V4);
  mat_clear(M22);
  mat_clear(M23);
  mat_clear(M32);
  mat_clear(M33a);
  mat_clear(M33b);
  mat_clear(M34);
  mat_clear(M43);
  mat_clear(M44);

}




// Matrix Input and Output
void MatIO() {
  printf("Testing input and output capabilities \n");

  matrix* M = mat_init(5,2);
  mat_print(M);
  mat_write(M,"matM");
  matrix* N = mat_read("matM");
  mat_print(N);
  mat_clear(M); 
  mat_clear(N);

  printf("\n\n");
}




// Matrix Manipulation
void MatManip() {
  printf("Matrix manipulation \n");

  // Identity matrix
  matrix* M = mat_eye(4);
  mat_print(M);

  // Scale matrix
  matrix* N = mat_scale(M,3);
  mat_print(N);

  // Copy matrix
  matrix* P = mat_copy(N);
  mat_print(P);

  // Set element value
  mat_set( P, 1, 4, 14.0 );
  mat_set( P, 3, 2, 32.0 );
  mat_print(P);

  // Fet element value
  double val;
  val = mat_get( P, 1, 4 );
  printf( "Element value: %f\n", val );
  val = mat_get( P, 3, 2 );
  printf( "Element value: %f\n", val );

  // Ones matrix
  matrix* Q = mat_ones(5,2);
  mat_print(Q);

  // Clear completed matrices 
  mat_clear(M); 
  mat_clear(N); 
  mat_clear(P); 
  mat_clear(Q);

  printf("\n\n");
}




// Matrix Arithmetic
void MatArith() {
  
  //  Addition
  matrix* Madd = mat_add(M33a,M33b);
  mat_print(Madd);
  mat_clear(Madd);

  //  Subtraction
  matrix* Msub = mat_sub(M33a,M33b);
  mat_print(Msub);
  mat_clear(Msub);
  
  //  Multiplication
  matrix* Mmul = mat_mul(M33a,M33b);
  mat_print(Mmul);
  mat_clear(Mmul);
  
  //  Power
  matrix* Mpow;
  for ( int i=0; i<=2; i++ ) {
    Mpow= mat_pow(M33a,i);
    mat_print(Mpow);
  }
  mat_clear(Mpow);
  
  //  Transpose
  matrix* T1 = mat_trans(V4);
  mat_print(T1);
  mat_clear(T1);
  matrix* T2 = mat_trans(M23);
  mat_print(T2);
  mat_clear(T2);
  matrix* T3 = mat_trans(M43);
  mat_print(T3);
  mat_clear(T3);
  matrix* T4 = mat_trans(M33a);
  mat_print(T4);
  mat_clear(T4);

  //  Skew Symmetric
  matrix* skew = mat_skew(V3a);
  mat_print(skew);
  mat_clear(skew);
  
  //  Cross product
  matrix* cross;
  cross = mat_cross(V3a,V3b);
  mat_print(cross);
  cross = mat_cross(V3a,V3a);
  mat_print(cross);
  mat_clear(cross);
  
  //  Dot product
  double dot;
  dot = mat_dot(V3a,V3b);
  printf("dot: %f \n", dot);
  dot = mat_dot(V3a,V3a);
  printf("dot: %f \n", dot);

  printf("\n\n");
}




// Matrix Properties
void MatProp() {
  printf("Matrix properties \n");

  // Trace
  double T33 = mat_trace(M33a);  printf( "Trace of M33a: %f \n", T33 );
  double T34 = mat_trace(M34);   printf( "Trace of M34:  %f \n", T34 );
  double T43 = mat_trace(M43);   printf( "Trace of M43:  %f \n", T43 );

  printf("\n\n");
}




// Matrix Decomposition
void MatDecomp() {
  printf("Matrix decomposition \n");

  // Decomp matrices
  matrix* L3 = NULL;
  matrix* U3 = NULL;
  matrix* L4 = NULL;
  matrix* U4 = NULL;

  // LU decomposition [3x3]
  mat_LU( M33a, &L3, &U3 );
  mat_print(L3); mat_print(U3);
  matrix* LU3 = mat_mul( L3, U3 );
  mat_print(LU3);  mat_clear(LU3);

  // LU decomposition [4x4]
  mat_LU( M44, &L4, &U4 );
  mat_print(L4); mat_print(U4);
  matrix* LU4 = mat_mul( L4, U4 );
  mat_print(LU4);  mat_clear(LU4);

  // Determinant
  double det3 = mat_det(M33a);
  printf( "det3: %f \n", det3 );
  double det4 = mat_det(M44);
  printf( "det4: %f \n", det4 );

  // Left division
  matrix* x31 = mat_divL( M33a, V3a );
  mat_print(x31);
  mat_clear(x31);
  matrix* x32 = mat_divL( M33a, M32 );
  mat_print(x32);
  mat_clear(x32);
  matrix* x41 = mat_divL( M44, V4 );
  mat_print(x41);
  mat_clear(x41);

  // Clear matrices
  mat_clear(L3); 
  mat_clear(U3);
  mat_clear(L4); 
  mat_clear(U4);

  printf("\n\n");
}



