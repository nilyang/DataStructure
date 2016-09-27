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
long MaxSubSet(const std::vector<int> & NumberArray)
{
    long MaxSum = 0, TempSum = 0;
    int i, len = NumberArray.size();
    for (i = 0; i < len; i++) {
        TempSum += NumberArray[i]; // �����ۼ�
        if (TempSum > MaxSum) {    
            MaxSum = TempSum;  // �������ͣ���������
        }
        else if (TempSum < 0) {
            TempSum = 0;       // �����ǰ���к�С��0���򲻿���ʹ����ĺ����󣬹ʶ���
        }
    }

    return MaxSum;
}



#endif