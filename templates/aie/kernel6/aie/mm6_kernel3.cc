#include <adf.h>
#include <stdio.h>
#include "para_L{{layer}}.h"
void mm6_kernel3_L{{layer}}(input_window_int8* __restrict matA, 
        input_window_int8*  __restrict matB,
        output_window_int8* __restrict matC){

    v64int8 chess_storage(xa) buf_matA0=undef_v64int8();
    v64int8 chess_storage(xb) buf_matA1=undef_v64int8();
            
    v32int8 chess_storage(wc0) buf_matB0=undef_v32int8(); 
    v32int8 chess_storage(wc1) buf_matB1=undef_v32int8(); 
    

    buf_matA0=upd_w(buf_matA0,0,window_read_v32(matA));
    window_incr(matA,L{{layer}}_jumpA0);

    buf_matB0=window_read_v32(matB);
    window_incr(matB,L{{layer}}_jumpB0);

    buf_matA0=upd_w(buf_matA0,1,window_read_v32(matA));
    window_incr(matA,L{{layer}}_jumpA0);

    for (int i=0;i<L{{layer}}_boundary_i;i++)
    chess_prepare_for_pipelining
    chess_loop_range(L{{layer}}_boundary_i,)
    {
        for (int j=0;j<L{{layer}}_boundary_j;j++)
        chess_prepare_for_pipelining
        chess_loop_range(L{{layer}}_boundary_j,)
        {

            int jumpA=L{{layer}}_jumpA1;
            int jumpB=L{{layer}}_jumpB2;
            if(j==L{{layer}}_judge_j){
                jumpA=L{{layer}}_jumpA0;
                jumpB=L{{layer}}_jumpB0;
            }

            v16acc48  acc0=null_v16acc48();
            v16acc48  acc1=null_v16acc48();      

            //K iteration 0
            acc0=mac16(acc0,buf_matA0,0,0x11101110,16,0x3120,buf_matB0,0,0x88880000,2,0x3210);
            buf_matA1=upd_w(buf_matA1,0,window_read_v32(matA));
            window_incr(matA,L{{layer}}_jumpA0);
            buf_matB1=window_read_v32(matB);
            window_incr(matB,L{{layer}}_jumpB1);

            acc1=mac16(acc1,buf_matA0,0,0x11101110,16,0x3120,buf_matB1,0,0x88880000,2,0x3210);
            buf_matA1=upd_w(buf_matA1,1,window_read_v32(matA));
            window_incr(matA,L{{layer}}_jumpA0);

            acc0=mac16(acc0,buf_matA1,0,0x11101110,16,0x3120,buf_matB0,0,0xCCCC4444,2,0x3210);
            buf_matA0=upd_w(buf_matA0,0,window_read_v32(matA));
            window_incr(matA,L{{layer}}_jumpA0);

            acc1=mac16(acc1,buf_matA1,0,0x11101110,16,0x3120,buf_matB1,0,0xCCCC4444,2,0x3210);
            buf_matA0=upd_w(buf_matA0,1,window_read_v32(matA));
            window_incr(matA,L{{layer}}_jumpA0);
            buf_matB0=window_read_v32(matB); 
            window_incr(matB,L{{layer}}_jumpB0);

            //K iteration 1
            acc0=mac16(acc0,buf_matA0,0,0x11101110,16,0x3120,buf_matB0,0,0x88880000,2,0x3210);
            buf_matA1=upd_w(buf_matA1,0,window_read_v32(matA));
            window_incr(matA,L{{layer}}_jumpA0);
            buf_matB1=window_read_v32(matB);
            window_incr(matB,L{{layer}}_jumpB1);

            acc1=mac16(acc1,buf_matA0,0,0x11101110,16,0x3120,buf_matB1,0,0x88880000,2,0x3210);
            buf_matA1=upd_w(buf_matA1,1,window_read_v32(matA));
            window_incr(matA,L{{layer}}_jumpA0);

            acc0=mac16(acc0,buf_matA1,0,0x11101110,16,0x3120,buf_matB0,0,0xCCCC4444,2,0x3210);
            buf_matA0=upd_w(buf_matA0,0,window_read_v32(matA));
            window_incr(matA,L{{layer}}_jumpA0);

            acc1=mac16(acc1,buf_matA1,0,0x11101110,16,0x3120,buf_matB1,0,0xCCCC4444,2,0x3210);
            buf_matA0=upd_w(buf_matA0,1,window_read_v32(matA));
            window_incr(matA,L{{layer}}_jumpA0);
            buf_matB0=window_read_v32(matB); 
            window_incr(matB,L{{layer}}_jumpB0);

            //K iteration 2
            acc0=mac16(acc0,buf_matA0,0,0x11101110,16,0x3120,buf_matB0,0,0x88880000,2,0x3210);
            buf_matA1=upd_w(buf_matA1,0,window_read_v32(matA));
            window_incr(matA,L{{layer}}_jumpA0);
            buf_matB1=window_read_v32(matB);
            window_incr(matB,L{{layer}}_jumpB1);

            acc1=mac16(acc1,buf_matA0,0,0x11101110,16,0x3120,buf_matB1,0,0x88880000,2,0x3210);
            buf_matA1=upd_w(buf_matA1,1,window_read_v32(matA));
            window_incr(matA,L{{layer}}_jumpA0);

            acc0=mac16(acc0,buf_matA1,0,0x11101110,16,0x3120,buf_matB0,0,0xCCCC4444,2,0x3210);
            buf_matA0=upd_w(buf_matA0,0,window_read_v32(matA));
            window_incr(matA,L{{layer}}_jumpA0);

            acc1=mac16(acc1,buf_matA1,0,0x11101110,16,0x3120,buf_matB1,0,0xCCCC4444,2,0x3210);
            buf_matA0=upd_w(buf_matA0,1,window_read_v32(matA));
            window_incr(matA,L{{layer}}_jumpA0);
            buf_matB0=window_read_v32(matB); 
            window_incr(matB,L{{layer}}_jumpB0);

            //K iteration 3
            acc0=mac16(acc0,buf_matA0,0,0x11101110,16,0x3120,buf_matB0,0,0x88880000,2,0x3210);
            buf_matA1=upd_w(buf_matA1,0,window_read_v32(matA));
            window_incr(matA,L{{layer}}_jumpA0);
            buf_matB1=window_read_v32(matB);
            window_incr(matB,jumpB);

            acc1=mac16(acc1,buf_matA0,0,0x11101110,16,0x3120,buf_matB1,0,0x88880000,2,0x3210);
            buf_matA1=upd_w(buf_matA1,1,window_read_v32(matA));
            window_incr(matA,jumpA);//jump

            acc0=mac16(acc0,buf_matA1,0,0x11101110,16,0x3120,buf_matB0,0,0xCCCC4444,2,0x3210);
            buf_matA0=upd_w(buf_matA0,0,window_read_v32(matA));
            window_incr(matA,L{{layer}}_jumpA0);
            window_write(matC,bsrs(acc0,0));
            window_incr(matC,16);

            acc1=mac16(acc1,buf_matA1,0,0x11101110,16,0x3120,buf_matB1,0,0xCCCC4444,2,0x3210);
            buf_matA0=upd_w(buf_matA0,1,window_read_v32(matA));
            window_incr(matA,L{{layer}}_jumpA0);
            buf_matB0=window_read_v32(matB); 
            window_incr(matB,L{{layer}}_jumpB0);
            window_write(matC,bsrs(acc1,0));
            window_incr(matC,16);
            
        }
    }

}