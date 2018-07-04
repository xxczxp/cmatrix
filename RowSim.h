//
// Created by 彭伟浩 on 2018/7/4.
//

#ifndef PROJECT_ROWSIM_H
#define PROJECT_ROWSIM_H

#include "matrix_base.h"

void rowAdd(matrix m,int target,int source,int n,int start){  //将source行乘上n加到target行，从start一直计算到结束
    for (int i = start; i < m.c; ++i) {
        dex(m,target,i)+=n*dex(m,source,i);
    }

}

void rowChange(matrix m,int target,int n, int start){
    for (int i = start; i < m.c; ++i) {
        dex(m,target,i)*=n;
    }
}



#endif //PROJECT_ROWSIM_H
