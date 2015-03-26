
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  LinSys.h
//  Justin M Selfridge
//  Header file for linear system functions
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef _LINSYS_H
#define _LINSYS_H

// Standand include files
#include <stdio.h>
//#include <math.h>


// Function prototypes
void LinSysTest();




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/**************************************************************************
 **
 ** Copyright (C) 1993 David E. Steward & Zbigniew Leyk, all rights reserved.
 **
 **     Meschach Library
 ** 
 ** This Meschach Library is provided "as is" without any express 
 ** or implied warranty of any kind with respect to this software. 
 ** In particular the authors shall not be liable for any direct, 
 ** indirect, special, incidental or consequential damages arising 
 ** in any way from use of the software.
 ** 
 ** Everyone is granted permission to copy, modify and redistribute this
 ** Meschach Library, provided:
 **  1.  All copies contain this copyright notice.
 **  2.  All modified copies shall carry a notice stating who
 **      made the last modification and the date of such modification.
 **  3.  No charge is made for this software or works derived from it.  
 **      This clause shall not be construed as constraining other software
 **      distributed on the same medium as this software, nor is a
 **      distribution fee considered a charge.
 **
 ***************************************************************************/


/*
  Type definitions for general purpose maths package
*/

#ifndefMATRIXH

/* RCS id: $Id: matrix.h,v 1.18 1994/04/16 00:33:37 des Exp $ */

#defineMATRIXH

#include"machine.h"
#include        "err.h"
#include "meminfo.h"

/* unsigned integer type */
/************************************************************
#ifndef U_INT_DEF
typedefunsigned intu_int;
#define U_INT_DEF
#endif
************************************************************/

/* vector definition */
typedefstruct{
  unsigned intdim, max_dim;
  Real*ve;
} VEC;

/* matrix definition */
typedefstruct{
  unsigned intm, n;
  unsigned intmax_m, max_n, max_size;
  Real**me,*base;/* base is base of alloc'd mem */
} MAT;

/* band matrix definition */
typedef struct {
  MAT   *mat;       /* matrix */
  int   lb,ub;    /* lower and upper bandwidth */
} BAND;


/* permutation definition */
typedefstruct{
  unsigned intsize, max_size, *pe;
} PERM;

/* integer vector definition */
typedef struct{
  unsigned intdim, max_dim;
  int*ive;
} IVEC;


#ifndef MALLOCDECL
#ifndef ANSI_C
externchar*malloc(), *calloc(), *realloc();
#else
externvoid*malloc(size_t),
  *calloc(size_t,size_t),
  *realloc(void *,size_t);
#endif
#endif /* MALLOCDECL */

			/* For creating MEX files (for use with Matlab) using Meschach
			   See also: mexmesch.h */
#ifdef MEX
#include"mex.h"
#definemalloc(len)mxMalloc(len)
#definecalloc(n,len)mxCalloc(n,len)
#definerealloc(ptr,len)mxRealloc(ptr,len)
#definefree(ptr)mxFree(ptr)
#defineprintfmexPrintf
#ifndef THREADSAFE/* for use as a shared library */
#defineTHREADSAFE 1
#endif
#endif /* MEX */

#ifdef THREADSAFE
#defineSTATIC
#else
#defineSTATICstatic
#endif /* THREADSAFE */

#ifndef ANSI_C
			extern void m_version();
#else
			voidm_version( void );
#endif

#ifndef ANSI_C
			/* allocate one object of given type */
#defineNEW(type)((type *)calloc((size_t)1,sizeof(type)))

			/* allocate num objects of given type */
#defineNEW_A(num,type)((type *)calloc((size_t)(num),sizeof(type)))

			/* re-allocate arry to have num objects of the given type */
#defineRENEW(var,num,type) \
  ((var)=(type *)((var) ? \
		  realloc((char *)(var),(size_t)(num)*sizeof(type)) : \
		  calloc((size_t)(num),sizeof(type))))

#defineMEMCOPY(from,to,n_items,type) \
  MEM_COPY((char *)(from),(char *)(to),(size_t)(n_items)*sizeof(type))

#else
			/* allocate one object of given type */
