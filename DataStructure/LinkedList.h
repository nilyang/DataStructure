#pragma once
#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

#include<memory>

template<typename ElementType>
struct ListNode
{
    using element_t = ElementType;

    element_t Data;
    struct ListNode<element_t> *next;

    ListNode(element_t data=0) :next(nullptr),Data(data){}
};

// 头节点别名
template<typename T>
using ListHead = ListNode<T>;

// 创建空链表
template<typename T>
ListHead<T>* MakeEmptyList();


// 在P元素后面插入数据X
template<typename T>
bool Insert(ListHead<T>* L, const T & X, ListNode<T> *P);

// 末尾插入数据
template<typename T>
bool Insert(ListHead<T>* L, const T & X);

// 删除指定元素
template<typename T>
bool Delete(ListHead<T>* L, ListNode<T>* P);

// 销毁链表
template<typename T>
bool DestroyList(ListHead<T> * L);

// ------ 实现代码 ---------//

template<typename T>
inline ListHead<T>* MakeEmptyList()
{
    return new ListHead<T>();
}

template<typename T>
bool Insert(ListHead<T>* L, const T & X, ListNode<T> *P)
{
    if (L == nullptr)
        return false;

    ListNode<T> *pre, *xNode;

    int i = 0;

    // 查找P的前置节点
    for (pre = L; pre != nullptr && pre->next != P; pre = pre->next);

    // 查完整个链表没找到
    if (pre == nullptr) {
        // 找到末尾
        if (P == nullptr) {
            xNode = new ListNode<T>();
            xNode->Data = X;
            pre->next = xNode;
        }
        else {
            return false;
        }
    }
    else {
        xNode = new ListNode<T>();
        xNode->Data = X;
        xNode->next = P;
        pre->next = xNode;
    }

    return true;
}

template<typename T>
bool Insert(ListHead<T>* L, const T & X)
{
    return Insert<T>(L, X, nullptr);
}


template<typename T>
bool Delete(ListHead<T>* L, ListNode<T>* P)
{
    ListNode<T> *pNode = L;

    while (pNode != nullptr && pNode != P) {
        pNode = pNode->next;
    }

    if (pNode == nullptr)
        return false;

    pNode->next = P->next;

    delete P;

    return false;
}

template<typename T>
bool DestroyList(ListHead<T>* L)
{
    ListNode<T> *tmpNode;
    if (L == nullptr)
        return false;

    for (; L->next != nullptr;) {
        tmpNode = L->next;
        L->next = L->next->next;
        delete tmpNode;
    }

    delete L;
    return true;
}

#endif // !__LINKED_LIST_H
