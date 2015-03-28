
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Temp.h - Matlib Library Development
//  Justin M Selfridge
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef _TEMP_H
#define _TEMP_H




// Matrix structure declaration
typedef struct _matrix {
  int rows;
  int cols;
  double* data;
} matrix;




//~~~~~~~~~~~~~~~~~~~~
// MatIO (matrix input and output)
void     mat_err    ( int cond, char* msg );
matrix*  mat_init   ( int rows, int cols );
matrix*  mat_read   ( char* file );
void     mat_print  ( matrix* mat );
void     mat_write  ( matrix* mat, char* file );
void     mat_clear  ( matrix* mat );




//~~~~~~~~~~~~~~~~~~~~
// MatManip (matrix manipulation)
void     mat_set    ( matrix* mat, int row, int col, double val );
double   mat_get    ( matrix* mat, int row, int col );
matrix*  mat_copy   ( matrix* mat );
matrix*  mat_eye    ( int n );
matrix*  mat_ones   ( int rows, int cols );
matrix*  mat_scale  ( matrix* mat, double scale );




//~~~~~~~~~~~~~~~~~~~~
// MatProp (matrix properties)
//matrix*  mat_trans   ( matrix* mat );                    // Issue with vectors
//double   mat_trace   ( matrix* mat );
//double   mat_mean    ( matrix* mat );  // WIP
//matrix*  mat_meanr   ( matrix* mat );  // WIP
//matrix*  mat_meanc   ( matrix* mat );  // WIP
//matrix*  mat_mul     ( matrix* matA, matrix* matB );  // WIP




//~~~~~~~~~~~~~~~~~~~~
// MatArith (matrix arithmetic)




//~~~~~~~~~~~~~~~~~~~~
// MatOver (matrix overloaded operators)




#endif



