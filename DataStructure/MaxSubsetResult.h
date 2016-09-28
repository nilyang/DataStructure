#ifndef __MAXSUBSETRESULT_H
#define __MAXSUBSETRESULT_H

#include<iostream>
#include<vector>

/*
��MaxSubset�����ϣ�����������βԪ�أ��ո�ָ�
��һ�У�¼��K
�ڶ��У�¼��K�����ֿո�ָ�
�����У����������кͼ���βԪ�أ��ո�ָ�
--------------------------------------------
e.g

10
- 10 1 2 3 4 - 5 - 23 3 7 - 21
10 1 4
--------------------------------------------
Ҫ��
a. ���ȫΪ����������ֵΪ0����β�ֱ�ȡ��һ�������һ��Ԫ��
b. ���

����������
1. { -10 ,1 ,2 ,3 ,4 ,-5 ,-23, 3, 7 ,-21 };  //sample
2. { -10 ,1 ,2 ,-3 ,4 ,-5 ,-23, 3, 7 ,-21 }; //sample��1�����֡���������������ͷ��β���в�������
3. { -2, 11, -4, 13, -5, -2 }; // �����к��и���
4. { 1,2,3,4,-10,10 };  // ���кͶ�Ӧ��ͬi���ǲ�ͬj����β��0
5. { -10,-3 };          // ȫ�Ǹ���
6. {0,0,3,5,-13,6,2,-3}; // ����ǰ��������0�����
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


//���Ӷ� O(2N)
Result MaxSubsetResult(const std::vector<int>& NumberArray)
{
    std::vector<Result> vRes;
    Result res, preResult, finalResult;

    long maxSum = 0, currSum = 0, findMax = 0, isNegative = 1;
    int idx_begin = 0, idx_end = 0;//index number
    int i, K = NumberArray.size();// K <= 10000

    maxSum = 0;
    // ȫ�������ж�
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

        // ����ж�����У���¼��һ��������к�
        // ��һ�����к͵���ǰ�ӵ�һ�����������
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

        if (currSum >= maxSum) {//����ʡ����ȣ����� findMax�����©��
            maxSum = currSum;
            idx_end = i;
            findMax++;//�ҵ�Ŀǰ������к�
                      //std::cout << "idx_end = "<< idx_end <<  ", findMax = " << findMax << std::endl;

                      //��¼������Ϣ
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
            findMax = 0; // δ�ҵ�max���к�
        }
        else {
            findMax++;//�����1���м京�и���ʱ
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

// O(N)�㷨��
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
            currEndIdx = currBeginIdx;//��ʼλ��
        }

        if (currSum > maxSum) {
            maxSum = currSum;
            maxEndIdx = currEndIdx = i;//����λ��
        }
    }

    //�������
    if (isNegative) {
        maxSum = 0; 
        maxBeginIdx = 0;
        maxEndIdx =  K - 1;
    }

    return Result(maxSum, numArray[maxBeginIdx], numArray[maxEndIdx]);
}
#endif