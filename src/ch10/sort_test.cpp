///////////////////////////////////////
/// file: sort_test.cpp
/// Sort algorithms test
///////////////////////////////////////

#include <iostream>
using namespace std;

#include "sort.h"

// 用 v[0..n-1] 初始化 a[0..n-1]
void reset(int a[], int n, int v[]);

// 打印数组 a[0..n-1]
void print(int a[], int n);

///
/// 测试各种排序方法
///
int main()
{
    const int n = 10;
    int v[n] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int a[n];

    cout << "简单插入排序" << endl;
    reset(a, n, v);
    print(a, n);
    InsertionSort(a, n);  // 简单插入排序
    print(a, n);

    cout << "二分插入排序" << endl;
    reset(a, n, v);
    print(a, n);
    BinInsertionSort(a, n);  // 二分插入排序
    print(a, n);

    cout << "希尔排序" << endl;
    reset(a, n, v);
    print(a, n);
    ShellSort(a, n);  // 希尔排序
    print(a, n);

    cout << "冒泡排序" << endl;
    reset(a, n, v);
    print(a, n);
    BubbleSort(a, n);  // 冒泡排序
    print(a, n);

    cout << "快速排序" << endl;
    reset(a, n, v);
    print(a, n);
    QuickSort(a, n);  // 快速排序
    print(a, n);

    cout << "简单选择排序" << endl;
    reset(a, n, v);
    print(a, n);
    SelectionSort(a, n);  // 简单选择排序
    print(a, n);

    cout << "堆排序" << endl;
    reset(a, n, v);
    print(a, n);
    HeapSort(a, n);  // 堆排序
    print(a, n);

    cout << "归并排序" << endl;
    reset(a, n, v);
    print(a, n);
    MergeSort(a, n);  // 归并排序
    print(a, n);

    return 0;
}

// 用 v[0..n-1] 初始化 a[0..n-1]
void reset(int a[], int n, int v[])
{
    for (int i = 0; i < n; i++)
        a[i] = v[i];
}

// 打印数组 a[0..n-1]
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << ' ' << a[i];
    cout << endl;
}
