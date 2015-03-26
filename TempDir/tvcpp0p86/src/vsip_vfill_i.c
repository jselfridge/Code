/* Created RJudd January 3, 1998 */
/* SPAWARSYSCEN */
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
/* $Id: vsip_vfill_i.c,v 2.0 2003/02/22 15:19:13 judd Exp $ */
/* Modified to vsip_vfill_i.c RJudd March 19, 1998 */
/* Removed Tisdale error checking Sept 00 */

#include<vsip.h>
#include<vsip_vviewattributes_i.h>

void (vsip_vfill_i)(vsip_scalar_i alpha,
  const vsip_vview_i* r) {
  { 
     /*define variables*/
      vsip_length   n = r->length;
      vsip_stride rst = r->stride;
      vsip_scalar_i *rp = (r->block->array) + r->offset;
      /*end define*/
      while(n-- > 0){
           *rp  = alpha;
            rp += rst;
      }
   }
}