#defineNEW(type)((type *)calloc((size_t)1,(size_t)sizeof(type)))

			/* allocate num objects of given type */
#defineNEW_A(num,type)((type *)calloc((size_t)(num),(size_t)sizeof(type)))

			/* re-allocate arry to have num objects of the given type */
#defineRENEW(var,num,type) \
  ((var)=(type *)((var) ? \
		  realloc((char *)(var),(size_t)((num)*sizeof(type))) : \
		  calloc((size_t)(num),(size_t)sizeof(type))))

#defineMEMCOPY(from,to,n_items,type) \
  MEM_COPY((char *)(from),(char *)(to),(unsigned)(n_items)*sizeof(type))

#endif /* ANSI_C */

			/* type independent min and max operations */
#ifndef max
#definemax(a,b)((a) > (b) ? (a) : (b))
#endif /* max */
#ifndef min
#definemin(a,b)((a) > (b) ? (b) : (a))
#endif /* min */


#undef TRUE
#defineTRUE1
#undef FALSE
#defineFALSE0


			/* for input routines */
#define MAXLINE 81


			/* Dynamic memory allocation */

			/* Should use M_FREE/V_FREE/PX_FREE in programs instead of m/v/px_free()
			   as this is considerably safer -- also provides a simple type check ! */

#ifndef ANSI_C

			externVEC *v_get(), *v_resize();
			externMAT *m_get(), *m_resize();
			externPERM *px_get(), *px_resize();
			externIVEC *iv_get(), *iv_resize();
			externint m_free(),v_free();
			extern  int px_free();
			extern  int iv_free();
			extern  BAND *bd_get(), *bd_resize();
			extern  int bd_free();

#else

			/* get/resize vector to given dimension */
			externVEC *v_get(int), *v_resize(VEC *,int);
			/* get/resize matrix to be m x n */
			externMAT *m_get(int,int), *m_resize(MAT *,int,int);
			/* get/resize permutation to have the given size */
			externPERM *px_get(int), *px_resize(PERM *,int);
			/* get/resize an integer vector to given dimension */
			externIVEC *iv_get(int), *iv_resize(IVEC *,int);
			/* get/resize a band matrix to given dimension */
			extern  BAND *bd_get(int,int,int), *bd_resize(BAND *,int,int,int);

			/* free (de-allocate) (band) matrices, vectors, permutations and 
			   integer vectors */
			extern  int iv_free(IVEC *);
			externm_free(MAT *),v_free(VEC *),px_free(PERM *);
			extern   int bd_free(BAND *);

#endif /* ANSI_C */


			/* MACROS */

			/* macros that also check types and sets pointers to NULL */
#defineM_FREE(mat)( m_free(mat),(mat)=(MAT *)NULL )
#define V_FREE(vec)( v_free(vec),(vec)=(VEC *)NULL )
#definePX_FREE(px)( px_free(px),(px)=(PERM *)NULL )
#defineIV_FREE(iv)( iv_free(iv),(iv)=(IVEC *)NULL )

#define MAXDIM  10000001


			/* Entry level access to data structures */
			/* routines to check indexes */
#definem_chk_idx(A,i,j)((i)>=0 && (i)<(A)->m && (j)>=0 && (j)<=(A)->n)
#definev_chk_idx(x,i)((i)>=0 && (i)<(x)->dim)
#definebd_chk_idx(A,i,j)((i)>=max(0,(j)-(A)->ub) && \
			 (j)>=max(0,(i)-(A)->lb) && (i)<(A)->mat->n && (j)<(A)->mat->n)

#definem_entry(A,i,j)m_get_val(A,i,j)
#definev_entry(x,i)v_get_val(x,i)
#definebd_entry(A,i,j)bd_get_val(A,i,j)
#ifdef DEBUG
#definem_set_val(A,i,j,val)( m_chk_idx(A,i,j) ? \
			     (A)->me[(i)][(j)] = (val) : (error(E_BOUNDS,"m_set_val"), 0.0))
#definem_add_val(A,i,j,val)( m_chk_idx(A,i,j) ? \
			     (A)->me[(i)][(j)] += (val) : (error(E_BOUNDS,"m_add_val"), 0.0))
