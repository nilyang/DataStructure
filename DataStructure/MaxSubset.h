#pragma once
#ifndef __MAXSUBSET_H
#define __MAXSUBSET_H

#include<vector>

/*
�����ִ��������ͣ����纬��10�����ֵ���{-10 1 2 3 4 -5 -23 3 7 -21}������Ϊ10
���Ӷ�  T(N)=O(N)
���룺��һ�������ָ���K���ڶ�������K�����֣�������Ϊ��������

10
-10 1 2 3 4 -5 -23 3 7 -21
10

*/
long MaxSubSet(const std::vector<int> & NumberArray);


#endif