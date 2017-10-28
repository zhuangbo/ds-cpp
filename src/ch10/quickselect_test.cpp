///////////////////////////////////////
/// file: quickselect_test.cpp
/// Quick select test
///////////////////////////////////////

#include <iostream>
using namespace std;

#include "quickselect.h"

int main()
{
    const int n = 17;
    int a[] = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2};

    QuickSelect(a, n, 4);

    for (auto x : a)
        cout << x;
    cout << endl;

    return 0;
}