#definem_sub_val(A,i,j,val)( m_chk_idx(A,i,j) ? \
			     (A)->me[(i)][(j)] -= (val) : (error(E_BOUNDS,"m_sub_val"), 0.0))
#definem_get_val(A,i,j)( m_chk_idx(A,i,j) ? \
			 (A)->me[(i)][(j)] : (error(E_BOUNDS,"m_get_val"), 0.0))
#definev_set_val(x,i,val)( v_chk_idx(x,i) ? (x)->ve[(i)] = (val) : \
			   (error(E_BOUNDS,"v_set_val"), 0.0))
#definev_add_val(x,i,val)( v_chk_idx(x,i) ? (x)->ve[(i)] += (val) : \
			   (error(E_BOUNDS,"v_set_val"), 0.0))
#definev_sub_val(x,i,val)( v_chk_idx(x,i) ? (x)->ve[(i)] -= (val) : \
			   (error(E_BOUNDS,"v_set_val"), 0.0))
#definev_get_val(x,i)( v_chk_idx(x,i) ? (x)->ve[(i)] : \
		       (error(E_BOUNDS,"v_get_val"), 0.0))
#definebd_set_val(A,i,j,val)( bd_chk_idx(A,i,j) ? \
			      (A)->mat->me[(A)->lb+(j)-(i)][(j)] = (val) : \
			      (error(E_BOUNDS,"bd_set_val"), 0.0))
#definebd_add_val(A,i,j,val)( bd_chk_idx(A,i,j) ? \
			      (A)->mat->me[(A)->lb+(j)-(i)][(j)] += (val) : \
			      (error(E_BOUNDS,"bd_set_val"), 0.0))
#definebd_get_val(A,i,j)( bd_chk_idx(A,i,j) ? \
			  (A)->mat->me[(A)->lb+(j)-(i)][(j)] : \
			  (error(E_BOUNDS,"bd_get_val"), 0.0))
#else /* no DEBUG */
#definem_set_val(A,i,j,val)((A)->me[(i)][(j)] = (val))
#definem_add_val(A,i,j,val)((A)->me[(i)][(j)] += (val))
#definem_sub_val(A,i,j,val)((A)->me[(i)][(j)] -= (val))
#definem_get_val(A,i,j)((A)->me[(i)][(j)])
#definev_set_val(x,i,val)((x)->ve[(i)] = (val))
#definev_add_val(x,i,val)((x)->ve[(i)] += (val))
#definev_sub_val(x,i,val)((x)->ve[(i)] -= (val))
#definev_get_val(x,i)((x)->ve[(i)])
#definebd_set_val(A,i,j,val)((A)->mat->me[(A)->lb+(j)-(i)][(j)] = (val))
#definebd_add_val(A,i,j,val)((A)->mat->me[(A)->lb+(j)-(i)][(j)] += (val))
#definebd_get_val(A,i,j)((A)->mat->me[(A)->lb+(j)-(i)][(j)])
#endif /* DEBUG */


			/* I/O routines */
#ifndef ANSI_C

			externvoid v_foutput(),m_foutput(),px_foutput();
			extern  void iv_foutput();
			externVEC *v_finput();
			externMAT *m_finput();
			externPERM *px_finput();
			externIVEC *iv_finput();
			externint fy_or_n(), fin_int(), yn_dflt(), skipjunk();
			externdouble fin_double();

