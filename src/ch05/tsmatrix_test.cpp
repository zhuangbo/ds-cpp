///////////////////////////////////////
/// file: tsmatrix_test.cpp
/// 三元组顺序表测试
///////////////////////////////////////

#include <iostream>
using namespace std;

#include "tsmatrix.h"

template<typename E, int MS>
void Print(const TSMatrix<E,MS>& A)
{
    for (int t=1; t<=A.tu; t++) {
        cout << A.data[t].i << " " << A.data[t].j << " " << A.data[t].e << endl;
    }    
}

int main()
{
    TSMatrix<int,100> A = { {0,0,0, 1,2,12, 1,3,9, 3,1,-3, 3,6,14, 4,3,24, 5,2,18, 6,1,15, 6,4,-7}, 6,6,8 };
    TSMatrix<int,100> B;

    FastTranspose(A,B);

    Print(A);
    Print(B);

    return 0;
}