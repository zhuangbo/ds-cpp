///////////////////////////////////////
/// file: heapsort.h
/// Heap sort
///////////////////////////////////////

#pragma once

#include <utility> // for std::swap
using std::swap;

/// 假设除 a[s] 外其他结点已经构成大顶堆
/// 把序列 a[s..m] 调整成大顶堆
template <typename T>
void HeapAdjust(T a[], int s, int m)
{
    // 暂存待插入元素（根结点 a[s]）
    T t = a[s];
    // 延根结点向下逐步调整（较大的元素上调）
    for (int j = 2 * s + 1; j <= m; j = 2 * j + 1) // a[j] 的左孩子是 a[2j+1]
    {
        // 从 a[s] 的左右孩子 (a[2s+1] 和 a[2s+2]) 中选出最大的 a[j]
        if (j < m && a[j] < a[j + 1])
            j++;
        // 若孩子结点都小于待插入结点 t 则结束调整
        if (a[j] <= t)
            break;
        // 上调大孩子结点 a[j] 到双亲 a[s] 的位置
        a[s] = a[j];
        // s 记录被上调的元素位置
        s = j;
    }
    // 插入暂存的待插入元素 t
    a[s] = t;
}

///
/// 堆排序
///
template <typename T>
void HeapSort(T a[], int n)
{
    // 把 a[0..n-1] 调整成大顶堆
    for (int i = (n - 3) / 2; i >= 0; i--)
        HeapAdjust(a, i, n - 1);
    // 堆排序
    for (int i = n - 1; i > 0; i--) {
        // 堆顶元素 a[0] 与最后一个元素 a[i] 交换
        swap(a[0], a[i]);
        // 重新调整 a[0..i-1] 为大顶堆
        HeapAdjust(a, 0, i - 1);
    }
}