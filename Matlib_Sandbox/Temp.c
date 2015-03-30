
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Temp.c - Matlib Library Development 
//  Justin M Selfridge
//  Temporary source code file to develop the functions
//  for the Matlib Labrary.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "Temp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>








//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  MatIO (matrix input and output)
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_err
//  If error condition is true, prints a warning and exits.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void mat_err ( int cond, char* msg ) {
  if (cond) {
    fprintf( stderr, "%s\n\n", msg );
    exit(1);
  }
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_init
//  Initializes a new matrix with the specified dimensions, and
//  sets the elements to values of zero.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_init ( int rows, int cols ) {

  matrix* out;
  mat_err( ( rows<1 || cols<1 ), "Error (mat_init): matrix dimensions must be positive" ); 

  out = (matrix*) malloc( sizeof(matrix) );
  mat_err( out == NULL, "Error (mat_init): matrix returned NULL" );

  out->rows = rows;
  out->cols = cols;
  out->data = (double*) malloc( sizeof(double) * rows * cols );

  mat_err( out->data == NULL, "Error (mat_init): matrix data returned NULL" );
  memset( out->data, 0.0, rows * cols * sizeof(double) );

  return out;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_read
//  Reads a matrix from a file.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_read ( char* file ) {

  FILE*    f;
  int      i, elem;
  int      rows, cols;
  int      scan;
  float    val;
  matrix*  out;
  double*  outdata;

  if ( ( f= fopen( file, "r" ) ) == NULL ) {
    fprintf( stderr, "Error (mat_read): cannot open %s \n", file );
    exit(1);
  }

  scan = fscanf( f, "%d", &rows );
  mat_err( scan==EOF, "Error (mat_read): failed to read 'rows' from file" );

  scan = fscanf( f, "%d", &cols );
  mat_err( scan==EOF, "Error (mat_read): failed to read 'col' from file" );

  out = mat_init( rows, cols );
  elem = rows * cols; 
  outdata = out->data;

  for ( i=0; i<elem; i++ ) {
    scan = fscanf( f, "%f", &val );
    mat_err( scan==EOF, "Error (mat_read): matrix is missing elements" );
    *(outdata++) = val;
  }

  scan = fscanf( f, "%f", &val );
  mat_err( scan!=EOF, "Error (mat_read): matrix has extra elements" );

  fclose(f);
  return out;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_print
