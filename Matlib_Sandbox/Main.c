
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Main.c - Matlib Library Development
//  Justin M Selfridge
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Standard include files
#include <stdio.h>

// Custom include files
#include "Temp.h"



// Main program loop
int main() {

  printf("\nRunning Matlib demo \n");

  /*
  //~~~~~~~~~~~~~~~~~~~~
  // MatIO function testing 
  printf("MatIO function testing  \n");
  matrix* M = mat_init(5,2);
  mat_print(M);
  mat_write(M,"matM");
  matrix* N = mat_read("matM");
  mat_print(N);
  mat_clear(M); mat_clear(N);
  */
  
  //~~~~~~~~~~~~~~~~~~~~
  // MatIO error checking
  //mat_init(0,4);
  //mat_read("matM");


  //~~~~~~~~~~~~~~~~~~~~
  // MatManip function testing
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

  //~~~~~~~~~~~~~~~~~~~~
  // MatManip error checking
  // mat_eye(n);
  // mat_ones(n,m);


  printf("Program complete\n\n");

  return 0 ;

}



