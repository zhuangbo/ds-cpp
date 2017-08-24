///////////////////////////////////////
/// file: bubblesort_test.cpp
/// Bubble sort test
///////////////////////////////////////

#include <iostream>
#include "bubblesort.h"  // for bubble_sort

///
/// 冒泡排序
///
int main()
{
    int a[] = {7,4,3,2,1,6,9,8,5};

    bubble_sort(a,9);

    for(int i=0; i<9; i++) {
        std::cout << a[i];
    }
    std::cout << std::endl;

    return 0;
}