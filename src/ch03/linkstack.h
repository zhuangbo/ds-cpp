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
template <typename E>
struct LNode
{
    E data;
    LNode *next;
};

/// 指针作为链表类型
template <typename E>
using Stack = LNode<E> *; // C++11 only

///////////////////////////////////////
/// 基本操作

///
/// 初始化链栈
///
template <typename E>
void InitStack(Stack<E> &S)
{
    S = NULL;
}

///
/// 判空
///
template <typename E>
bool StackEmpty(const Stack<E> &S)
{
    return S == NULL;
}

///
/// 栈长度
///
template <typename E>
int StackLength(const Stack<E> &S)
{
    int n = 0;
    for (auto p = S; p; p = p->next)
        ++n;
    return n;
}

///
/// 入栈
///
template <typename E>
void Push(Stack<E> &S, E e)
{
    // 新建结点
    Stack<E> p = new LNode<E>;
    p->data = e;
    // 作为新的表头
    p->next = S;
    S = p;
}

///
/// 出栈
///
template <typename E>
void Pop(Stack<E> &S, E &e)
{
    // 栈空则下溢
    if (S == NULL)
        throw underflow_error("Stack underflow");
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
template <typename E>
E Pop(Stack<E> &S)
{
    // 栈空则下溢
    if (S == NULL)
        throw underflow_error("Stack underflow");
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
template <typename E>
void GetTop(const Stack<E> &S, E &e)
{
    // 栈空则下溢
    if (S == NULL)
        throw underflow_error("Stack underflow");
    // 返回栈顶元素
    e = S->data;
}

///
/// 取栈顶元素
///
template <typename E>
E GetTop(const Stack<E> &S)
{
    // 栈空则下溢
    if (S == NULL)
        throw underflow_error("Stack underflow");
    // 返回栈顶元素
    return S->data;
}
