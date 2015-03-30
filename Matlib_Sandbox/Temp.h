
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Temp.h - Matlib Library Development
//  Justin M Selfridge
//  Temporary header file to develop the functions 
//  for the Matlib Library.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef _TEMP_H
#define _TEMP_H


// Standard includes
#include <math.h>




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Matrix structure declaration
typedef struct _matrix {
  int rows;
  int cols;
  double* data;
} matrix;




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MatIO (matrix input and output)
void     mat_err    ( int cond, char* msg );
matrix*  mat_init   ( int rows, int cols );
matrix*  mat_read   ( char* file );
void     mat_print  ( matrix* mat );
void     mat_write  ( matrix* mat, char* file );
void     mat_clear  ( matrix* mat );




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MatManip (matrix manipulation)
void     mat_set    ( matrix* mat, int row, int col, double val );
double   mat_get    ( matrix* mat, int row, int col );
matrix*  mat_copy   ( matrix* mat );
matrix*  mat_eye    ( int n );
matrix*  mat_ones   ( int rows, int cols );
matrix*  mat_scale  ( matrix* mat, double scale );
//matrix* mat_swapr   ( matrix* mat, int n, int m );
//matrix* mat_swapc   ( matrix* mat, int n, int m );



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MatArith (matrix arithmetic)
matrix*  mat_add    ( matrix* matA, matrix* matB );
matrix*  mat_sub    ( matrix* matA, matrix* matB );
matrix*  mat_mul    ( matrix* matA, matrix* matB );
matrix*  mat_pow    ( matrix* mat, int power );
matrix*  mat_trans  ( matrix* mat );
matrix*  mat_skew   ( matrix* vec );
matrix*  mat_cross  ( matrix* vecA, matrix* vecB );
double   mat_dot    ( matrix* vecA, matrix* vecB );




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MatProp (matrix properties)/
double   mat_trace   ( matrix* mat );
//double   mat_norm1   ( matrix* mat );
//double   mat_norm2   ( matrix* mat );
//double   mat_normI   ( matrix* mat );
//double   mat_mean    ( matrix* mat );
//matrix*  mat_meanr   ( matrix* mat );
//matrix*  mat_meanc   ( matrix* mat );
//matrix*  mat_eigval  ( matrix* mat );
//matrix*  mat_eigvec  ( matrix* mat );
//matrix*  mat_cov     ) matrix* mat );




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MatDecomp (matrix decompositions)
void     mat_LU    ( matrix* mat, matrix** L, matrix** U );
double   mat_det   ( matrix* mat );
matrix*  mat_inv   ( matrix* mat );
matrix*  mat_divL  ( matrix* A, matrix* B );
matrix*  mat_divR  ( matrix* B, matrix* A );








//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  L2_distance.h
//matrix* L2_distance(matrix* a, matrix* b);        // NOT INTERESTED

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  eigen.h
//double powerMethod(matrix* a);                    // NOT INTERESTED
//matrix* francisQRstep(matrix* a);
//matrix* eigenvec(matrix* a, double eigenval);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  matrix.h
//void assert(int assertion, char* message);        // COMPLETE 
//matrix* readMatrix(char* filename);               // COMPLETE
//matrix* makeMatrix(int width, int height);        // COMPLETE
//matrix* copyMatrix(matrix* m);                    // COMPLETE
//void freeMatrix(matrix* m);                       // COMPLETE
//void writeMatrix(matrix* m, char* filename);      // COMPLETE
//void printMatrix(matrix* m);                      // COMPLETE
//matrix* eyeMatrix(int n);                         // COMPLETE
//double traceMatrix(matrix* m);                    // COMPLETE
//matrix* transposeMatrix(matrix* m);               // COMPLETE
//matrix* meanMatrix(matrix* m);                    // NOT INTERSTED
//matrix* multiplyMatrix(matrix* a, matrix* b);     // COMPLETE
//matrix* scaleMatrix(matrix* m, double value);     // COMPLETE
//matrix* covarianceMatrix(matrix* m);              // NOT INTERSETED
//void rowSwap(matrix* a, int p, int q);
//matrix* dotProdMatrix(matrix* a, matrix* b);      // NOT INTERESTED
//matrix* dotDiagMatrix(matrix* a, matrix* b);      // NOT INTERSETED
//matrix* L2_distance(matrix* a, matrix* b);        // NOT INTERESTED

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  matrixadv.h
//void LUdecomp(mat* a, mat** l, mat** u);          // COMPLETE
//double determinantMatrix(matrix* a);              // COMPLETE
//matrix* matrixInverse(matrix* a);                 // COMPLETE
//matrix* solver(matrix* a, matrix* b);             // COMPLETE

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  qr.h
//void gram_schmidt(mat* a, mat** q, mat** r);      // NOT INTERSETED
//matrix* unitVectorRows(matrix* a);                // NOT INTERSETED
//matrix* unitVectorColumns(matrix* a);             // NOT INTERSETED

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  qsort.h
//void quicksort(double *a, int start, int end);    // NOT INTERSETED
//int partition(double *a, int start, int end);     // NOT INTERESTED

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  svd.h
//void svd(matrix* a);                              // NOT INTERESTED




#endif



