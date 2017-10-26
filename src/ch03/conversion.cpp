///////////////////////////////////////
/// file: conversion.cpp
/// 数制转换
///////////////////////////////////////

#include <iostream>
#include "sqstack.h"

using namespace std;

///
/// 对于任意输入的一个非负十进制数，打印输出
/// 与其等值的八进制数
///
void conversion()
{
    // 输入十进制数
    int n;
    cout << "n = ";
    cin >> n;

    // 转换为八进制数
    SqStack<int> s;
    InitStack(s); // 初始化为空栈
    do
    {
        Push(s, n % 8);
        n = n / 8;
    } while (n);

    // 输出八进制数
    while (!StackEmpty(s))
    {
        int e;
        Pop(s, e);
        cout << e;
    }
    cout << endl;
}

///
/// 将十进制数转换为八进制数
///
int main()
{
    conversion();
    return 0;
}