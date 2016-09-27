#define TEST_CASE 0

#if TEST_CASE == 1
#include<iostream>
#include<vector>


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

int main()
{
    int K;
    std::cin >> K;
    int i = 0;
    std::vector<int> Array(K);
    for (i = 0; i < K; i++) {
        std::cin >> Array[i];
    }
    Result res = MaxSubsetResult(Array);
    std::cout << res.maxSum << " " << res.firstNum << " " << res.lastNum << std::endl;
    return 0;
}

#elif TEST_CASE == 2

#include<iostream>
#include<vector>

#include"MaxSubset.h"
int main()
{
    int K;
    std::cin >> K;
    int Len = K, i = 0;
    std::vector<int> Array(K);
    for (i = 0; i < K; i++) {
        std::cin >> Array[i];
    }
    std::cout << MaxSubSet(Array) << std::endl;
    Result res = MaxSubsetResult(Array);
    std::cout << res.maxSum << " " << res.firstNum << " " << res.lastNum << std::endl;
    system("pause");
    return 0;
}
#elif TEST_CASE == 3
int main()
{
    // Create a vector containing integers
    //std::vector<int> v = { 1, -10, -11,3,-27, -23 -12, 13, -4, -5, -3, -23, 7, -21 };
    //std::vector<int> v = { -10 ,1 ,2 ,3 ,4 ,-5 ,-23, 3, 7 ,-21 };//sample
    //std::vector<int> v = { -10 ,1 ,2 ,-3 ,4 ,-5 ,-23, 3, 7 ,-21 };//sample��1�����֡���������������ͷ��β���в�������
    //std::vector<int> v = { -2, 11, -4, 13, -5, -2 }; // �����к��и���
    //std::vector<int>v = { 1,2,3,4,-10,10 };//���кͶ�Ӧ��ͬi���ǲ�ͬj����β��0
    //std::vector<int>v = { -10,-3 };// ȫ�Ǹ���
    std::vector<int> v = { 1,-2,0,0,1,2,3,4,-10,0,0,11 }; // ����ǰ����һ����0


    for (auto item : v) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    Result res = MaxSubsetResult(v);
    std::cout << std::endl<<res.maxSum << " " << res.firstNum << " " << res.lastNum << std::endl;

    system("pause");
    return 0;
}
#endif