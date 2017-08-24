///////////////////////////////////////
/// file: binsearch_test.cpp
/// Tests for binary search
///////////////////////////////////////

#include <iostream>
#include "binsearch.h"  // for binary_search

///
/// 测试二分查找
///
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << binary_search(a,10, 3) << std::endl;
    std::cout << binary_search(a,10, 11) << std::endl;
    
    return 0;
}
