#include "LinkedList.h"

template<typename T, typename Node = ListNode<T>>
LinkedList<T>& MakeEmptyList()
{
    LinkedList<T> L = std::make_shared<Node>();
    L->next = nullptr;
    return L;
}

//
//template<typename T, typename Node = ListNode<T>>
//bool Insert(LinkedList<T>& L, const Node::element_t & X, Node & P)
//{
//    if (L == nullptr)
//        return false;
//    Node *pre=L->next;
//    // ����P��ǰ�ýڵ�
//    while (pre!=nullptr && pre->next != &P)
//    {
//        pre = pre->next;
//    }
//    
//    if (pre == nullptr && pre->next!= &P)
//        return false; // ����L�в�����P���
//
//    Node xNode = new Node();
//    xNode->Data = X;
//    xNode->next = P.next;
//    P.next = xNode;
//    pre->next = xNode;
//    return true;
//}
//
//template<typename T, typename Node = ListNode<T>>
//bool Insert(LinkedList<T> & L,const Node::element_t & X)
//{
//    if (!L) return false;
//    return Insert<T>(L, X, *(L->next));
//}
//
//template<typename T, typename Node = ListNode<T>>
//bool Delete(LinkedList<T> & L, Node & X)
//{
//    if (L == nullptr)
//        return false;
//    Node *pre = L->next;
//    while (pre != nullptr && pre->next != &X)
//        pre = pre->next;
//
//    if (pre == nullptr)
//        return false; // ���������û�ҵ�
//
//    pre->next = X.next;
//    
//    delete &X;
//    
//    return false;
//}
