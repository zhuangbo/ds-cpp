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

    StrAssign(S, s1);
    StrAssign(T, s2);

    cout << "S = '" << S + 1 << "'" << endl;
    cout << "StrLength = " << StrLength(S) << endl;
    SString sub;
    SubString(sub, S, 3, 5);
    cout << "SubString(sub,S,3,5) = '" << sub << "'" << endl;

    cout << "T = '" << T + 1 << "'" << endl;
    cout << "StrLength = " << StrLength(T) << endl;

    cout << "StrCompare(S,T) = " << StrCompare(S, T) << endl;
    SString cat;
    Concat(cat, S, T);
    cout << "Concat(cat,S,T) = '" << cat << "'" << endl;

    cout << "Index(S,T,1) = " << Index(S, T, 1) << endl;

    return 0;
}