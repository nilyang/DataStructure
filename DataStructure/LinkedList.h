#pragma once
#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

#include<memory>

template<typename ElementType>
struct ListNode
{
    typedef typename ElementType element_t;
    element_t Data;
    struct ListNode<ElementType> *next;
};
template<typename T>
using LinkedList = std::shared_ptr<ListNode<T>>;

// 创建空链表
template<typename T, typename Node = ListNode<T>>
LinkedList<T>& MakeEmptyList();

//// 在P元素后面插入数据X
//template<typename T,typename Node=ListNode<T>>
//bool Insert(LinkedList<T> &L, Node::element_t& X, const Node& P);
//
//// 在链表后面插入数据
//template<typename T, typename Node = ListNode<T>>
//bool Insert(LinkedList<T> &L, Node::element_t& X);
//
//// 删除指定元素
//template<typename T, typename Node = ListNode<T>>
//bool Delete(LinkedList<T> &L, Node& P);

#endif // !__LINKED_LIST_H
