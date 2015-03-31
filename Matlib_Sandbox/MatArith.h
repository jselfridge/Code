
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  MatArith.h
//  Justin M Selfridge
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef _MATARITH_H
#define _MATARITH_H

#include "MatIO.h"
#include "MatManip.h"
//#include "MatProp.h"
//#include "MatDecomp.h"

matrix*  mat_add    ( matrix* matA, matrix* matB );
matrix*  mat_sub    ( matrix* matA, matrix* matB );
matrix*  mat_mul    ( matrix* matA, matrix* matB );
matrix*  mat_pow    ( matrix* mat, int power );
matrix*  mat_trans  ( matrix* mat );
matrix*  mat_skew   ( matrix* vec );
matrix*  mat_cross  ( matrix* vecA, matrix* vecB );
double   mat_dot    ( matrix* vecA, matrix* vecB );

#endif



