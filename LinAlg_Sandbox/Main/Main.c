
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Linear Algebra Demonstration Project
//  Justin M Selfridge
//  Main.c
//  Main source code to run the linear algebra demonstration.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "Main.h"

// Main program loop
/*
int main() {

  printf("\nHello Linear Algebra Demo! \n");

  printf("Running the BLAS functionality! \n");
  LinAlg_Demo();

  printf("Program complete\n\n");

  return 0 ;

}
*/

/*
void LinAlg_Demo() {

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


}
*/



/* Start of Listing */
//#include "f2c.h"
//#include "stdio.h"
//#include "clapack.h"

#define SIZE 4

//void MAIN_(){}
//void MAIN__(){}
//void _MAIN_(){}

int main( ) {

  printf("\nMain program \n");

  double myV[4*1] = { 2.0, 3.0, 4.0, 5.0 };
  //_nrm2(myV);

  /*
  char JOBU;
  char JOBVT;

  int i;

  integer M = SIZE;
  integer N = SIZE;
    
  integer LDA = M;
  integer LDU = M;
  integer LDVT = N;
  integer LWORK;
  integer INFO;
   
  integer mn = min( M, N );    
  integer MN = max( M, N );

  double a[SIZE*SIZE] = { 16.0, 5.0, 9.0 , 4.0, 2.0, 11.0, 7.0 , 14.0, 3.0, 10.0, 6.0, 15.0, 13.0, 8.0, 12.0, 1.0};
  double s[SIZE];
  double wk[201];
  double uu[SIZE*SIZE];
  double vt[SIZE*SIZE];

  JOBU = 'A';     
  JOBVT = 'A';
  LWORK =  201;
  */


  //double myB[4*1] = { 9.0, 8.0, 7.0, 6.0 };

  // REAL FUNCTION sdot(N,SX,INCX,SY,INCY)
  //real dot = sdot_( 1, &myA, 4, &myB, 4 );
    
  /* Subroutine int dgesvd_(char *jobu, char *jobvt, integer *m, integer *n, 
        doublereal *a, integer *lda, doublereal *s, doublereal *u, integer *
        ldu, doublereal *vt, integer *ldvt, doublereal *work, integer *lwork, 
        integer *info)
  */

  /*
  dgesvd_( &JOBU, &JOBVT, &M, &N, a, &LDA, s, uu, 
	   &LDU, vt, &LDVT, wk, &LWORK, &INFO);
  */
  /*
  printf("\n INFO=%d", INFO );          

  for ( i= 0; i< SIZE; i++ ) {
    printf("\n s[ %d ] = %f", i, s[ i ] );
  }
  */

  printf("End program \n\n");

  return 0;

}     

/* End of Listing */
