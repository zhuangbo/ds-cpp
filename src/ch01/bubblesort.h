///////////////////////////////////////
/// file: bubblesort.h
/// Bubble sort
///////////////////////////////////////

#pragma once

///
/// 冒泡排序
///
/**
 * Bubble sort for data in array a[n]
 *
 * @param a  an array
 * @param n  length of the array
 */
template <typename E>
void bubble_sort(E a[], int n)
{
    for(int i=0; i<n-1; i++) {
        bool change = false;
        for(int j=0; j<n-i-1; j++) {
            if(a[j] > a[j+1]) {
                E temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;

                change = true;
            }
        }
        if(!change) break;
    }
}

