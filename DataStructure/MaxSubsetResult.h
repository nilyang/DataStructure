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
Result MaxSubsetResult(const std::vector<int>& NumberArray)
{
    std::vector<Result> vRes;
    Result res, preResult, finalResult;

    long maxSum = 0, currSum = 0, findMax = 0, isNegative = 1;
    int idx_begin = 0, idx_end = 0;//index number
    int i, K = NumberArray.size();// K <= 10000

    maxSum = 0;
    // 全部负数判定
    for (i = 0; i < K; i++) {
        isNegative = NumberArray[i] < 0 && isNegative;
    }

    if (isNegative)
        goto negative;

    for (i = 0; i < K; i++) {
        //if (NumberArray[i] == 0 && findMax == 0) {
        //    continue;
        //}
        currSum += NumberArray[i];

        // 如果有多个子列，记录上一个最大子列和
        // 上一个子列和到当前加到一个负数的情况
        if (currSum > 0 && currSum < maxSum && preResult.maxSum > 0) {
            if (vRes.size() > 0) {
                if (vRes[vRes.size() - 1].maxSum < preResult.maxSum) {
                    vRes.pop_back();
                    vRes.push_back(preResult);
                }
            }
            else {
                vRes.push_back(preResult);
            }
        }

        if (currSum >= maxSum) {//不能省略相等，否则 findMax计算会漏算
            maxSum = currSum;
            idx_end = i;
            findMax++;//找到目前最大子列和
                      //std::cout << "idx_end = "<< idx_end <<  ", findMax = " << findMax << std::endl;

                      //记录子列信息
            idx_begin = (idx_end + 1) - findMax;
            res.firstNum = NumberArray[idx_begin];
            res.lastNum = NumberArray[idx_end];
            res.maxSum = maxSum;

            if (preResult.maxSum < maxSum) {
                preResult = res;
                //std::cout << "preResult.maxSum="<< preResult.maxSum <<", idx_end = " << idx_end << std::endl;
            }

            if (vRes.size() > 0) {
                if (vRes[vRes.size() - 1].maxSum < preResult.maxSum) {
                    vRes.pop_back();
                    vRes.push_back(preResult);
                }
            }
        }
        else if (currSum < 0) {
            currSum = 0;
            findMax = 0; // 未找到max子列和
        }
        else {
            findMax++;//额外加1，中间含有负数时
        }
    }
    //std::cout << " vRes.size() = " << vRes.size() << std::endl;

    if (isNegative < 0) {
negative:
        res.maxSum = 0;
        res.firstNum = NumberArray[0];
        res.lastNum = NumberArray[K - 1];
        return res;
    }
    else if (vRes.size() > 0) {
        for (int j = 0, vlen = vRes.size(); j < vlen; j++) {
            if (j + 1 < vlen && vRes[j].maxSum > vRes[j + 1].maxSum) {
                finalResult = vRes[j + 1];
            }
            else {
                finalResult = vRes[j];
            }
        }

        return finalResult;
    }
    else {
        return preResult;
    }
}

// O(N)算法简化
Result MaxSubSum(const std::vector<int>& numArray)
{
    long currSum = 0, maxSum = 0, finalSum = 0;
    int currBeginIdx = 0, currEndIdx = 0;
    int maxBeginIdx = 0, maxEndIdx = 0;

    int i, K = numArray.size();
    int isNegative = 1;
    for (i = 0; i < K; i++) {
        
        currSum += numArray[i];
        
        isNegative = isNegative && (numArray[i] < 0 ? 1 : 0);

        if (currSum<0){
            currSum = 0;
            currBeginIdx = i + 1;
            currEndIdx = currBeginIdx;//开始位置
        }

        if (currSum > maxSum) {
            maxSum = currSum;
            maxEndIdx = currEndIdx = i;//结束位置
        }
    }

    //负数情况
    if (isNegative) {
        maxSum = 0; 
        maxBeginIdx = 0;
        maxEndIdx =  K - 1;
    }

    return Result(maxSum, numArray[maxBeginIdx], numArray[maxEndIdx]);
}
#endif