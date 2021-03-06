///////////////////////////////////////
/// file: kmp_test.cpp
/// KMP算法测试
///////////////////////////////////////

#include <iostream>
#include "ssting.h"
#include "kmp.h"
using namespace std;

int main()
{
    auto s1 = "ababcabcacbababaabcab";
    auto s2 = "abaabc";

    SString S, T;

    StrAssign(S, s1);
    StrAssign(T, s2);

    cout << S + 1 << endl;
    cout << T + 1 << endl;
    cout << Index(S, T, 1) << endl;
    cout << Index_KMP(S, T, 1) << endl;

    return 0;
}