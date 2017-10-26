///////////////////////////////////////
/// file: sqstack_test.cpp
/// SqStack tests
///////////////////////////////////////

#include <iostream>
#include "sqstack.h"

using namespace std;

/// 打印栈中的数据
template <typename E, int M>
void Print(const SqStack<E, M> &S)
{
    cout << "[";
    for (int i = 0; i < S.top; i++)
        cout << " " << S.elem[i];
    cout << " ^]" << endl;
}

///
/// 顺序栈的测试
///
int main()
{
    // 创建栈
    SqStack<int> s;
    // 初始化
    InitStack(s);

    Print(s);

    // 入栈
    Push(s, 3);
    Push(s, 1);
    Push(s, 4);

    Print(s);

    // 栈空否
    cout << "StackEmpty = " << StackEmpty(s) << endl;
    // 栈长度
    cout << "StackLength = " << StackLength(s) << endl;
    // 取栈顶元素
    int e;
    GetTop(s, e);
    cout << "GetTop = " << e << endl;

    // 出栈
    Pop(s, e);
    cout << "Pop = " << e << endl;
    Print(s);
    Pop(s, e);
    cout << "Pop = " << e << endl;
    Print(s);
    Pop(s, e);
    cout << "Pop = " << e << endl;
    Print(s);

    // 栈空否
    cout << "StackEmpty = " << StackEmpty(s) << endl;
    // 栈长度
    cout << "StackLength = " << StackLength(s) << endl;

    return 0;
}