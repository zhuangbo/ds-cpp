///////////////////////////////////////
/// file: quickselect.h
/// Quick select
///////////////////////////////////////

#pragma once

#include <utility> // for std::swap
using std::swap;

/// 三者取中
template <typename T>
const T &median3(T a[], int low, int high)
{
    int mid = (low + high) / 2;
    if (a[mid] < a[low])
        swap(a[low], a[mid]);
    if (a[high] < a[low])
        swap(a[low], a[high]);
    if (a[high] < a[mid])
        swap(a[mid], a[high]);
    // Place pivot at position high - 1
    swap(a[mid], a[high - 1]);
    return a[high - 1];
}

/// 从 a[low..high] 中快速选出前 k 个最小的元素
template <typename T>
void QSelect(T a[], int low, int high, int k)
{
    if (low >= high)
        return;

    // 划分序列 a[low..high]
    const T &pivot = median3(a, low, high);
    int i = low, j = high - 1;
    for (;;)
    {
        while (a[++i] < pivot) {}
        while (a[--j] > pivot) {}
        if (i < j)
            swap(a[i], a[j]);
        else
            break;
    }
    swap(a[i], a[high - 1]); // Restore pivot

    if (k <= i)
        QSelect(a, low, i - 1, k);
    else
        QSelect(a, i + 1, high, k);
}

///
/// 快速选择
///
template <typename T>
void QuickSelect(T a[], int n, int k)
{
    QSelect(a, 0, n - 1, k);
}