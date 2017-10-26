///////////////////////////////////////
/// file: bubblesort.h
/// Bubble sort
///////////////////////////////////////

#pragma once

///
/// 冒泡排序
///
template <typename T>
void BubbleSort(T a[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        // 对序列 a[0..n-i-1] 进行一趟冒泡排序
        bool change = false; // 是否发生交换的标志
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                // 交换 a[j] 与 a[j+1]
                swap(a[j], a[j + 1]);
                // 发生交换，设置标志
                change = true;
            }
        }
        // 若一趟排序没有交换发生，则结束排序
        if (!change)
            break;
    }
}
