#include "MaxSubset.h"

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

