///////////////////////////////////////
/// file: power.cpp
/// n-power
///////////////////////////////////////

#include <iostream>
#include <exception>

///
/// Compute x's n power, x^n
///
double power(double x, int n) {
    if(n<0) throw std::invalid_argument("n<0");
    
    if(n==0) return 1;
    else if(n&1)  // odd or not
        return power(x*x, n/2)*x;
    else
        return power(x*x, n/2);
}

///
/// 输入实数 x 和正整数 n，计算 x^n
///
int main()
{
    double x;
    int n;

    std::cout << "input x and n: ";
    std::cin >> x >> n;
    std::cout << "x^n=" << power(x,n) << std::endl;
    
    return 0;
}