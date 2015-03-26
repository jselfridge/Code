/* Created by RJudd */
/* SPAWARSYSCEN D857 */
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

/* $Id: cfir_N201_D3_d.h,v 2.0 2003/02/22 15:23:11 judd Exp $ */
static void cfir_N201_D3_d(){
   printf("********\nTEST cfir_N201_D3_d\n");
   {
      vsip_length N = 201;
      vsip_length D = 3;
      vsip_length n = 0;
      vsip_length L = 0;
      vsip_scalar_d k_data_r[]  = {
              1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
      vsip_scalar_d k_data_i[]  = {
              1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
      vsip_scalar_d in_data_r[] = {0.0,
              0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
      vsip_scalar_d in_data_i[] = {0.0,
              0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
      vsip_scalar_d ans_data_r[] = {0.0,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
      vsip_scalar_d ans_data_i[] = {0.0,
              0.1*2, 0.2*2, 0.3*2, 0.4*2, 0.5*2, 0.6*2, 0.7*2, 0.8*2, 0.9*2, 1.0*2,
              0.9*2, 0.8*2, 0.7*2, 0.6*2, 0.5*2, 0.4*2, 0.3*2, 0.2*2, 0.1*2, 0.0*2,
              0.1*2, 0.2*2, 0.3*2, 0.4*2, 0.5*2, 0.6*2, 0.7*2, 0.8*2, 0.9*2, 1.0*2,
              0.9*2, 0.8*2, 0.7*2, 0.6*2, 0.5*2, 0.4*2, 0.3*2, 0.2*2, 0.1*2, 0.0*2,
              0.1*2, 0.2*2, 0.3*2, 0.4*2, 0.5*2, 0.6*2, 0.7*2, 0.8*2, 0.9*2, 1.0*2,
              0.9*2, 0.8*2, 0.7*2, 0.6*2, 0.5*2, 0.4*2, 0.3*2, 0.2*2, 0.1*2, 0.0*2,
              0.1*2, 0.2*2, 0.3*2, 0.4*2, 0.5*2, 0.6*2, 0.7*2, 0.8*2, 0.9*2, 1.0*2,
              0.9*2, 0.8*2, 0.7*2, 0.6*2, 0.5*2, 0.4*2, 0.3*2, 0.2*2, 0.1*2, 0.0*2,
              0.1*2, 0.2*2, 0.3*2, 0.4*2, 0.5*2, 0.6*2, 0.7*2, 0.8*2, 0.9*2, 1.0*2,
              0.9*2, 0.8*2, 0.7*2, 0.6*2, 0.5*2, 0.4*2, 0.3*2, 0.2*2, 0.1*2, 0.0*2,
              0.1*2, 0.2*2, 0.3*2, 0.4*2, 0.5*2, 0.6*2, 0.7*2, 0.8*2, 0.9*2, 1.0*2,
              0.9*2, 0.8*2, 0.7*2, 0.6*2, 0.5*2, 0.4*2, 0.3*2, 0.2*2, 0.1*2, 0.0*2,
              0.1*2, 0.2*2, 0.3*2, 0.4*2, 0.5*2, 0.6*2, 0.7*2, 0.8*2, 0.9*2, 1.0*2,
              0.9*2, 0.8*2, 0.7*2, 0.6*2, 0.5*2, 0.4*2, 0.3*2, 0.2*2, 0.1*2, 0.0*2,
              0.1*2, 0.2*2, 0.3*2, 0.4*2, 0.5*2, 0.6*2, 0.7*2, 0.8*2, 0.9*2, 1.0*2,
              0.9*2, 0.8*2, 0.7*2, 0.6*2, 0.5*2, 0.4*2, 0.3*2, 0.2*2, 0.1*2, 0.0*2,
              0.1*2, 0.2*2, 0.3*2, 0.4*2, 0.5*2, 0.6*2, 0.7*2, 0.8*2, 0.9*2, 1.0*2,
              0.9*2, 0.8*2, 0.7*2, 0.6*2, 0.5*2, 0.4*2, 0.3*2, 0.2*2, 0.1*2, 0.0*2,
              0.1*2, 0.2*2, 0.3*2, 0.4*2, 0.5*2, 0.6*2, 0.7*2, 0.8*2, 0.9*2, 1.0*2,
              0.9*2, 0.8*2, 0.7*2, 0.6*2, 0.5*2, 0.4*2, 0.3*2, 0.2*2, 0.1*2, 0.0*2};
       vsip_cblock_d *k_block = vsip_cblockbind_d(k_data_r,k_data_i,10,VSIP_MEM_NONE);
       vsip_cblock_d *in_block = vsip_cblockbind_d(in_data_r,in_data_i,201,VSIP_MEM_NONE);
       vsip_cblock_d *ans_block = vsip_cblockbind_d(ans_data_r,ans_data_i,201,VSIP_MEM_NONE);
       vsip_cblock_d *out_block = vsip_cblockcreate_d(201,VSIP_MEM_NONE);
       vsip_cvview_d *k = vsip_cvbind_d(k_block,0,1,10);
       vsip_cvview_d *in = vsip_cvbind_d(in_block,0,1,201);
       vsip_cvview_d *ans = vsip_cvbind_d(ans_block,0,1,201);
       vsip_cvview_d *out = vsip_cvbind_d(out_block,0,1,201);
       vsip_cfir_d *fir;
       vsip_cblockadmit_d(k_block,VSIP_TRUE);
       vsip_cblockadmit_d(in_block,VSIP_TRUE);

       vsip_cblockadmit_d(ans_block,VSIP_TRUE);
       { L = N/D;
         if(N%D) L+=1;
         vsip_cvputlength_d(ans,L);
         vsip_cvputlength_d(out,L);
         vsip_cvputstride_d(ans,D);
         vsip_cvputstride_d(out,D);
       }
       fir = vsip_cfir_create_d(
                       k, /* kernel */
             VSIP_NONSYM, /* lets use the whole thing */
                       N, /* length input */
                       D, /* decimation */
         VSIP_STATE_SAVE, /* save state */
                       0,
                       0);
       n = vsip_cfirflt_d(fir,in,out);
       printf("N = %d\nD = %d\n",N,D);
       printf("fir = vsip_cfir_create_d( k,\n VSIP_NONSYM,\n N,\n D,\n VSIP_STATE_SAVE,\n 0,\n 0)\n");
       printf("n = vsip_cfirflt_d(fir,in,out)\n");
       printf("n = %d",n);
       if(n == L)
           printf(" ;correct\n");
       else
           printf(" ;error\n");
       printf("kernel\n");VU_cvprintm_d("3.2",k);
       printf("input\n"); VU_cvprintm_d("3.2",in);
       printf("output\n"); VU_cvprintm_d("3.2",out);
       printf("right output\n"); VU_cvprintm_d("3.2",ans);
       { vsip_cvview_d *chk = vsip_cvcreate_d(n,VSIP_MEM_NONE);
         vsip_vview_d *chk_r = vsip_vrealview_d(chk);
         vsip_cvsub_d(ans,out,chk); vsip_cvmag_d(chk,chk_r); vsip_vclip_d(chk_r,.0001,.0001,0,1,chk_r);
         if(vsip_vsumval_d(chk_r) > .5)
             printf("error\n");
         else
             printf("correct\n");
         vsip_vdestroy_d(chk_r);
         vsip_cvalldestroy_d(chk);
       }
       vsip_cfir_destroy_d(fir);
       vsip_cvalldestroy_d(k);
       vsip_cvalldestroy_d(in);
       vsip_cvalldestroy_d(out);
       vsip_cvalldestroy_d(ans);
   }
   return;
}
