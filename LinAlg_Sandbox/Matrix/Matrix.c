
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Matrix.c
//  Justin M Selfridge
//  Library for performing basic matrix and vector 
//  manipulations.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_err
//  Test an error condition, and if true prints a warning
//  and exits the program.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void mat_err ( int cond, char* msg )  {
  if (cond) {
    fprintf( stderr, "%s\n", msg );
    exit(1);
  }
}




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_create
//  Creates a new matrix with the specified dimensions, and
//  sets the elements to values of zero.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_create( int width, int height ) {

  matrix* out;
  mat_err( ( width<1 || height<1 ), "Matrix dimensions must be positive" ); 

  out = (matrix*) malloc( sizeof(matrix) );
  mat_err( out == NULL, "Out of memory" );

  out->width = width;
  out->height = height;
  out->data = (double*) malloc( sizeof(double) * width * height );

  mat_err( out->data == NULL, "Out of memory");
  memset( out->data, 0.0, width * height * sizeof(double) );

  return out;
}




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_read
//  Reads a matrix from a file.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_read ( char* file )  {

  FILE*    f;
  int      i, elem;
  int      width, height;
  int      scan;
  float    val;
  matrix*  out;
  double*  outdata;

  if ( ( f= fopen( file, "r" ) ) == NULL ) {
    fprintf( stderr, "Error: Cannot open %s \n", file );
    exit(1);
  }

  scan = fscanf( f, "%d", &width );
  mat_err( scan==EOF, "Failed to read from file \n" );

  scan = fscanf( f, "%d", &height );
  mat_err( scan==EOF, "Failed to read from file \n" );

  out = mat_create( width, height );
  elem = width * height; 
  outdata = out->data;

  for ( i=0; i<elem; i++ ) {
    scan = fscanf( f, "%f", &val );
    mat_err( scan==EOF, "Matrix is missing elements \n" );
    *(outdata++) = val;
  }

  fclose(f);
  return out;
}
   



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_copy
//  Copies a matrix into a new matrix.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_copy ( matrix* mat )  {
  return mat_scale( mat, 1 );
}




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_print
//  Display a matrix in the terminal.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void mat_print( matrix* mat )  {

  int i, j;
  double* matdata = mat->data;
  printf( "[%dx%d]\n", mat->width, mat->height );

  for ( i=0; i< mat->height; i++ ) {
    for ( j=0; j< mat->width; j++ ) {
      printf( " %9.6f", *(matdata++) );
    }
    printf("\n");
  }

  return;
}




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_write
//  Writes a matrix to a file.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void mat_write ( matrix* mat, char* file )  {

  FILE* f;
  int i, j;
  double* matdata = mat->data;

  if ( ( f= fopen( file, "w" ) ) == NULL ) {
    fprintf( stderr, "Error: Cannot open %s\n", file );
    exit(1);
  }

  fprintf( f, "%d %d\n", mat->width, mat->height );

  for ( i=0; i< mat->height; i++ ) {
    for ( j=0; j< mat->width; j++ ) {
      fprintf( f, " %2.5f", *(matdata++) );
    }
    fprintf( f, "\n" );
  }

  fclose(f);  
  return;
}




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_clear
//  Destroys an existing matrix and frees the memory.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void mat_clear( matrix* mat )  {

  if ( mat != NULL ) {
    if ( mat->data != NULL ) {
      free( mat->data );
      mat->data = NULL;
    }
    free(mat);
    mat = NULL;
  }

  return;
}




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_eye
//  Creates an identity matrix of size n.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_eye ( int n )  {

  int i;
  matrix* out;
  double* outdata;

  mat_err( n<1, "Identity matrix dimension must be positive." );

  out = mat_create( n, n );
  outdata = out->data;

  for ( i=0; i<n; i++ ) {
    *outdata = 1.0;
    outdata += n+1;
  }

  return out;
}




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_scale
//  Multiplies a matrix by a scalar with type double.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_scale ( matrix* mat, double scale )  {

  int i;
  int elem = mat->width * mat->height;

  matrix* out = mat_create( mat->width, mat->height );

  double* matdata = mat->data;
  double* outdata = out->data;

  for ( i=0; i<elem; i++ ) {
    *(outdata++) = *(matdata++) * scale;
  }

  return out;
}

























