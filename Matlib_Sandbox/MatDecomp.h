
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  MatDecomp.h
//  Justin M Selfridge
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef _MATDECOMP_H
#define _MATDECOMP_H

#include "MatIO.h"
#include "MatManip.h"
#include "MatArith.h"
//#include "MatProp.h"

void     mat_LU    ( matrix* mat, matrix** L, matrix** U );
double   mat_det   ( matrix* mat );
matrix*  mat_inv   ( matrix* mat );
matrix*  mat_divL  ( matrix* A, matrix* B );
matrix*  mat_divR  ( matrix* B, matrix* A );

#endif



