//
// Created by 彭伟浩 on 2018/7/6.
//

#ifndef PROJECT_MATRIX_DYNAMIC_H
#define PROJECT_MATRIX_DYNAMIC_H

#include <stdlib.h>
#include "RowSim.h"


matrix d_eye(int a){
    matrix m;
    m.c=a;
    m.r=a;
    m.data=malloc(a*a*sizeof(double));
    eye(m);
    return m;
}





#endif //PROJECT_MATRIX_DYNAMIC_H
