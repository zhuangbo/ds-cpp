///////////////////////////////////////
/// file: quicksort.h
/// Quick sort
///////////////////////////////////////

#pragma once

/// 对 a[low..high] 快速排序
template <typename T>
void QSort(T a[], int low, int high)
{
    if (low >= high)
        return;

    // 划分序列 a[low..high]
    T pivot = a[low];
    int i = low, j = high;
    while (i < j)
    {
        while (i < j && a[j] >= pivot)
            --j;
        a[i] = a[j];
        while (i < j && a[i] <= pivot)
            ++i;
        a[j] = a[i];
    }
    a[i] = pivot;

    // 分别对子序列 a[low..i-1] 和 a[i+1..high]
    QSort(a, low, i - 1);
    QSort(a, i + 1, high);
}

///
/// 快速排序
///
template <typename T>
void QuickSort(T a[], int n)
{
    QSort(a, 0, n - 1);
}