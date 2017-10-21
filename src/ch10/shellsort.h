///////////////////////////////////////
/// file: shellsort.h
/// Shell sort
///////////////////////////////////////

#pragma once

///
/// 希尔排序
///
template <typename T>
void ShellSort(T a[], int n)
{
    int dk = n / 2;
    while (dk >= 1)
    {
        // 一趟希尔排序，对dk个序列分别进行插入排序
        for (int i = dk; i < n; i++)
        {
            T x = a[i];
            int j = i - dk;
            for (; j >= 0 && x < a[j]; j -= dk)
                a[j + dk] = a[j];
            a[j + dk] = x;
        }
        // 缩小增量
        dk = dk / 2;
    }
}