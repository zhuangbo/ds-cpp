///////////////////////////////////////
/// file: binsearch.h
/// Binary search
///////////////////////////////////////

#pragma once

///
/// 在一个有序数组 a[n] 中查找元素 x。
/// 若找到，返回元素在数组中的下标，否则返回 -1。
///
template <typename E>
int BinarySearch(E a[], int n, const E &x)
{
    int low, mid, high;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < a[mid])
            high = mid - 1;
        else if (x > a[mid])
            low = mid + 1;
        else
            return mid;
    }

    return -1; // not found
}