/*===========================================================================
 * traceMatrix
 * Given an "m rows by n columns" matrix, it returns the sum of the elements
 * along the diagonal. This is know as the matrix 'trace'.
 *=========================================================================*/
/*~~~
double traceMatrix(matrix* m) {
    int i;
    int size;
    double* ptr = m->data;
    double sum = 0.0;

    if (m->height < m->width) {
        size = m->height;
    }
    else {
        size = m->width;
    }

    for (i = 0; i < size; i++) {
        sum += *ptr;
        ptr += m->width + 1;
    }

    return sum;
}
~~~*/



/*===========================================================================
 * meanMatrix
 * Given an "m rows by n columns" matrix, it returns a matrix with 1 row and
 * n columns, where each element represents the mean of that full column.
 *=========================================================================*/
/*~~~
matrix* meanMatrix(matrix* m) {
    int i, j;
    double* ptr;
    matrix* out;

    assert(m->height > 0, "Height of matrix cannot be zero.");

    out = makeMatrix(m->width, 1);

    for (i = 0; i < m->width; i++) {
        out->data[i] = 0.0;
        ptr = &m->data[i];
        for (j = 0; j < m->height; j++) {
            out->data[i] += *ptr;
            ptr += out->width;
        }
        out->data[i] /= (double) m->height;
    }
    return out;
}
~~~*/




/*===========================================================================
 * covarianceMatrix
 * Given an "m rows by n columns" matrix, it returns a matrix with n row and
 * n columns, where each element represents covariance of 2 columns.
 *=========================================================================*/
/*~~~
matrix* covarianceMatrix(matrix* m) {
    int i, j, k, L = 0;
    matrix* out;
    matrix* mean;
    double* ptrA;
    double* ptrB;
    double* ptrOut;

    assert(m->height > 1, "Height of matrix cannot be zero or one.");

    mean = meanMatrix(m);
    out = makeMatrix(m->width, m->width);
    ptrOut = out->data;

    for (i = 0; i < m->width; i++) {
        for (j = 0; j < m->width; j++) {
             ptrA = &m->data[i];
             ptrB = &m->data[j];
             *ptrOut = 0.0;
             for (k = 0; k < m->height; k++) {
                 *ptrOut += (*ptrA - mean->data[i]) * (*ptrB - mean->data[j]);
                 ptrA += m->width;
                 ptrB += m->width;
             }
             *ptrOut /= m->height - 1;
             ptrOut++;
        }
    }

    freeMatrix(mean);
    return out;
}
~~~*/


/*===========================================================================
 * transposeMatrix
 * Given an matrix, returns the transpose.
 *=========================================================================*/
/*~~~
matrix* transposeMatrix(matrix* m) {
    matrix* out = makeMatrix(m->height, m->width);
    double* ptrOut;
    double* ptrM = m->data;
    int i, j;

    for (i = 0; i < m->height; i++) {
        ptrOut = &out->data[i];
        for (j = 0; j < m->width; j++) {
            *ptrOut = *ptrM;
            ptrM++;
            ptrOut += out->width;
        }
    }

    return out;
}
~~~*/


/*===========================================================================
 * multiplyMatrix
 * Given a two matrices, returns the multiplication of the two.
 *=========================================================================*/
/*~~~
matrix* multiplyMatrix(matrix* a, matrix* b) {
    int i, j, k;
    matrix* out;
    double* ptrOut;
    double* ptrA;
    double* ptrB;

    assert(a->width == b->height, "Matrices have incorrect dimensions. a->width != b->height");

    out = makeMatrix(b->width, a->height);
    ptrOut = out->data;

    for (i = 0; i < a->height; i++) {

        for (j = 0; j < b->width; j++) {
            ptrA = &a->data[ i * a->width ];
            ptrB = &b->data[ j ];

            *ptrOut = 0;
            for (k = 0; k < a->width; k++) {
                *ptrOut += *ptrA * *ptrB;
                ptrA++;
                ptrB += b->width;
            }
            ptrOut++;
        }
    }

    return out;
}
~~~*/




