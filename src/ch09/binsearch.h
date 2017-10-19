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
int BinarySearch(E a[], int n, E x)
{
    int low, mid, high;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x == a[mid])
            return mid;
        if (x < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1; // not found
}

///
/// 折半查找
///
template <typename E>
int BinarySearch(E a[], int low, int high, E x)
{
    if (low > high)
        return -1; // not found

    int mid = (low + high) / 2;
    if (x == a[mid])
        return mid;
    else if (x < a[mid])
        return BinarySearch(a, low, mid - 1, x);
    else
        return BinarySearch(a, mid + 1, high, x);
}
