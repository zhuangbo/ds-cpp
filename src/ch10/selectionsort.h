///////////////////////////////////////
/// file: selectionsort.h
/// Selection sort
///////////////////////////////////////

#pragma once

///
/// 选择排序
///
template <typename T>
void SelectionSort(T a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        // 从 a[i..n-1] 中选出最小的 a[k] 与 a[i-1] 交换
        int k = i;
        int j = i + 1;
        for (; j < n; j++)
            if (a[j] < a[k])
                k = j;
        if (j != k)
            swap(a[k], a[i - 1]);
    }
}