//  Display a matrix in the terminal.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void mat_print( matrix* mat ) {

  double* matdata = mat->data;
  printf( "[%dx%d]\n", mat->rows, mat->cols );

  for ( int i=0; i< mat->rows; i++ ) {
    for ( int j=0; j< mat->cols; j++ ) {
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
void mat_write ( matrix* mat, char* file ) {

  FILE* f;
  double* matdata = mat->data;

  if ( ( f= fopen( file, "w" ) ) == NULL ) {
    fprintf( stderr, "Error (mat_write): cannot open %s\n", file );
    exit(1);
  }

  fprintf( f, "%d %d\n", mat->rows, mat->cols );

  for ( int i=0; i< mat->rows; i++ ) {
    for ( int j=0; j< mat->cols; j++ ) {
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
void mat_clear( matrix* mat ) {

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








//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  MatManip (matrix manipulation)
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_set
//  Assigns a value into a matrix element
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void mat_set ( matrix* mat, int row, int col, double val ) {

  double* matdata;
  int     offset;

  mat_err( ( row > mat->rows ) || ( col > mat->cols ), "Error (mat_set): index exceeds matrix dimensions" );

  matdata = mat->data;
  offset = (row-1) * (mat->cols) + (col-1);
  matdata += offset;
  *matdata = val;

}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_get
//  Returns the value of a matrix element.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
double mat_get ( matrix* mat, int row, int col ) {

  double* matdata;
  int     offset;
  double  val;

  mat_err( ( row > mat->rows ) || ( col > mat->cols ), "Error (mat_get): index exceeds matrix dimensions" );

  matdata = mat->data;
  offset = (row-1) * (mat->cols) + (col-1);
  matdata += offset;
  val = *matdata;

  return val;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_copy
//  Copies a matrix into a new matrix.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_copy ( matrix* mat ) {
  return mat_scale( mat, 1.0 );
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_eye
//  Creates an identity matrix of size n.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_eye ( int n ) {

  matrix* out;
  double* outdata;

  mat_err( n<1, "Error (mat_eye): identity matrix dimension must be positive." );

  out = mat_init( n, n );
  outdata = out->data;

  for ( int i=0; i<n; i++ ) {
    *outdata = 1.0;
    outdata += n+1;
  }

  return out;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_ones
//  Creates a new nxm  matrix filled with values of one.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_ones ( int rows, int cols ) {

  matrix* out;
  double* outdata;
  int elem = rows * cols;

  mat_err(  rows<1 || cols<1, "Error (mat_ones): identity matrix dimension must be positive." );

  out = mat_init( rows, cols );
  outdata = out->data;

  for ( int i=0; i<elem; i++ ) {
    *outdata = 1.0;
    outdata++;
  }

  return out;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_scale
//  Multiplies a matrix by a scalar with type double.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_scale ( matrix* mat, double scale ) {

  int      elem     = mat->rows * mat->cols;
  matrix*  out      = mat_init( mat->rows, mat->cols );
  double*  outdata  = out->data;
  double*  matdata  = mat->data;

  for ( int i=0; i<elem; i++ ) {
    *(outdata++) = *(matdata++) * scale;
  }

  return out;
}








//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  MatArith (matrix arithmetic)
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_add
//  Adds two arrays of indentical dimension.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_add ( matrix* matA, matrix* matB ) {

  matrix* out;
  double* outdata;
  double* Adata;
  double* Bdata;
  int     elem = matA->rows * matA->cols;

  mat_err( matA->rows != matB->rows, "Error (mat_add): matrices must have same number of rows" );
  mat_err( matA->cols != matB->cols, "Error (mat_add): matrices must have same number of columns" );

  out = mat_init( matA->rows, matA->cols );
  outdata = out->data;
  Adata = matA->data;
  Bdata = matB->data;

  for ( int i=0; i<elem; i++ ) {
    *(outdata++) = *(Adata++) + *(Bdata++);
  }

  return out;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_sub
//  Subtracts two arrays of identical dimension.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_sub ( matrix* matA, matrix* matB ) {

  matrix* out;
  double* outdata;
  double* Adata;
  double* Bdata;
  int     elem = matA->rows * matA->cols;

  mat_err( matA->rows != matB->rows, "Error (mat_sub): matrices must have same number of rows" );
  mat_err( matA->cols != matB->cols, "Error (mat_sub): matrices must have same number of columns" );

  out = mat_init( matA->rows, matA->cols );
  outdata = out->data;
  Adata = matA->data;
  Bdata = matB->data;

  for ( int i=0; i<elem; i++ ) {
    *(outdata++) = *(Adata++) - *(Bdata++);
  }

  return out;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_mul
//  Matrix multiplication on two matrices with proper dimension.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_mul ( matrix* matA, matrix* matB ) {

  matrix* out;
  double* outdata;
  double* Adata;
  double* Bdata;

  mat_err( matA->cols != matB->rows, "Error (mat_mul): matrix dimensions do not agree" );

  out = mat_init( matA->rows, matB->cols );
  outdata = out->data;

  for ( int i=0; i< matA->rows; i++ ) {
    for ( int j=0; j< matB->cols; j++ ) {

      Adata = &matA->data[ i * matA->cols ];
      Bdata = &matB->data[j];
      *outdata = 0;

      for ( int k=0; k< matA->rows; k++ ) {
        *outdata += (*Adata) * (*Bdata);
        Adata++;
        Bdata += matB->cols;
      }
      outdata++;

    }
  }

  return out;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_pow
//  Raise a square matrix to the specified power.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_pow ( matrix* mat, int power ) {

  matrix* out;

  mat_err( mat->rows != mat->cols, "Error (mat_pow): matrix must be square to raise to a power" );
  mat_err( power<0, "Error (mat_pow): power must be nonnegative" );

  if      ( power==0 )  {  out = mat_eye(mat->rows);  return out;  }
  else if ( power==1 )  {  out = mat_copy(mat);       return out;  }
  else {

    out = mat_init( mat->rows, mat->cols );
    for ( int i=0; i< power-1; i++ ) {
      if ( i==0 )  { out = mat_mul( mat, mat ); }
      else         { out = mat_mul( out, mat ); }
    }

  }

  return out;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_trans
//  Returns the transpose of a rectangular matrix or an array.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_trans ( matrix* mat ) {

  matrix*  out      = mat_init( mat->cols, mat->rows );
  double*  outdata  = out->data;
  double*  matdata  = mat->data;

  for ( int i=0; i< mat->rows; i++ ) {
    outdata = &out->data[i];
    for ( int j=0; j< mat->cols; j++ ) {
      *outdata = *matdata;
      matdata++;
      outdata += out->cols;
    }
  }

  return out;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_skew
//  Returns skew symmetric matrix of a three element vector.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_skew ( matrix* vec ) {

  matrix*  out = mat_init(3,3);
  double   x, y, z;

  mat_err( ( vec->rows!=3 || vec->cols!=1 ), "Error (mat_skew): vector must be [3x1]" );

  x = mat_get(vec,1,1);  mat_set(out,3,2,x);  mat_set(out,2,3,-x);
  y = mat_get(vec,2,1);  mat_set(out,1,3,y);  mat_set(out,3,1,-y);
  z = mat_get(vec,3,1);  mat_set(out,2,1,z);  mat_set(out,1,2,-z);

  return out;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_cross
//  Returns cross product of two three element vectors.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_cross ( matrix* vecA, matrix* vecB ) {

  matrix*  out = mat_init(3,1);

  mat_err( ( vecA->rows!=3 || vecA->cols!=1 ), "Error (mat_cross): vector A must be [3x1]" );
  mat_err( ( vecB->rows!=3 || vecB->cols!=1 ), "Error (mat_cross): vector B must be [3x1]" );

  return out = mat_mul( mat_skew(vecA), vecB );
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_dot
//  Returns dot product of two arbitrary length vectors.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
double mat_dot ( matrix* vecA, matrix* vecB ) {

  mat_err( ( vecA->cols!=1 || vecB->cols!=1 ), "Error (mat_dot): dot product requires vector inputs" );
  mat_err( ( vecA->rows != vecB->rows ), "Error (mat_dot): vectors must be the same length" );

  double out = 0.0;
  for ( int r=1; r<= vecA->rows; r++ ) {
    out += (mat_get(vecA,r,1)) * (mat_get(vecB,r,1)) ;
  }

  return out;
}








//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  MatProp (matrix properties)
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_trace
//  Returns the trace of a matrix (sum of main diagonal)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
double mat_trace ( matrix* mat ) {

  int      n;
  double*  matdata = mat->data;
  double   sum = 0.0;

  if   ( mat->rows < mat->cols )  { n = mat->rows; }
  else                            { n = mat->cols;  }

  for ( int i=0; i<n; i++ ) {  
    sum += *matdata;
    matdata += mat->cols + 1;
  }

  return sum;
}








//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  MatDecomp (matrix decompositions)
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_LU
//  Solves for the LU decomposition of a matrix.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void mat_LU ( matrix* mat, matrix** L, matrix** U ) {

  mat_err( *L != NULL || *U != NULL, "Error (mat_LU): Matricies L and U must be null. ");
  mat_err( mat->rows != mat->cols, "Error (mat_LU): Matrix must be square. ");

  int     n = mat->rows;
  double  sum;
  double* data;
  double* Ldata;
  double* Udata;

  *L = mat_eye(n);
  *U = mat_init(n,n);

  data  = mat->data;
  Ldata = (*L)->data;
  Udata = (*U)->data;

  // Loop through calculations
  for ( int j=0; j<n; j++ ) {

    // Derive upper matrix
    for ( int i=0; i<=j; i++ ) {
      sum = 0.0;
      for ( int k=0; k<i; k++ ) {  sum += Ldata[i*n+k] * Udata[k*n+j];  }
      Udata[i*n+j] = data[i*n+j] - sum;
    }

    // Derive lower matrix
    for ( int i=j+1; i<n; i++ ) {
      sum = 0.0;
      for ( int k=0; k<j; k++ ) {  sum += Ldata[i*n+k] * Udata[k*n+j];  }
      Ldata[i*n+j] = 1.0/Udata[j*n+j] * ( data[i*n+j] - sum );
    }

  }

  return;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_det
//  Returns the determinant of a square matrix.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
double mat_det ( matrix* mat ) {

  int     n = mat->rows;
  double  product = 1.0;
  matrix* L = NULL;
  matrix* U = NULL;

  mat_err( mat->rows != mat->cols, "Error (mat_det): Matrix A must be square.");

  mat_LU( mat, &L, &U );
  for ( int i=0; i<n; i++ ) {  product *= U->data[i*n+i];  }
  mat_clear(L);  mat_clear(U);

  return product;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_inv
//  Returns the inverse of a square matrix.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_inv ( matrix* mat ) {

  mat_err( mat->rows != mat->cols, "Error (mat_inv): Matrix must be square." );

  matrix* eye = mat_eye( mat->rows );
  matrix* inv = mat_divL( mat, eye );

  mat_clear(eye);
  return inv;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_divL
//  Solves for x in b=Ax, equivalent to x=A\b.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_divL ( matrix* A, matrix* b ) {

  int     Ar = A->rows;  
  int     Ac = A->cols;
  int     Br = b->rows;
  int     Bc = b->cols;
  double* Bd = b->data;

  mat_err( Ar != Ac, "Error (mat_divL): A matrix must be square. " );
  mat_err( Ar != Br, "Error (mat_divL): A and b must be the same height." );

  matrix* L = NULL;  
  matrix* U = NULL;
  mat_LU( A, &L, &U );
  double* Ld = L->data;
  double* Ud = U->data;

  matrix* y;
  matrix* x;
  y = mat_init( 1,  Ar );
  x = mat_init( Br, Bc );
  double* yd = y->data;
  double* xd = x->data;

  double sum;
  double* row;

  for ( int k=0; k<Bc; k++ ) {

    // L backward subsitituion:  L * y = B_k
    for ( int i=0; i<Ar; i++ ) {
      row = Ld + i*Ac;
      sum = 0;
      for ( int j=0; j<i; j++ ) {
	sum += yd[j] * (*row++);
      }
      yd[i] = ( Bd[i*Bc+k] - sum) / *row;
    }

    // U backward subsitituion:  U * x = y
    for ( int i= Ar-1; i>=0; i-- ) {
      row = Ud + (i*Ac) + (Ac-1);
      sum = 0;
      for ( int j= Ac-1; j>i; j-- ) {
	sum += xd[j*Bc+k] * (*row--);
      }
      xd[i*Bc+k] = (yd[i] - sum) / *row;
    }

  }

  mat_clear(L);
  mat_clear(U);
  mat_clear(y);

  return x;
}






















//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  PENDING AND UNSORTED
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


/*
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_inv
//  Matrix inverse of a square matrix.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_inv ( matrix* mat ) {

}
*/





/*
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_meanc
//  Returns a row vector with the average values from the 
//  columns of a matrix.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_meanc ( matrix* mat ) {

  int     i, j;
  double* matdata;
  matrix* out;

  mat_err( mat->height <1, "Error (mat_meanc): Matrix height must be positive." );
  out = mat_create( mat->width, 1 );

  for ( i=0; i< mat->width; i++ ) {
    out->data[i] = 0.0;
    matdata = &mat->data[i];
    for ( j=0; j< mat->height; j++ ) {
      out->data[i] += *matdata;
      matdata += out->width;
    }
    out->data[i] /= (double) mat->height;
  }

  return out;
}
*/





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



