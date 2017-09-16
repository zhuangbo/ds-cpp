///////////////////////////////////////
/// file: sstring_test.cpp
/// 定长顺序串测试
///////////////////////////////////////

#include <iostream>
#include "ssting.h"
using namespace std;

int main()
{
    auto s1 = "ababcabcacbababaabcab";
    auto s2 = "abaabc";

    SString S, T;

    Assign(S, s1);
    Assign(T, s2);

    cout << S+1 << endl;
    cout << T+1 << endl;
    cout << Index(S,T,1) << endl;
    cout << Index_KMP(S,T,1) << endl;

    return 0;
}