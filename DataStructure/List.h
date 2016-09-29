#pragma once
#ifndef __LIST_H
#define __LIST_H

// 顺序表

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
// 元素查找
List::position_t Find(const PList &L, const List::element_t& X);
// 插入操作,P为从0开始的索引位置
bool Insert(PList &L, List::element_t X, List::position_t P);
// 插入操作，不指定位置，默认从最后插入
bool Insert(PList &L, List::element_t X);
// 删除操作
bool Delete(PList &L, List::position_t P);

#endif // !__LIST_H
