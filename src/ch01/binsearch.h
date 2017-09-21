///////////////////////////////////////
/// file: binsearch.h
/// Binary search
///////////////////////////////////////

#pragma once

///
/// 在一个有序数组 a[n] 中查找元素 x。
/// 若找到，返回元素在数组中的下标，否则返回 -1。
///
/**
 * Binary search an element x in an ordered array a[n].
 *
 * @param a  the sorted array
 * @param n  length of the array
 * @param x  the element to be found
 * @return the index of the element in the array if found, -1 otherwise.
 */
template <typename E>
int binary_search(E a[], int n, const E& x)
{
    int low, mid, high;

    low = 0; high = n-1;
    while(low <= high) {
        mid = (low + high) / 2;
        if(a[mid] < x)
            low = mid + 1;
        else if(a[mid] > x)
            high = mid - 1;
        else
            return mid;
    }

    return -1; // not found
}
