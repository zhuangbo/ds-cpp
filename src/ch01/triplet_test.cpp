///////////////////////////////////////
/// file: triplet_test.cpp
/// Triplet tests
///////////////////////////////////////

#include <iostream>
#include "triplet.h" // for Triplet

///
/// 重载输出运算符 << 输出三元组
///
template <typename E>
std::ostream& operator<<(std::ostream& out, const Triplet<E>& t)
{
    out << '(' << t.elem[0] << ','
        << t.elem[1] << ','
        << t.elem[2] << ')';
    return out;
}


///
/// 测试三元组
///
int main()
{
    Triplet<int> t = {1,2,3};
    std::cout << Get(t,1) << Get(t,2) << Get(t,3) << std::endl;

    try {
        Put(t,2,5);
        Put(t,3,6);
        Put(t,4,7);  // error
    } catch(std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << t << std::endl;
    
    Triplet<char> c = {'a','b','c'};
    std::cout << c << std::endl;
    
    Triplet<double> d = {3.14159, 2.71828, 0.61803};
    std::cout << d << std::endl;
    
    return 0;
}