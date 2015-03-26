/* Created RJudd */
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
/* $Id: vsip_tputzlength_uc.c,v 2.0 2003/02/22 15:19:08 judd Exp $ */
#include"VI_support_priv_uc.h"

vsip_tview_uc* (vsip_tputzlength_uc)(
  vsip_tview_uc *v,
  vsip_length n) {
    v->z_length = n;
    return v;
}
