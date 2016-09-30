#pragma once
#ifndef __TEMPLATEUSAGE_H
#define __TEMPLATEUSAGE_H

#include<iostream>
template<typename T>
class aTMP
{
public:
    typedef const T retType;
};

void f()
{
    std::cout << "global f()\n";
}

template<typename T>
class Base
{
public:
    template <int N=99>
    void f()
    {
        std::cout << "member f():" << N << '\n';
    }
};

template<typename T>
class Derived :public Base
{
public:
    typename T::retType m;
    Derived(typename T::retType a) :m(a) {}

    void df1() { f(); }                          // 全局 f()
    void df2() { this->template f(); }           // 基类 f<99>()
    void df3() { Base<T>::template f<22>(); }    // 强制基类 f<22>()
    void df4() { ::f(); }                        // 强制全局f()
};

void test()
{
    Derived<aTMP<int>> a(10);
    a.df1();
    a.df2();
    a.df3();
    a.df4();
}
#endif // !__TEMPLATEUSAGE_H
