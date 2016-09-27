#pragma once
#ifndef __MAXSUBSET_H
#define __MAXSUBSET_H

#include<vector>

/*
求数字串子列最大和，例如含有10个数字的列{-10 1 2 3 4 -5 -23 3 7 -21}，最大和为10
复杂度  T(N)=O(N)
输入：第一行是数字个数K，第二行输入K个数字，输出结果为子列最大和

10
-10 1 2 3 4 -5 -23 3 7 -21
10

*/
long MaxSubSet(const std::vector<int> & NumberArray)
{
    long MaxSum = 0, TempSum = 0;
    int i, len = NumberArray.size();
    for (i = 0; i < len; i++) {
        TempSum += NumberArray[i]; // 向右累加
        if (TempSum > MaxSum) {    
            MaxSum = TempSum;  // 发现最大和，更新最大和
        }
        else if (TempSum < 0) {
            TempSum = 0;       // 如果当前子列和小于0，则不可能使后面的和增大，故丢弃
        }
    }

    return MaxSum;
}



#endif