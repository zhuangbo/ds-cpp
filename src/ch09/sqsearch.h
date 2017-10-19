///////////////////////////////////////
/// file: sqsearch.h
/// Sequential search
///////////////////////////////////////

#pragma once

///
/// 顺序查找
///
template <typename E>
int SqSearch(E a[], int n, E x)
{
    for (int i = 0; i < n; i++)
        if (a[i] == x)
            return i;

    return -1; // 未找到
}
