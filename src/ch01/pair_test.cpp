///////////////////////////////////////
/// file: pair_test.cpp
/// Tests for Pair
///////////////////////////////////////

#include <iostream>
#include <string>
#include "pair.h" // for Pair

using namespace std;

///
/// 打印输出一个对
///
template <typename E1, typename E2>
void print(const Pair<E1, E2> &p)
{
    cout << "(" << first(p) << ", " << second(p) << ")" << endl;
}

///
/// 创建不同类型的元素组成的 Pair 然后打印输出
///
int main()
{
    Pair<int, double> p1 = create_pair(3, 0.14);
    print(p1);

    string name = "Bill";
    int age = 20;
    Pair<string, int> p2 = create_pair(name, age);
    print(p2);

    return 0;
}