
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Matrix.h
//  Justin M Selfridge
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef _MATRIX_H
#define _MATRIX_H




/*
 * This is my personal matrix C library.
 * Now I understand why the NR library was created.
 * I didn't realize how quickly I would run into
 * memory problems when working with matricies.
 *
 * None of the matrix operations below change the
 * input matrices if an input is required. They all
 * return a new matrix with the new changes.
 *
 * Because memory issues are so prevelant, be sure
 * to use the "freeMatrix" function to reclaim some
 * of that memory.
 *
 * Most of the algorithms come from the following books:
 *
 * Numerical Recipes in C (2nd Edition)
 * 1992
 * By Press, Teukolsky, Vetterling, and Flannery
 *
 * Matric Computations (3rd Edition)
 * 1996
 * By Golub and Loan
 */



// Matrix structure declaration
typedef struct _matrix {
  char name[32];
  int height;
  int width;
  double* data;
} matrix;


void    mat_err     ( int cond, char* msg );
matrix* mat_create  ( int width, int height );
matrix* mat_read    ( char* file );
matrix* mat_copy    ( matrix* mat );
void    mat_print   ( matrix* mat );
void    mat_write   ( matrix* mat, char* file );
void    mat_clear   ( matrix* mat );


matrix* mat_eye     ( int n );
matrix* mat_scale   ( matrix* mat, double scale );




//============================
// Stuff I wish C had.
//============================
//void    assert(int assertion, char* message);          // COMPLETE

//============================
// Catch and release functions
//============================
//matrix* readMatrix(char* filename);                    // COMPLETE
//matrix* makeMatrix(int width, int height);             // COMPLETE
//matrix* copyMatrix(matrix* m);                         // COMPLETE
//void    freeMatrix(matrix* m);                         // COMPLETE
//void    writeMatrix(matrix* m, char* filename);        // COMPLETE
//void    printMatrix(matrix* m);                        // COMPLETE

//============================
// Basic Matrix operations
//============================
//matrix* eyeMatrix(int n);                              // COMPLETE
//double  traceMatrix(matrix* m);
//matrix* transposeMatrix(matrix* m);
//matrix* meanMatrix(matrix* m);
//matrix* multiplyMatrix(matrix* a, matrix* b);
//matrix* scaleMatrix(matrix* m, double value);          // COMPLETE
//matrix* covarianceMatrix(matrix* m);
//void    rowSwap(matrix* a, int p, int q); // This method changes the input matrix.
//matrix* dotProductMatrix(matrix* a, matrix* b);
//matrix* dotDiagonalMatrix(matrix* a, matrix* b);
//matrix* L2_distance(matrix* a, matrix* b);

#endif



