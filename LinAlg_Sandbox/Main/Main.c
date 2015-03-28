
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Linear Algebra Demonstration Project
//  Justin M Selfridge
//  Main.c
//  Main source code to run the linear algebra demonstration.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "Main.h"

// Main program loop
int main() {

  printf("\nHello Linear Algebra Demo! \n");
  
  double VecA[4] = { 1.0, 2.0, 3.0, 4.0 };
  printf("\n%f\n%f\n%f\n%f\n", VecA[0], VecA[1], VecA[2], VecA[3]);

  double matA[2][2] = { { 1.0, 2.0 }, { 3.0, 4.0 } };
  matA = {/0};
  double matA[2][2] = { { 5.0, 6.0 }, { 7.0, 8.0 } };

  //matrix* A = mat_read("matA");
  //matrix* B = mat_read("matB");

  //matrix* C = mat_mul(A,B);
  //mat_print(C);
  //mat_clear(C);

  //matrix* M = mat_create(3,4);  
  //mat_print(M);

  //matrix* M = mat_eye(2);
  //mat_print(M);

  //matrix* M = mat_copy(M);
  //mat_print(M);

  //matrix* M = mat_scale( M, 5 );
  //mat_print(M);

  //mat_write( M, "testfile" );

  //matrix* M = mat_read("testfile");
  //mat_print(M);

  //double a = mat_trace(M);
  //printf( "Trace: %f\n", a );

  //matrix* Vt = mat_trans(V);
  //matrix* Mt = mat_trans(M);
  //mat_print(Vt);  mat_clear(Vt);
  //mat_print(Mt);  mat_clear(Mt);

  //matrix* Mc = mat_meanc(M);
  //mat_print(Mc);





  // eye(3)
  // zero(2,4)
  // zero(3)

  //printf("Define scalars, vectors and matrices: \n");
  // S1 = 2;  S2 = 3;
  // Vec V11 = [2;3]; V12 = [3,2];
  // Vec V21 = [3;5;7]; V22 = [7,5,3];
  // Mat M2 = [ 2,3; 5,7 ];
  // Mat M3 = [ 3,5,8; 6,3,4; 1,9,3 ];

  //printf("Scalar multiplication and division \n");
  // V21 * S1
  // V22 / S2
  // Mat2 * S1
  // Mat3 / S1

  //printf("Transpose \n");
  // V11'
  // V22'
  // Mat2'
  // Mat3'

  //printf("Addition and subtraction \n");
  // V11 + V12'
  // V12 + V22'
  // M2 + S1*M2
  // S2*M3 - M3

  //printf("Matrix inverse \n");
  // inv(Mat2)
  // inv(Mat3)

  //printf("Vector-Matrix Multiplication \n");
  // M2 * V11
  // V12 * M2
  // M3 * V21
  // V22 * M3

  //printf("Matrix division \n");
  // (S1*eye(2)) \ Mat2
  // Mat2 / (S2*sys(2))
  // (S1*eye(3)) \ Mat3
  // Mat3 / (S2*sys(3))

  //printf("Dot and cross product \n");
  // Dot(V21,[1;1;1])
  // Cross(V11,[1;1])
  // Skew(V21)

  //printf("Program complete\n\n");

  return 0 ;

}



