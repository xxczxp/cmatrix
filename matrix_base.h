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
#include <stdlib.h>

#define dex(matrix, a, b) matrix.data[a*matrix.c+b]
#define Mmalloc(a,b) malloc(a*b*sizeof(double))

typedef struct {
    int r;
    int c;
    double *data;
} matrix;





void multiMM(matrix a, matrix b, matrix result) {

    if(a.c != b.r){
        fprintf(stderr,"矩阵一的行和矩阵二的列不相等,无法相乘");
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

matrix d_eye(int a){
    matrix m;
    m.c=a;
    m.r=a;
    m.data=malloc(a*a*sizeof(double));
    eye(m);
    return m;
}

void matrixprint(matrix m){
    for (int i = 0; i < m.r; ++i) {
        for (int j = 0; j < m.c; ++j) {
            printf("%7.3f",dex(m,i,j));
        }
        printf("\n");
    }
}

void joinRowMatrix(matrix a,matrix b,matrix result){
    if(a.r != b.r){
        fprintf(stderr,"矩阵一的行和矩阵二的行不相等,无法进行拼接");
        return;
    }

    int j;

    for (int i = 0; i < a.r; ++i) {
        for (j = 0; j < a.c; ++j) {
            dex(result,i,j)=dex(a,i,j);
        }

        for ( ; j < b.c; ++j) {
            dex(result,i,j)=dex(b,i,j-a.c);
        }
    }

}


#endif //MATRIX_MATRIX_H
