#include "MaxSubset.h"

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

