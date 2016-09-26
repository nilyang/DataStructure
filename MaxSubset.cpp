#include"MaxSubset.h"

#include<iostream>
#include<vector>


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
    system("pause");
    return 0;
}