/* Created RJudd September 16, 2000 */
/* SPAWARSYSCEN D857                */
/**********************************************************************
// For TASP VSIPL Documentation and Code neither the United States    /
// Government, the United States Navy, nor any of their employees,    /
// makes any warranty, express or implied, including the warranties   /
// of merchantability and fitness for a particular purpose, or        /
// assumes any legal liability or responsibility for the accuracy,    /
// completeness, or usefulness of any information, apparatus,         /
// product, or process disclosed, or represents that its use would    /
// not infringe privately owned rights                                /
**********************************************************************/
/* $Id: VI_cblockdestroy_d.h,v 2.0 2003/02/22 15:18:28 judd Exp $ */

#include<vsip.h>
#include<vsip_cblockattributes_d.h>

#ifndef VI_CBLOCKDESTROY_D_H
#define VI_CBLOCKDESTROY_D_H

static
void 
VI_cblockdestroy_d(
   vsip_cblock_d* b) {
   #if defined(VSIP_DEFAULT_SPLIT)
      #include"VI_cblockdestroy_d_ds.h"
   #elif defined(VSIP_ALWAYS_SPLIT)
      #include"VI_cblockdestroy_d_as.h"
   #elif defined(VSIP_ALWAYS_INTERLEAVED)
      #include"VI_cblockdestroy_d_ai.h"
   #else
      #include"VI_cblockdestroy_d_di.h"
   #endif
   return;
}
#endif
