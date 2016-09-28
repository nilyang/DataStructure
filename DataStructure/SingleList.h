
#pragma once

#ifndef __SINGLE_LIST_H
#define __SINGLE_LIST_H

//多项式结点
struct PolyNode
{
    int coef; // coefficient 系数
    int expon;// exponatial 指数
    struct PolyNode *next;
};

//多项式头
typedef struct PolyNode *Polynomial; 


#endif // !__SINGLE_LIST_H
