#include "MaxSubsetResult.h"

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


// 使用vector记录历史子列和
Result MaxSubSumUseVector(const std::vector<int>& numArray)
{
    std::vector<TempInfo> maxSumQueue;//记录子列和及子列首尾数
    std::vector<TempInfo>::iterator iterSQ;//用于取顶部数据项

    long currSum = 0, maxSum = 0, finalSum = 0, preSum = 0;
    int currBeginIdx = 0, currEndIdx = 0;
    int maxBeginIdx = 0, maxEndIdx = 0;

    int i, K = numArray.size();
    int isNegative = 1;
    for (i = 0; i < K; i++) {
        //上一子列总和
        preSum = currSum;

        //当前子列和
        currSum += numArray[i];

        //是否全负数判定
        isNegative = isNegative && (numArray[i] < 0 ? 1 : 0);

        if (currSum<0) {
            currSum = 0;// 当前子列和小于0时，丢弃当前子列和

            currEndIdx = currBeginIdx = i + 1; //起始位置移动到下一个位置

            continue;
        }

        if (currSum >= maxSum) {
            maxSum = currSum;
            maxEndIdx = currEndIdx = i;//结束位置
            maxBeginIdx = currBeginIdx;//起始位置
            iterSQ = maxSumQueue.begin();
            if (maxSumQueue.size() == 0 || iterSQ[maxSumQueue.size() - 1].maxSum < maxSum) {
                if (maxSumQueue.size() > 0) {
                    maxSumQueue.pop_back();
                }
                maxSumQueue.push_back(TempInfo(maxSum, maxBeginIdx, maxEndIdx));
            }
        }
    }

    //负数情况
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

// 不使用vector记录历史子列和，仅用一个对象记录最大子列和信息
Result MaxSubSumNoVector(const std::vector<int>& numArray)
{
    TempInfo maxResult; //记录历史，仅仅记录最大的那个
    long currSum = 0, maxSum = 0;
    int currBeginIdx = 0, currEndIdx = 0;
    int maxBeginIdx = 0, maxEndIdx = 0;

    int i, K = numArray.size();
    int isNegative = 1;
    for (i = 0; i < K; i++) {

        //当前子列和
        currSum += numArray[i];

        //是否全负数判定
        isNegative = isNegative && (numArray[i] < 0 ? 1 : 0);

        if (currSum<0) {
            currSum = 0;// 当前子列和小于0时，丢弃当前子列和

            currEndIdx = currBeginIdx = i + 1; //起始位置移动到下一个位置

            continue;
        }

        if (currSum >= maxSum) {
            maxSum = currSum;
            maxEndIdx = currEndIdx = i;//结束位置
            maxBeginIdx = currBeginIdx;//起始位置

                                       // 最大子列和历史记录(包括最大和以及首尾索引)
            if (maxResult.maxSum < maxSum) {
                maxResult.maxSum = maxSum;
                maxResult.indexBegin = maxBeginIdx;
                maxResult.indexEnd = maxEndIdx;
            }
        }
    }

    //负数情况
    if (isNegative) {
        maxSum = 0;
        maxBeginIdx = 0;
        maxEndIdx = K - 1;
    }

    // 当最子列数超过1个的时候，仅记录最大的子列
    else if (maxResult.maxSum > 0) {
        maxSum = maxResult.maxSum;
        maxBeginIdx = maxResult.indexBegin;
        maxEndIdx = maxResult.indexEnd;
    }

    return Result(maxSum, numArray[maxBeginIdx], numArray[maxEndIdx]);
}
