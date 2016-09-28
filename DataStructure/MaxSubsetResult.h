#ifndef __MAXSUBSETRESULT_H
#define __MAXSUBSETRESULT_H

#include<iostream>
#include<vector>


/*
在MaxSubset基础上，返回子列首尾元素，空格分隔
第一行：录入K
第二行：录入K个数字空格分隔
第三行：输出最大子列和及首尾元素，空格分隔
--------------------------------------------
e.g

10
- 10 1 2 3 4 - 5 - 23 3 7 - 21
10 1 4
--------------------------------------------
要求：
a. 如果全为负数，子列值为0，首尾分别取第一个和最后一个元素
b. 如果

测试用例：
1. { -10 ,1 ,2 ,3 ,4 ,-5 ,-23, 3, 7 ,-21 };  //sample
2. { -10 ,1 ,2 ,-3 ,4 ,-5 ,-23, 3, 7 ,-21 }; //sample换1个数字。有正负，负数开头结尾，有并列最大和
3. { -2, 11, -4, 13, -5, -2 }; // 子列中含有负数
4. { 1,2,3,4,-10,10 };  // 并列和对应相同i但是不同j，即尾是0
5. { -10,-3 };          // 全是负数
6. {0,0,3,5,-13,6,2,-3}; // 子列前含有数字0的情况
*/ 
struct Result {
    long maxSum;
    int firstNum;
    int lastNum;
    Result(long max = 0, int first = 0, int last = 0)
        : maxSum(max), firstNum(first), lastNum(last)
    {
    }
};
//复杂度 O(2N)

Result MaxSubsetResult(const std::vector<int>& NumberArray);


//--------------------------//

// O(N) 算法简化版
// 核心依然是求开始位置，另外需要对最大子列和做历史记录，
// 只记录最大的那个，相同子列和只记录第一个

struct TempInfo{
    long maxSum;
    int indexBegin;
    int indexEnd;
    TempInfo(long max=0, int start=0, int end=0)
        :maxSum(max), indexBegin(start), indexEnd(end)
    {
    }
};

// 使用vector记录历史子列和
Result MaxSubSumUseVector(const std::vector<int>& numArray);

// 不使用vector记录历史子列和，仅用一个对象记录最大子列和信息
Result MaxSubSumNoVector(const std::vector<int>& numArray);


#endif