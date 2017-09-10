///////////////////////////////////////
/// file: sqstack.h
/// Sequential stack
///////////////////////////////////////

#pragma once

#include <stdexcept>
using std::overflow_error;
using std::underflow_error;

///////////////////////////////////////
/// 类型定义

///
/// 顺序栈存储结构
///
template<typename T, int MAXSIZE=256>
struct SqStack {
    T elem[MAXSIZE];
    int top;
};

///////////////////////////////////////
/// 基本操作

///
/// 初始化空栈
///
template<typename T, int M>
void InitStack(SqStack<T,M>& S)
{
    S.top = 0;
}

///
/// 判空
///
template<typename T, int M>
bool StackEmpty(const SqStack<T,M>& S)
{
    return S.top == 0;
}

///
/// 求长度
///
template<typename T, int M>
int StackLength(const SqStack<T,M>& S)
{
    return S.top;
}

///
/// 入栈
///
template<typename T, int MAXSIZE>
void Push(SqStack<T,MAXSIZE>& S, T e)
{
    // 栈满则溢出
    if(S.top == MAXSIZE) throw overflow_error("Stack overflow");
    // 入栈
    S.elem[S.top++] = e;
}

///
/// 出栈
///
template<typename T, int M>
void Pop(SqStack<T,M>& S, T& e)
{
    // 栈空则下溢
    if(S.top==0) throw underflow_error("Stack underflow");
    // 出栈
    e = S.elem[--S.top];
}

///
/// 出栈
///
template<typename T, int M>
T Pop(SqStack<T,M>& S)
{
    // 栈空则下溢
    if(S.top==0) throw underflow_error("Stack underflow");
    // 出栈
    return S.elem[--S.top];
}

///
/// 取栈顶元素
///
template<typename T, int M>
void GetTop(const SqStack<T,M>& S, T& e)
{
    // 栈空则下溢
    if(S.top==0) throw underflow_error("Stack underflow");
    // 返回栈顶元素
    e = S.elem[S.top - 1];  // 栈顶元素的下标 top-1
}

///
/// 取栈顶元素
///
template<typename T, int M>
T GetTop(const SqStack<T,M>& S)
{
    // 栈空则下溢
    if(S.top==0) throw underflow_error("Stack underflow");
    // 返回栈顶元素
    return S.elem[S.top - 1];  // 栈顶元素的下标 top-1
}


///////////////////////////////////////
/// 其他操作

///
/// 清空栈
///
template<typename T, int M>
void ClearStack(SqStack<T,M>& S)
{
    S.top = 0;
}

///
/// 销毁栈
///
template<typename T, int M>
void DestroyStack(SqStack<T,M>& S)
{
    ClearStack(S);
}
