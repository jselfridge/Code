
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  MatIO.h
//  Justin M Selfridge
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef _MATIO_H
#define _MATIO_H

void     mat_err    ( int cond, char* msg );
matrix*  mat_init   ( int rows, int cols );
matrix*  mat_read   ( char* file );
void     mat_print  ( matrix* mat );
void     mat_write  ( matrix* mat, char* file );
void     mat_clear  ( matrix* mat );

#endif



