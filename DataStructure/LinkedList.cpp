#include "LinkedList.h"

// 带模板编译有问题:(LNK2019: https://msdn.microsoft.com/query/dev14.query?appId=Dev14IDEF1&l=ZH-CN&k=k(C4172)&rd=true )，
// 模板都放头文件了
// 无法解析的外部符号"...，该符号在main()中被引用"，不知道是不是没有引入编译结果的原因

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
//    // 查找P的前置节点
//    for (pre = L; pre != nullptr && pre->next != P; pre = pre->next);
//
//    // 查完整个链表没找到
//    if (pre == nullptr) {
//        // 找到末尾
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
