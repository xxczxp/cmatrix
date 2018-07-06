//
// Created by 彭伟浩 on 2018/7/1.
/*
 *
 *
 *
 *
 * */
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <stdio.h>
#include <math.h>
#include <string.h>

#define dex(matrix, a, b) matrix.data[a*matrix.c+b]

typedef struct {
    int r;
    int c;
    double *data;
} matrix;

typedef double *vector;

double lndex(matrix m, int a, int b) {
    return m.data[m.c * a + b];
}

void multiMM(matrix a, matrix b, matrix result) {

    if(a.c != b.r){
        fprintf(stderr,"矩阵一的行和矩阵二的列不相等");
        return;
    }
    double sum = 0;
    result.r = a.r;
    result.c = b.c;
    int n = a.c;

    for (int i = 0; i < b.c; ++i) {       //遍历b的列
        for (int j = 0; j < a.r; ++j) {     //遍历a的行
            for (int k = 0; k < n; ++k) {
                sum=sum+dex(a,j,k)*dex(b,k,i);
            }
            dex(result,j,i)=sum;
            sum=0;
        }
    }
}

void eye(matrix m){     //单位矩阵
    for (int i = 0; i < m.r; ++i) {
        for (int j = 0; j < m.c; ++j) {
            if(i == j)
                dex(m,i,j)=1;
            else
                dex(m,i,j)=0;
        }
    }
}

void matrixprint(matrix m){
    for (int i = 0; i < m.r; ++i) {
        for (int j = 0; j < m.c; ++j) {
            printf("%7.3f",dex(m,i,j));
        }
        printf("\n");
    }
}



#endif //MATRIX_MATRIX_H
