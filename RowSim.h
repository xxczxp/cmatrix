//
// Created by 彭伟浩 on 2018/7/4.
//

#ifndef PROJECT_ROWSIM_H
#define PROJECT_ROWSIM_H

#include <stdlib.h>
#include "matrix_base.h"

void rowAdd(matrix m, int target, int source, double n, int start) {  //将source行乘上n加到target行，从start一直计算到结束
    for (int i = start; i < m.c; ++i) {
        dex(m, target, i) += n * dex(m, source, i);
    }

}

void rowMuti(matrix m, int target, double n, int start) {
    for (int i = start; i < m.c; ++i) {
        dex(m, target, i) *= n;
    }
}

void rowChange(matrix m, int target, int source, int start) {
    double temp;
    for (int i = start; i < m.c; ++i) {
        temp = dex(m, target, i);
        dex(m, target, i) = dex(m, source, i);
        dex(m, source, i) = temp;
    }
}

void SimLU_U(matrix A, matrix LB) {   //A化简为最简阶梯矩阵，LB与其同步
    if(A.r!=LB.r){
        fprintf(stderr,"矩阵一的行数和矩阵二的行数不相等");
    }

    int *maindex = malloc(sizeof(int)*A.r);
    int cl = 0;
    int i,j;
    double temp;

    for (i = 0; i < A.r; ) {
        

        if(cl>=A.c){
            break;
        }

        //主元不能为零
        if(dex(A,i,cl)==0)
            for (j = i+1; j < A.r; ++j) {
                if(dex(A,j,cl) != 0) {
                    rowChange(A,i,j,cl);
                    rowChange(LB,i,j,0);
                }
            };
        
        //如果这列全是零
        if(j>=A.r){
            ++cl;
            continue;
        }
        
        maindex[i]=cl;

        //主元归一
        temp=1.0/dex(A,i,cl);
        rowMuti(A,i,temp,cl);
        rowMuti(LB,i,temp,0);

        //主元下方都归零
        for (int k = i+1; k < A.r; ++k) {
            if(dex(A,k,cl) != 0){
                temp=-dex(A,k,cl);
                rowAdd(A,k,i,temp,cl);
                rowAdd(LB,k,i,temp,0);
            }
        }

        cl++;
        i++;
    }

    for (i = i-1; i > 0; --i) {
        for (j = 0; j < i; ++j) {
            if(dex(A,j,maindex[i]) != 0){
                temp=-dex(A,j,maindex[i]);
                rowAdd(A,j,i,temp,maindex[i]);
                rowAdd(LB,j,i,temp,0);
            }
        }
    }
    
}

//如果矩阵不可逆则返回零，可逆返回1
int reverseMatrix(matrix A,matrix LB){
    if(A.r!=A.c) {
        printf( "矩阵不可逆");
        return 0;
    }
    int i,j;
    double temp;

    for (i = 0; i < A.r;i++) {




        //主元不能为零
        if(dex(A,i,i)==0)
            for (j = i+1; j < A.r; ++j) {
                if(dex(A,j,i) != 0) {
                    rowChange(A,i,j,i);
                    rowChange(LB,i,j,0);
                }
            };

        //如果这列全是零
        if(j>=A.r){
            printf("矩阵不可逆");
            return 0;
        }

        //主元归一
        temp=1.0/dex(A,i,i);
        rowMuti(A,i,temp,i);
        rowMuti(LB,i,temp,0);

        //主元下方都归零
        for (int k = i+1; k < A.r; ++k) {
            if(dex(A,k,i) != 0){
                temp=-dex(A,k,i);
                rowAdd(A,k,i,temp,i);
                rowAdd(LB,k,i,temp,0);
            }
        }
    }

    //上三角化为单位阵
    for (i = i-1; i > 0; --i) {
        for (j = 0; j < i; ++j) {
            if(dex(A,j,i) != 0){
                rowAdd(LB,j,i,-dex(A,j,i),0);
            }
        }
    }
    return 1;

}



#endif //PROJECT_ROWSIM_H
