///////////////////////////////////////
/// file: insertionsort.h
/// Insertion sort
///////////////////////////////////////

#pragma once

///
/// 插入排序
///
template <typename T>
void InsertionSort(T a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        // 将 a[i] 插入有序序列 a[0..i-1] 中
        auto x = a[i];
        int j = i - 1;
        for (; x < a[j]; j--)
            a[j + 1] = a[j];
        a[j + 1] = x;
    }
}

///
/// 插入排序
///
template <typename T>
void BinInsertionSort(T a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        // 在 a[0..i-1] 中折半查找插入位置使 a[high]≤a[i]<a[high+1..i-1]
        int low = 0, high = i - 1;
        while (low <= high)
        {
            int m = (low + high) / 2;
            if (a[i] < a[m])
                high = m - 1;
            else
                low = m + 1;
        }
        // 向后移动元素 a[high+1..i-1]，在 a[high+1] 处插入 a[i]
        T x = a[i];
        for (int j = i - 1; j > high; j--)
            a[j + 1] = a[j];
        a[high + 1] = x; // 完成插入
    }
}