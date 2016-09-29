#pragma once
#ifndef __LIST_H
#define __LIST_H

// ˳���

#include<memory>


const int MAX_SIZE = 100;
const int LIST_ERROR = -1;

template<typename ElementTtype,typename PositionType>
struct LNode
{
    typedef ElementTtype element_t;
    typedef PositionType position_t;
    element_t Data[MAX_SIZE];
    PositionType Last;
};

template<typename ElementTtype, typename PositionType>
using ListInt = LNode<ElementTtype, PositionType>;

using List = ListInt<int, int>;
using PList = std::shared_ptr<List>;

PList MakeEmpty();
// Ԫ�ز���
List::position_t Find(const PList &L, const List::element_t& X);
// �������,PΪ��0��ʼ������λ��
bool Insert(PList &L, List::element_t X, List::position_t P);
// �����������ָ��λ�ã�Ĭ�ϴ�������
bool Insert(PList &L, List::element_t X);
// ɾ������
bool Delete(PList &L, List::position_t P);

#endif // !__LIST_H
