#define TEST_CASE 0

#if TEST_CASE != 0
    #include<iostream>
    #include<vector>

    #include"MaxSubset.h"
    #include"MaxSubsetResult.h"
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
    //std::vector<int> v = { -3,0, 0, 3, 4, -2, 1, -5, 3, 6, -12, 2, 3, -6 ,1 ,2 ,3 ,4 ,-5 ,-23, 3, 7 ,-21 };//sample��1�����֡���������������ͷ��β���в�������
    //std::vector<int> v = { -2, 11, -4, 13, -5, -2 }; // �����к��и���
    //std::vector<int> v = { 1,2,3,4,-10,10 ,0 };//���кͶ�Ӧ��ͬi���ǲ�ͬj����β��0
    //std::vector<int> v = { -10,-3 }; // ȫ�Ǹ���
    //std::vector<int> v = { 1,-2,0,0,1,2,3,4,-10,0,0,11 }; // ����ǰ����һ����0
    //std::vector<int> v = { 1, 2, 3, -5, -3, 0, 0, 3, 12, -23, 11, 4};//ǰ��һ���㣬���⺬��ͬ���к�
    std::vector<int> v = { -1,0,-3 }; //������0
    for (auto item : v) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    Result res ;
    res = MaxSubsetResult(v);
    std::cout << std::endl<<res.maxSum << " " << res.firstNum << " " << res.lastNum << std::endl;
    
    res = MaxSubSumUseVector(v);
    std::cout << std::endl << res.maxSum << " " << res.firstNum << " " << res.lastNum << std::endl;

    res = MaxSubSumNoVector(v);
    std::cout << std::endl << res.maxSum << " " << res.firstNum << " " << res.lastNum << std::endl;

    system("pause");
    return 0;
}
#endif