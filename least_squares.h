//
// Created by 彭伟浩 on 2018/7/9.
//

#ifndef PROJECT_LEAST_SQUARES_H
#define PROJECT_LEAST_SQUARES_H

#include "matrix_base.h"
#include <math.h>
#include <stdlib.h>

//x是一组数,n是x的数量，times是x的最高次幂
//未测试。。。
void vandermonde_matrix(double *x,int n,int times,matrix result){

    result.r=n;
    result.c=times+1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= times+1; ++j) {
            dex(result,i,j)=pow(x[i],j);
        }
    }
}

//未测试
void d_ATtimesA(matrix A){
    matrix result;
    result.c=result.r=A.c;
    result.data=Mmalloc(A.r,A.r);

    for (int i = 0; i < A.c; ++i) {
        for (int j = i; j < A.c; ++j) {
            dex(result,i,j)=0;
            for (int k = 0; k < A.r; ++k) {
                dex(result,i,j)+=dex(A,k,i)*dex(A,k,j);
            }
            dex(result,j,i)=dex(result,i,j);
        }
    }
    return result;
}


void leastSquare_RowSim(matrix A,matrix b,matrix x){
    matrix ATA=d_ATtimesA(A);

}


#endif //PROJECT_LEASTSQUARE_H
