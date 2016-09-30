#include "LinkedList.h"

// ��ģ�����������:(LNK2019: https://msdn.microsoft.com/query/dev14.query?appId=Dev14IDEF1&l=ZH-CN&k=k(C4172)&rd=true )��
// ģ�嶼��ͷ�ļ���
// �޷��������ⲿ����"...���÷�����main()�б�����"����֪���ǲ���û�������������ԭ��

//
//template<typename T>
//inline ListHead<T>* MakeEmptyList()
//{
//    return new ListHead<T>();
//}
//
//template<typename T>
//bool Insert(ListHead<T>* L, const T & X, ListNode<T> *P)
//{
//    if (L == nullptr)
//        return false;
//
//    ListNode<T> *pre, *xNode;
//
//    int i = 0;
//
//    // ����P��ǰ�ýڵ�
//    for (pre = L; pre != nullptr && pre->next != P; pre = pre->next);
//
//    // ������������û�ҵ�
//    if (pre == nullptr) {
//        // �ҵ�ĩβ
//        if (P == nullptr) {
//            xNode = new ListNode<T>();
//            xNode->Data = X;
//            pre->next = xNode;
//        }
//        else {
//            return false;
//        }
//    }
//    else {
//        xNode = new ListNode<T>();
//        xNode->Data = X;
//        xNode->next = P;
//        pre->next = xNode;
//    }
//
//    return true;
//}
//
//template<typename T>
//bool Insert(ListHead<T>* L, const T & X)
//{
//    return Insert(L, X, nullptr);
//}
//
//
//template<typename T>
//bool Delete(ListHead<T>* L, ListNode<T>* P)
//{
//    ListNode<T> *pNode = L;
//
//    while (pNode != nullptr && pNode != P) {
//        pNode = pNode->next;
//    }
//
//    if (pNode == nullptr)
//        return false;
//
//    pNode->next = P->next;
//
//    delete P;
//
//    return false;
//}
//
//template<typename T>
//bool DestroyList(ListHead<T>* L)
//{
//    ListNode<T> *tmpNode;
//    if (L == nullptr)
//        return false;
//
//    for (; L->next != nullptr;) {
//        tmpNode = L->next;
//        L->next = L->next->next;
//        delete tmpNode;
//    }
//
//    delete L;
//    return true;
//}
