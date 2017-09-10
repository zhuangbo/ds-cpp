///////////////////////////////////////
/// file: linkstack.h
/// Stack using linked list
///////////////////////////////////////

#pragma once

#include <stdexcept>
using std::underflow_error;

///////////////////////////////////////
/// 存储结构

///
/// 结点结构
///
template<typename T>
struct LNode {
    T data;
    LNode *next;
};

/// 指针作为链表类型
template<typename T>
using Stack = LNode<T> *; // C++11 only

///////////////////////////////////////
/// 基本操作

///
/// 初始化链栈
///
template<typename T>
void InitStack(Stack<T>& S)
{
    S = NULL;
}

///
/// 判空
///
template<typename T>
bool StackEmpty(const Stack<T>& S)
{
    return S == NULL;
}

///
/// 栈长度
///
template<typename T>
int StackLength(const Stack<T>& S)
{
    int n = 0;
    for(auto p = S; p; p = p->next) ++n;
    return n;
}

///
/// 入栈
///
template<typename T>
void Push(Stack<T>& S, T e)
{
    // 新建结点
    Stack<T> p = new LNode<T>;
    p->data = e;
    // 作为新的表头
    p->next = S;
    S = p;
}

///
/// 出栈
///
template<typename T>
void Pop(Stack<T>& S, T& e)
{
    // 栈空则下溢
    if(S==NULL) throw underflow_error("Stack underflow");
    // 取栈顶元素
    e = S->data;
    // 删除栈顶结点
    auto p = S;
    S = S->next;
    delete p;
}

///
/// 出栈
///
template<typename T>
T Pop(Stack<T>& S)
{
    // 栈空则下溢
    if(S==NULL) throw underflow_error("Stack underflow");
    // 出栈
    auto p = S;
    auto e = p->data;
    S = S->next;
    delete p;
    return e;
}

///
/// 取栈顶元素
///
template<typename T>
void GetTop(const Stack<T>& S, T& e)
{
    // 栈空则下溢
    if(S==NULL) throw underflow_error("Stack underflow");
    // 返回栈顶元素
    e = S->data;
}

///
/// 取栈顶元素
///
template<typename T>
T GetTop(const Stack<T>& S)
{
    // 栈空则下溢
    if(S==NULL) throw underflow_error("Stack underflow");
    // 返回栈顶元素
    return S->data;
}
