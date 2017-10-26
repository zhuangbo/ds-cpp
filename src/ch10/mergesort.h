///////////////////////////////////////
/// file: mergesort.h
/// Merge sort
///////////////////////////////////////

#pragma once

/// 归并有序的子序列 a[low..mid] 和 a[mid+1..high]，其中 b[low..high] 为临时空间
template <typename T>
void Merge(T a[], T b[], int low, int mid, int high)
{
    // 把 a[low..mid] 和 a[mid+1..high] 归并到 b[low..high]
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
        b[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    while (i <= mid)
        b[k++] = a[i++];
    while (j <= high)
        b[k++] = a[j++];
    // 从 b[low..high] 复制到 a[low..high]
    for (i = low; i <= high; i++)
        a[i] = b[i];
}

/// 对 a[low..high] 进行归并排序，临时空间 b[low..high] 用于归并
template <typename T>
void MSort(T a[], T b[], int low, int high)
{
    if (low < high) {
        int mid = (low + high) / 2;
        MSort(a, b, low, mid);
        MSort(a, b, mid + 1, high);
        Merge(a, b, low, mid, high);
    }
}

///
/// 归并排序
///
template <typename T>
void MergeSort(T a[], int n)
{
    T *b = new T[n];
    MSort(a, b, 0, n - 1);
    delete[] b;
}