/*===========================================================================
 * rowSwap
 * Given a matrix, this algorithm will swap rows p and q, provided
 * that p and q are less than or equal to the height of matrix A and p
 * and q are different values.
 *=========================================================================*/
/*~~~
void rowSwap(matrix* a, int p, int q) {
    int i;
    double temp;
    double* pRow;
    double* qRow;

    assert(a->height > 2, "Matrix must have at least two rows to swap.");
    assert(p < a->height && q < a->height, "Values p and q must be less than the height of the matrix.");

    // If p and q are equal, do nothing.
    if (p == q) {
        return;
    }

    pRow = a->data + (p * a->width);
    qRow = a->data + (q * a->width);

    // Swap!
    for (i = 0; i < a->width; i++) {
        temp = *pRow;
        *pRow = *qRow;
        *qRow = temp;
        pRow++;
        qRow++;
    }

    return;
}
~~~*/



/*===========================================================================
 * dotProductMatrix
 * Given a two matrices (or the same matrix twice) with identical widths and
 * different heights, this method returns a a->height by b->height matrix of
 * the cross product of each matrix.
 *
 * Dot product is essentially the sum-of-squares of two vectors.
 *
 * Also, if the second paramter is NULL, it is assumed that we
 * are performing a cross product with itself.
 *=========================================================================*/
/*~~~
matrix* dotProductMatrix(matrix* a, matrix* b) {
    matrix* out;
    double* ptrOut;
    double* ptrA;
    double* ptrB;
    int i, j, k;

    if (b != NULL) {
        assert(a->width == b->width, "Matrices must be of the same dimensionality.");
    }

    // Are we computing the sum of squares of the same matrix?
    if (a == b || b == NULL) {
        b = a; // May not appear safe, but we can do this without risk of losing b.
    }

    out = makeMatrix(b->height, a->height);
    ptrOut = out->data;

    for (i = 0; i < a->height; i++) {
        ptrB = b->data;

        for (j = 0; j < b->height; j++) {
            ptrA = &a->data[ i * a->width ];

            *ptrOut = 0;
            for (k = 0; k < a->width; k++) {
                *ptrOut += *ptrA * *ptrB;
                ptrA++;
                ptrB++;
            }
            ptrOut++;
        }
    }

    return out;
}
~~~*/


/*===========================================================================
 * matrixDotDiagonal
 * Given a two matrices (or the same matrix twice) with identical widths and
 * heights, this method returns a 1 by a->height matrix of the cross
 * product of each matrix along the diagonal.
 *
 * Dot product is essentially the sum-of-squares of two vectors.
 *
 * If the second paramter is NULL, it is assumed that we
 * are performing a cross product with itself.
 *=========================================================================*/
/*~~~
matrix* dotDiagonalMatrix(matrix* a, matrix* b) {
    matrix* out;
    double* ptrOut;
    double* ptrA;
    double* ptrB;
    int i, j;

    if (b != NULL) {
        assert(a->width == b->width && a->height == b->height, "Matrices must be of the same dimensionality.");
    }

    // Are we computing the sum of squares of the same matrix?
    if (a == b || b == NULL) {
        b = a; // May not appear safe, but we can do this without risk of losing b.
    }

    out = makeMatrix(1, a->height);
    ptrOut = out->data;
    ptrA = a->data;
    ptrB = b->data;

    for (i = 0; i < a->height; i++) {
        *ptrOut = 0;
        for (j = 0; j < a->width; j++) {
            *ptrOut += *ptrA * *ptrB;
            ptrA++;
            ptrB++;
        }
        ptrOut++;
    }

    return out;
}
~~~*/



