///////////////////////////////////////
/// file: sqlist2_test.h
/// Test for sequential list
///////////////////////////////////////

#include <iostream>
#include "sqlist2.h"

using namespace std;

///
/// 打印顺序表
///
template<typename T, int M>
void PrintList(const SqList<T,M>& L)
{
    cout << "(";
    for(int i=0; i<L.length; i++)
        cout << " " << L.elem[i];
    cout << " )" << endl;
}

///
/// 向动态分配存储空间的顺序表中插入元素
///
int main()
{
    // 新建顺序表
    SqList<int> L;
    // 初始化
    InitList(L);
    PrintList(L);
    cout << "list size: " << L.listsize << endl;
    
    // 插入元素
    for(int i=1; i<=20; i++) {
        ListInsert(L,1,i);
    }
    PrintList(L);
    cout << "list size: " << L.listsize << endl;
    
    return 0;
}