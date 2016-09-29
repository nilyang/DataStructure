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

// ����������
template<typename T, typename Node = ListNode<T>>
LinkedList<T>& MakeEmptyList();

//// ��PԪ�غ����������X
//template<typename T,typename Node=ListNode<T>>
//bool Insert(LinkedList<T> &L, Node::element_t& X, const Node& P);
//
//// ����������������
//template<typename T, typename Node = ListNode<T>>
//bool Insert(LinkedList<T> &L, Node::element_t& X);
//
//// ɾ��ָ��Ԫ��
//template<typename T, typename Node = ListNode<T>>
//bool Delete(LinkedList<T> &L, Node& P);

#endif // !__LINKED_LIST_H
