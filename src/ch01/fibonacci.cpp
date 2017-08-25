///////////////////////////////////////
/// file: fibonacci.cpp
/// Calculate Fibonacci numbers
///////////////////////////////////////

#include <iostream>

///
/// 递归计算斐波那契数 O(2^n)
///
long long fib1(int n)
{
    if(n<=1)
        return n;
    else
        return fib1(n-1) + fib1(n-2);
}

///
/// 循环计算斐波那契数 O(n)
///
long long fib2(int n)
{
    long long pre, ppre;
    long long result;

    if(n<=1)
        return n;
    
    pre = 1;  ppre = 0;
    for(int i=2; i<=n; i++) {
        result = pre + ppre;
        ppre = pre;
        pre = result;
    }

    return result;
}

///
/// 斐波那契数的两种算法对比
///
int main()
{
    std::cout << "fib1(40)=" << std::endl;
    std::cout << fib1(40) << std::endl;

    std::cout << "fib2(40)=" << std::endl;
    std::cout << fib2(40) << std::endl;

    return 0;
}