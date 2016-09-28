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

Result MaxSubsetResult(const std::vector<int>& NumberArray);


//--------------------------//

// O(N) �㷨�򻯰�
// ������Ȼ����ʼλ�ã�������Ҫ��������к�����ʷ��¼��
// ֻ��¼�����Ǹ�����ͬ���к�ֻ��¼��һ��

struct TempInfo{
    long maxSum;
    int indexBegin;
    int indexEnd;
    TempInfo(long max=0, int start=0, int end=0)
        :maxSum(max), indexBegin(start), indexEnd(end)
    {
    }
};

// ʹ��vector��¼��ʷ���к�
Result MaxSubSumUseVector(const std::vector<int>& numArray);

// ��ʹ��vector��¼��ʷ���кͣ�����һ�������¼������к���Ϣ
Result MaxSubSumNoVector(const std::vector<int>& numArray);


#endif