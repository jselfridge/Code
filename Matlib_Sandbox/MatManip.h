
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  MatManip.h
//  Justin M Selfridge
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef _MATMANIP_H
#define _MATMANIP_H

#include "MatIO.h"
//#include "MatArith.h"
//#include "MatProp.h"
//#include "MatDecomp.h"

void     mat_set    ( matrix* mat, int row, int col, double val );
double   mat_get    ( matrix* mat, int row, int col );
matrix*  mat_copy   ( matrix* mat );
matrix*  mat_eye    ( int n );
matrix*  mat_ones   ( int rows, int cols );
matrix*  mat_scale  ( matrix* mat, double scale );
void     mat_swapr   ( matrix* mat, int p, int q );
void     mat_swapc   ( matrix* mat, int n, int m );

#endif



