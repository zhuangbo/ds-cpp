///////////////////////////////////////
/// file: linklist_test2.cpp
///////////////////////////////////////

#include <iostream>
#include "linklist.h"
using namespace std;

///
/// 打印链表
///
template<typename E>
void PrintList(LinkList<E> L)
{
    cout << "(";
    auto p = L->next;
    while(p) {
        cout << " " << p->data;
        p = p->next;
    }
    cout << " )" << endl;
}

bool eq(int a, int b)
{
    return a==b;
}

void print(int x)
{
    cout << " " << x;
}

///
/// 在单链表中定位元素，遍历顺序表
///
int main()
{
    // 建立链表
    LinkList<int> L;
    // 初始化
    InitList(L);
    PrintList(L);

    // 插入元素
    ListInsert(L,1,3);
    ListInsert(L,2,1);
    ListInsert(L,3,4);
    ListInsert(L,4,1);
    ListInsert(L,5,5);
    ListInsert(L,6,9);
    PrintList(L);

    // 元素定位
    cout << "LocateElem 9 = ";
    cout << "L(@" << LocateElem(L,9,eq) << ")" << endl;

    // 遍历线性表
    cout << "ListTraverse: ";
    ListTraverse(L,print);
    cout << endl;

    // 销毁链表
    DestroyList(L);

    return 0;
}