#else

			/* print x on file fp */
			void v_foutput(FILE *fp,const VEC *x),
			/* print A on file fp */
  m_foutput(FILE *fp,const MAT *A),
			/* print px on file fp */
  px_foutput(FILE *fp,const PERM *px);
			/* print ix on file fp */
			void iv_foutput(FILE *fp,const IVEC *ix);

			/* Note: if out is NULL, then returned object is newly allocated;
			   Also: if out is not NULL, then that size is assumed */

			/* read in vector from fp */
			VEC *v_finput(FILE *fp,VEC *out);
			/* read in matrix from fp */
			MAT *m_finput(FILE permutation from fp */
				      PERM *px_finput(FILE *fp,PERM *out);
				      /* read in int vector from fp */
				      IVEC *iv_finput(FILE *fp,IVEC *out);

				      /* fy_or_n -- yes-or-no to question in string s
        -- question written to stderr, input from fp 
        -- if fp is NOT a tty then return y_n_dfl*s,double low,double high);

	/* it skips white spaces and strings of the form #....\n
	Here .... is a comment string */
				      int skipjunk(FILE *fp);

#endif /* ANSI_C */


				      /* MACROS */

				      /* macros to use stdout and in_int(s,lo,hi)fin_int(stdin,s,lo,hi)
					 #definein_double(s,lo,hi)fin_double(stdin,s,lo,hi)


					 /* special purpose access routines */

				      /* Copying routines */
#ifndef ANSI_C
				      externMAT*_m_copy(), *m_move(), *vm_move();
				      externVEC*_v_copy(), *v_move(), *mv_move();
				      externPERM*px_copy();
				      externIVEC*iv_copy(), *iv_move();
				      extern  BAND    *bd_copy();

#else

				      /* copy in to out stat);

					 #endif /* ANSI_C */


				      /* MACROS */
#definem_copy(in,out)_m_copy(in,out,0,0)
#definev_copy(in,out)_v_copy(in,out,0)


				      /* Initialisation routines -- to be zero, ones, random or identity */
#ifndef ANSI_C
				      externVEC     *v_zero(), *v_rand(), *v_ones();
				      externMAT      *m__();
#else

				      externVEC*sv_mlt(double s,const VEC *x,VEC *out),/* out <- s.x */
				      *mv_mlt(const MAT *A,const VEC *s,VEC *out),/* out <- A.x */
				      *vm_mlt(const MAT *A,const VEC *x,VEC *out),/* out^T <- x^T.A */
				      *v_add(const VEC *x,const VEC *y,VEC *out), /* out <- x + y */
				      *v_sub(const VEC *x,const VEC *y,VEC                          /* out <- sum_i s[i].x[i] */
					     *v_linlist(VEC *out,VEC *v1,double a1,...);
					     /* out <- s1.x1 + s2.x2 + ... */

					     /* returns min_j x[j] (== x[i]) */
					     externdoublev_min(const VEC *, int *), 
					     /* returns max_j onst Real *,double,int),
						__add__(const Real *,const Real *,Real *,int),
						__sub__(const Real *,const Real *,Real *,int),
                __smlt__(const Real *,double,Real *,int),
		__zero__(Real *,int);

		#endif /* ANSI_C */


					     /* MACRO */
					     /* usual way of computing tev_norm1(x)_v_norm1(x,VNULL)
						#definev_norm2(x)_v_norm2(x,VNULL)
						#definev_norm_inf(x)_v_norm_inf(x,VNULL)

						/* Basic matrix operations */
#ifndef ANSI_C

					     externMAT *sm_mlt(), *m_mlt(), *mmtr_mlt(), *mtrm_mlt(), *m_add(), *m_sub(),
					     *sub_mat(), nt,MAT *out),
				      *m_transp(const MAT *A,MAT *out),/* out <- A^T */
				      /* out <- A + s.B */ 
				      *ms_mltadd(const MAT *A,const MAT *B,double s,MAT *out);   


				      extern  BAND    *bd_transp(const BAND *in, BAND *out),/* out <- A^T */
				      *sbd_mlt(Real s, const B *),
				      /* mv_mltadd: out <- x + s.A.y */
				      *mv_mltadd(const VEC *x,const VEC *y,const MAT *A,
						 double s,VEC *out),
				      /* vm_mltadd: out^T <- x^T + s.y^T.A */
				      *vm_mltadd(const VEC roduct of even # transpositions
                           -1 if ps product of odd  # transpositions */
						 externintpx_sign(const PERM *);

#endif /* ANSI_C */


						 /* Basic len);       /* generates len random numbers */

						 void    m_dump(FILE *fp,const MAT *a), px_dump(FILE *fp, const PERM *px),
						 v_dump(FILE *fp,const VEC *x), iv_<varargs.h>

						 /* prototypes */

						 int v_get_vars();
						 int iv_get_vars();
						 int m_get_vars();
						 int px_get_vars();

						 int v_resize_vars();
						 int iv_resize_vars();
						 int m_resize_vars()
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


#endif


