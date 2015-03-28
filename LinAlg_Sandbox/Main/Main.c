
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

  printf("Define scalars, vectors and matrices: \n");
  // S1 = 2;  S2 = 3;
  // Vec V11 = [2;3]; V12 = [3,2];
  // Vec V21 = [3;5;7]; V22 = [7,5,3];
  // Mat M2 = [ 2,3; 5,7 ];
  // Mat M3 = [ 3,5,8; 6,3,4; 1,9,3 ];

  printf("Scalar multiplication and division \n");
  // V21 * S1
  // V22 / S2
  // Mat2 * S1
  // Mat3 / S1

  printf("Transpose \n");
  // V11'
  // V22'
  // Mat2'
  // Mat3'

  printf("Addition and subtraction \n");
  // V11 + V12'
  // V12 + V22'
  // M2 + S1*M2
  // S2*M3 - M3

  printf("Matrix inverse \n");
  // inv(Mat2)
  // inv(Mat3)

  printf("Vector-Matrix Multiplication \n");
  // M2 * V11
  // V12 * M2
  // M3 * V21
  // V22 * M3

  printf("Identity and zeros \n");
  // eye(2)
  // eye(3)
  // zero(2,4)
  // zero(3)

  printf("Matrix division \n");
  // (S1*eye(2)) \ Mat2
  // Mat2 / (S2*sys(2))
  // (S1*eye(3)) \ Mat3
  // Mat3 / (S2*sys(3))

  printf("Dot and cross product \n");
  // Dot(V21,[1;1;1])
  // Cross(V11,[1;1])
  // Skew(V21)

  printf("Program complete\n\n");

  return 0 ;

}



