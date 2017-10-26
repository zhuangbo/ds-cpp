///////////////////////////////////////
/// file: sqlist_test2.h
/// Test for sequential list
///////////////////////////////////////

#include <iostream>
#include "sqlist.h"

using namespace std;

///
/// 打印顺序表
///
template <typename E, int M>
void PrintList(const SqList<E, M> &L)
{
    cout << "(";
    for (int i = 0; i < L.length; i++)
        cout << " " << L.elem[i];
    cout << " )" << endl;
}

bool eq(int a, int b)
{
    return a == b;
}

void print(int x)
{
    cout << " " << x;
}

///
/// 顺序表基本操作
///
int main()
{
    // 新建顺序表
    SqList<int> L;
    // 初始化
    InitList(L);
    PrintList(L);

    // 插入元素
    ListInsert(L, 1, 3);
    ListInsert(L, 2, 1);
    ListInsert(L, 3, 4);
    ListInsert(L, 4, 1);
    ListInsert(L, 5, 5);
    ListInsert(L, 6, 9);
    PrintList(L);

    // 元素定位
    cout << "LocateElem 9 = ";
    cout << "L(" << LocateElem(L, 9, eq) << ")" << endl;

    // 遍历线性表
    cout << "ListTraverse: ";
    ListTraverse(L, print);
    cout << endl;

    return 0;
}