
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
// MatArith (matrix arithmetic)
matrix*  mat_add    ( matrix* matA, matrix* matB );
matrix*  mat_sub    ( matrix* matA, matrix* matB );
matrix*  mat_mul    ( matrix* matA, matrix* matB );
matrix*  mat_pow    ( matrix* mat, int power );


//matrix*  mat_inv    ( matrix* mat );
//matrix*  mat_trans  ( matrix* mat );





//~~~~~~~~~~~~~~~~~~~~
// MatProp (matrix properties)
//double   mat_det     ( matrix* mat );
//double   mat_trace   ( matrix* mat );
//double   mat_mean    ( matrix* mat );
//matrix*  mat_meanr   ( matrix* mat );
//matrix*  mat_meanc   ( matrix* mat );









#endif



