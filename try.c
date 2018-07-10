//
// Created by 彭伟浩 on 2018/7/4.
//

#include <stdio.h>
#include <string.h>
#include "matrix_base.h"
#include "RowSim.h"
#include "matrix_dynamic.h"

int main(){
    matrix a;
    a.r=3;
    a.c=3;
    matrix b;
    double da[3][3]={{2.0,3.0,4.0},{5.0,6.0,7.0},{9.0,9.0,10.0}};
    double db[3][3]={{2.0,3.0,4.0},{5.0,6.0,7.0},{9.0,9.0,10.0}};
    b.r=3;
    b.c=3;
    b.data=db;
    eye(b);
    a.data=da;
    matrix c;
    c.r=c.c=3;
    c.data=malloc(9* sizeof(double));
    rowSim(a, b);
    matrixprint(a);
    matrixprint(b);
    multiMM(a,b,c);
    matrixprint(c);
    return 0;
}

