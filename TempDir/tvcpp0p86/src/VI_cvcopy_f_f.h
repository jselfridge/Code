/* Created RJudd August 8 */
/* SPAWARSYSCEN  */
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
/* $Id: VI_cvcopy_f_f.h,v 2.0 2003/02/22 15:18:31 judd Exp $ */

#ifndef VI_CVCOPY_F_F_H
#define VI_CVCOPY_F_F_H 1

#include<vsip.h>
#include<vsip_cvviewattributes_f.h>

static
void 
VI_cvcopy_f_f(
  const vsip_cvview_f* a,
  const vsip_cvview_f* r) {
  {
      vsip_length n =  r->length;
      vsip_stride cast = a->block->cstride,
                  crst = r->block->cstride;
      vsip_scalar_f *apr = (vsip_scalar_f *)((a->block->R->array) + cast * a->offset),
                    *rpr = (vsip_scalar_f *)((r->block->R->array) + crst * r->offset);
      vsip_scalar_f *api = (vsip_scalar_f *)((a->block->I->array) + cast * a->offset),
                    *rpi = (vsip_scalar_f *)((r->block->I->array) + crst * r->offset);
      vsip_stride ast = (cast * a->stride),
                  rst = (crst * r->stride);
      while(n-- > 0){
          *rpr = *apr;
          *rpi = *api;
          apr += ast; api += ast;
          rpr += rst; rpi += rst;
      }  
  }
  return;
}  
#endif
