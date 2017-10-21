///////////////////////////////////////
/// file: sort.h
/// Sort algorithms
///////////////////////////////////////

#pragma once

#include "insertionsort.h"
#include "shellsort.h"
#include "bubblesort.h"
#include "quicksort.h"
#include "selectionsort.h"
#include "heapsort.h"
#include "mergesort.h"

/// 简单插入排序
template <typename T>
void InsertionSort(T a[], int n);

/// 二分插入排序
template <typename T>
void BinInsertionSort(T a[], int n);

/// 希尔排序
template <typename T>
void ShellSort(T a[], int n);

/// 冒泡排序
template <typename T>
void BubbleSort(T a[], int n);

/// 快速排序
template <typename T>
void QuickSort(T a[], int n);

/// 简单选择排序
template <typename T>
void SelectionSort(T a[], int n);

/// 堆排序
template <typename T>
void HeapSort(T a[], int n);

/// 归并排序
template <typename T>
void MergeSort(T a[], int n);
