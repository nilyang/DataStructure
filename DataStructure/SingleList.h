
#pragma once

#ifndef __SINGLE_LIST_H
#define __SINGLE_LIST_H

//����ʽ���
struct PolyNode
{
    int coef; // coefficient ϵ��
    int expon;// exponatial ָ��
    struct PolyNode *next;
};

//����ʽͷ
typedef struct PolyNode *Polynomial; 


#endif // !__SINGLE_LIST_H
