#include "MaxSubsetResult.h"

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


// ʹ��vector��¼��ʷ���к�
Result MaxSubSumUseVector(const std::vector<int>& numArray)
{
    std::vector<TempInfo> maxSumQueue;//��¼���кͼ�������β��
    std::vector<TempInfo>::iterator iterSQ;//����ȡ����������

    long currSum = 0, maxSum = 0, finalSum = 0, preSum = 0;
    int currBeginIdx = 0, currEndIdx = 0;
    int maxBeginIdx = 0, maxEndIdx = 0;

    int i, K = numArray.size();
    int isNegative = 1;
    for (i = 0; i < K; i++) {
        //��һ�����ܺ�
        preSum = currSum;

        //��ǰ���к�
        currSum += numArray[i];

        //�Ƿ�ȫ�����ж�
        isNegative = isNegative && (numArray[i] < 0 ? 1 : 0);

        if (currSum<0) {
            currSum = 0;// ��ǰ���к�С��0ʱ��������ǰ���к�

            currEndIdx = currBeginIdx = i + 1; //��ʼλ���ƶ�����һ��λ��

            continue;
        }

        if (currSum >= maxSum) {
            maxSum = currSum;
            maxEndIdx = currEndIdx = i;//����λ��
            maxBeginIdx = currBeginIdx;//��ʼλ��
            iterSQ = maxSumQueue.begin();
            if (maxSumQueue.size() == 0 || iterSQ[maxSumQueue.size() - 1].maxSum < maxSum) {
                if (maxSumQueue.size() > 0) {
                    maxSumQueue.pop_back();
                }
                maxSumQueue.push_back(TempInfo(maxSum, maxBeginIdx, maxEndIdx));
            }
        }
    }

    //�������
    if (isNegative) {
        maxSum = 0;
        maxBeginIdx = 0;
        maxEndIdx = K - 1;
    }

    else if (maxSumQueue.size() > 0) {
        TempInfo maxRet = maxSumQueue.back();
        maxSum = maxRet.maxSum;
        maxBeginIdx = maxRet.indexBegin;
        maxEndIdx = maxRet.indexEnd;
    }

    return Result(maxSum, numArray[maxBeginIdx], numArray[maxEndIdx]);
}

// ��ʹ��vector��¼��ʷ���кͣ�����һ�������¼������к���Ϣ
Result MaxSubSumNoVector(const std::vector<int>& numArray)
{
    TempInfo maxResult; //��¼��ʷ��������¼�����Ǹ�
    long currSum = 0, maxSum = 0;
    int currBeginIdx = 0, currEndIdx = 0;
    int maxBeginIdx = 0, maxEndIdx = 0;

    int i, K = numArray.size();
    int isNegative = 1;
    for (i = 0; i < K; i++) {

        //��ǰ���к�
        currSum += numArray[i];

        //�Ƿ�ȫ�����ж�
        isNegative = isNegative && (numArray[i] < 0 ? 1 : 0);

        if (currSum<0) {
            currSum = 0;// ��ǰ���к�С��0ʱ��������ǰ���к�

            currEndIdx = currBeginIdx = i + 1; //��ʼλ���ƶ�����һ��λ��

            continue;
        }

        if (currSum >= maxSum) {
            maxSum = currSum;
            maxEndIdx = currEndIdx = i;//����λ��
            maxBeginIdx = currBeginIdx;//��ʼλ��

                                       // ������к���ʷ��¼(���������Լ���β����)
            if (maxResult.maxSum < maxSum) {
                maxResult.maxSum = maxSum;
                maxResult.indexBegin = maxBeginIdx;
                maxResult.indexEnd = maxEndIdx;
            }
        }
    }

    //�������
    if (isNegative) {
        maxSum = 0;
        maxBeginIdx = 0;
        maxEndIdx = K - 1;
    }

    // ��������������1����ʱ�򣬽���¼��������
    else if (maxResult.maxSum > 0) {
        maxSum = maxResult.maxSum;
        maxBeginIdx = maxResult.indexBegin;
        maxEndIdx = maxResult.indexEnd;
    }

    return Result(maxSum, numArray[maxBeginIdx], numArray[maxEndIdx]);
}
