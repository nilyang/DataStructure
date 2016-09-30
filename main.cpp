#define MY_CASE 2


#if MY_CASE == 0


#elif MY_CASE == 2

#include<iostream>

#include"DataStructure\LinkedList.h"

int main()
{
    ListHead<int> *L = MakeEmptyList<int>();

    Insert(L, 13);
    Insert(L, 23);
    Insert(L, 34);
    Insert(L, 45);
    Insert(L, 56);
    
    ListHead<int> *tmp = L->next;
    for (; tmp != nullptr; tmp = tmp->next) {
        std::cout << tmp->Data << " ";
    }
    std::cout << "\n";

    DestroyList<int>(L);

    system("pause");

    return 0;
}

#elif MY_CASE == 1

#include"DataStructure\List.h"

#include<iostream>

int main()
{
    PList list = MakeEmpty();
    std::cout << list->Last << std::endl;
    Insert(list, 1);
    Insert(list, 2);
    Insert(list, 3);
    Insert(list, 4);
    Insert(list, 5);
    Insert(list, 6);
    std::cout << list->Last+1 << std::endl;
    Insert(list, 13, 5);
    Delete(list, 2);
    std::cout << list->Last+1 << std::endl;
    for (int i = 0; i <= list->Last; i++) {
        std::cout << list->Data[i] << " ";
    }
    std::cout << "\n";
    system("pause");
    return 0;
}

#elif MY_CASE == 0

    #define TEST_CASE 1

    #if TEST_CASE != 0
        #include<iostream>
        #include<vector>

        #include"DataStructure\MaxSubset.h"
        #include"DataStructure\MaxSubsetResult.h"
    #endif

    #if TEST_CASE == 1

    int main()
    {
        int K;
        std::cin >> K;
        int i = 0;
        std::vector<int> Array(K);
        for (i = 0; i < K; i++) {
            std::cin >> Array[i];
        }
        //1 2 3 -5 -3 0 0 3 12 -23 11 4
        //Result res = MaxSubsetResult(Array);
        Result res = MaxSubSumNoVector(Array);
        std::cout << res.maxSum << " " << res.firstNum << " " << res.lastNum << std::endl;
        system("pause");
        return 0;
    }

    #elif TEST_CASE == 2

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
        Result res2 = MaxSubSumNoVector(Array);
        std::cout << res2.maxSum << " " << res2.firstNum << " " << res2.lastNum << std::endl;
        system("pause");
        return 0;
    }
    #elif TEST_CASE == 3

    int main()
    {
        // Create a vector containing integers
        //std::vector<int> v = { 1, -10, -11,3,-27, -23 -12, 13, -4, -5, -3, -23, 7, -21 };
        //std::vector<int> v = { -10 ,1 ,2 ,3 ,4 ,-5 ,-23, 3, 7 ,-21 };//sample
        //std::vector<int> v = { -3,0, 0, 3, 4, -2, 1, -5, 3, 6, -12, 2, 3, -6 ,1 ,2 ,3 ,4 ,-5 ,-23, 3, 7 ,-21 };//sample换1个数字。有正负，负数开头结尾，有并列最大和
        //std::vector<int> v = { -2, 11, -4, 13, -5, -2 }; // 子列中含有负数
        //std::vector<int> v = { 1,2,3,4,-10,10 ,0 };//并列和对应相同i但是不同j，即尾是0
        //std::vector<int> v = { -10,-3 }; // 全是负数
        //std::vector<int> v = { 1,-2,0,0,1,2,3,4,-10,0,0,11 }; // 最大和前面有一段是0
        //std::vector<int> v = { 1, 2, 3, -5, -3, 0, 0, 3, 12, -23, 11, 4};//前面一堆零，另外含相同子列和
        std::vector<int> v = { -1,0,-3 }; //负数和0
        for (auto item : v) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
        Result res;
        res = MaxSubsetResult(v);
        std::cout << std::endl << res.maxSum << " " << res.firstNum << " " << res.lastNum << std::endl;

        res = MaxSubSumUseVector(v);
        std::cout << std::endl << res.maxSum << " " << res.firstNum << " " << res.lastNum << std::endl;

        res = MaxSubSumNoVector(v);
        std::cout << std::endl << res.maxSum << " " << res.firstNum << " " << res.lastNum << std::endl;

        system("pause");
        return 0;
    }
    #endif

#endif