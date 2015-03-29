
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Temp.c - Matlib Library Development 
//  Justin M Selfridge
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
  offset = (row-1) * (mat->rows) + (col-1);
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
  offset = (row-1) * (mat->rows) + (col-1);
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
  else if ( power==1 )  {  return mat;  }
  else {

    out = mat_init( mat->rows, mat->cols );
    for ( int i=0; i< power-1; i++ ) {
      if ( i==0 )  { out = mat_mul( mat, mat ); }
      else         { out = mat_mul( out, mat ); }
    }

  }

  return out;
}










/*
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_det
//  Matrix determinant of a square matrix.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
double mat_det( matrix* mat, int order ) {


}
*/
/*
int determinant(int f[20][20],int x)
{
  int pr,c[20],d=0,b[20][20],j,p,q,t;
  if(x==2)
    {
      d=0;
      d=(f[1][1]*f[2][2])-(f[1][2]*f[2][1]);
      return(d);
    }
  else
    {
      for(j=1;j<=x;j++)
	{       
	  int r=1,s=1;
	  for(p=1;p<=x;p++)
	    {
	      for(q=1;q<=x;q++)
		{
		  if(p!=1&&q!=j)
		    {
		      b[r][s]=f[p][q];
		      s++;
		      if(s>x-1)
			{
			  r++;
			  s=1;
			}
		    }
		}
	    }
	  for(t=1,pr=1;t<=(1+j);t++)
	    pr=(-1)*pr;
	  c[j]=pr*determinant(b,x-1);
	}
      for(j=1,d=0;j<=x;j++)
	{
	  d=d+(f[1][j]*c[j]);
	}
      return(d);
    }
}
*/






/*
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_inv
//  Matrix inverse of a square matrix.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_inv ( matrix* mat ) {

  matrix*  out      = mat_init( mat->rows, mat->cols );
  double*  outdata  = out->data;
  double*  matdata  = mat->data;

  mat_err( mat->rows != mat->cols, "Error (mat_inv): inverse requires a square matrix" );


  return out;
}
*/












//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  MatProp (matrix properties)
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  MatOver (matrix overloaded operators)
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++








/*
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_trans
//  Returns the transpose of a rectangular matrix or an array.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_trans ( matrix* mat )  {

  int     i, j;
  matrix* out = mat_create( mat->height, mat->width );
  double* outdata;
  double* matdata = mat->data;

  for (i = 0; i < mat->height; i++) {
    outdata = &out->data[i];
    for (j = 0; j < mat->width; j++) {
      *outdata = *matdata;
      matdata++;
      outdata += out->width;
    }
  }

  return out;
}
*/




/*
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_trace
//  Returns the scalar trace of a rectangular matrix, which 
//  is the summation along the main diagonal.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
double mat_trace ( matrix* mat )  {

  int      i, size;
  double*  matdata = mat->data;
  double   sum = 0.0;

  if ( mat->height < mat->width )  { size = mat->height; }
  else                             { size = mat->width;  }

  for ( i=0; i<size; i++ ) {
    sum += *matdata;
    matdata += mat->width + 1;
  }

  return sum;
}
*/





//double mat_mean    ( matrix* mat );  // WIP
//matrix*  mat_meanr   ( matrix* mat );  // WIP




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


/*
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  mat_mul
//  Performs matrix multiplication.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
matrix* mat_mul ( matrix* matA, matrix* matB )  {

  int i, j, k;
  matrix* out;
  double* outdata;
  double* Adata;
  double* Bdata;

  mat_err( matA->width != matB->height, "Error (mat_mul): matrix dimension mismatch" );
  out = mat_create( matB->width, matA->height );
  outdata = out->data;

  for ( i=0; i< matA->height; i++ ) {

    for ( j=0; j< matB->width; j++ ) {
      Adata = &matA->data[ i * matA->width ];
      Bdata = &matB->data[j];
      *outdata = 0;

      for ( k=0; k< matA->width; k++ ) {
        *outdata += (*Adata) * (*Bdata);
        Adata++;
        Bdata += matB->width;
      }
      outdata++;

    }
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



