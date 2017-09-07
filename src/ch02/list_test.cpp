///////////////////////////////////////
/// file: list_test.cpp
///////////////////////////////////////

#include <iostream>
#include "list.h"
using namespace std;

///
/// 打印链表
///
template<typename T>
void PrintList(List<T> L)
{
    cout << "(";
    auto p = L->next;
    while(p!=L) {  // 判断表尾
        cout << " " << p->data;
        p = p->next;
    }
    cout << " )" << endl;
}

int main()
{
    // 建立链表
    List<int> L;
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

    // 销毁链表
    DestroyList(L);

    return 0;
}