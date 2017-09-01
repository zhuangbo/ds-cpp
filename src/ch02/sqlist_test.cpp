///////////////////////////////////////
/// file: sqlist_test.h
/// Test for sequential list
///////////////////////////////////////

#include <iostream>
#include "sqlist.h"

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
    ListInsert(L,1,3);
    ListInsert(L,2,1);
    ListInsert(L,3,4);
    ListInsert(L,4,1);
    ListInsert(L,5,5);
    ListInsert(L,6,9);
    PrintList(L);

    try {
        ListInsert(L,8,0);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
    // 取元素
    cout << "The 1st element is " << GetElem(L,1) << endl;

    // 删除元素
    int e;
    ListDelete(L,3,e);
    PrintList(L);
    cout << "Element deleted " << e << endl;

    return 0;
}