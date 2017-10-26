///////////////////////////////////////
/// file: linklist.h
///////////////////////////////////////

#pragma once

#include <stdexcept>
using std::out_of_range;

///////////////////////////////////////
/// 存储结构

///
/// 单链表存储结构
///
template <typename E>
struct LNode
{
    E data;
    LNode *next;
};

/// 指针作为单链表类型
template <typename E>
using LinkList = LNode<E> *; // C++11 only
// 需要 C++11 编译（如：g++ -std=c++11 ...）

///////////////////////////////////////
/// 基本操作

///
/// 初始化带头结点的空链表
///
template <typename E>
void InitList(LinkList<E> &L)
{
    // 创建头结点
    L = new LNode<E>();
    // 初始化为空表
    L->next = NULL;
}

///
/// 清空链表
///
template <typename E>
void ClearList(LinkList<E> &L)
{
    // 当表不空时，逐个删除结点
    while (L->next)
    {
        LinkList<E> p = L->next; // p 指向第一个数据结点
        L->next = p->next;       // 从链表中解除结点
        delete p;                // 释放结点存储空间
    }
}

///
/// 销毁链表
///
template <typename E>
void DestroyList(LinkList<E> &L)
{
    ClearList(L); // 清空链表
    delete L;     // 释放头结点
    L = NULL;     // 指针置空（防野指针）
}

///
/// 判断链表是否是空表
///
template <typename E>
bool ListEmpty(LinkList<E> L)
{
    return L->next == NULL;
}

///
/// 求表长
///
template <typename E>
int ListLength(LinkList<E> L)
{
    int n = 0;
    auto p = L; // for C++11 or LinkList<E> p = L;
    while (p->next)
    {
        ++n;
        p = p->next;
    }
    return n;
}

///
/// 取元素
///
template <typename E>
void GetElem(LinkList<E> L, int i, E &e)
{
    // 找到第 i 个结点 p
    int j = 1;
    auto p = L->next;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    // 若存在，则取数据，否则抛出异常
    if (p && j == i)
    {                // 找到第 i 个结点
        e = p->data; // 取出结点数据
    }
    else
    { // 不存在第 i 个结点
        throw std::out_of_range("i out of range");
    }
}

///
/// 取元素
///
template <typename E>
E GetElem(LinkList<E> L, int i)
{
    // 找到第 i 个结点 p
    int j = 1;
    auto p = L->next;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    // 若存在，则返回数据，否则抛出异常
    if (p && j == i)
    {                   // 找到第 i 个结点
        return p->data; // 返回结点数据
    }
    else
    { // 不存在第 i 个结点
        throw std::out_of_range("i out of range");
    }
}

///
/// 插入数据
///
template <typename E>
void ListInsert(LinkList<E> &L, int i, E e)
{
    // 找到第 i-1 个结点 p
    int j = 0;
    auto p = L;
    while (p && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    // 若找到，则在 p 后插入 e，否则抛出异常
    if (p && j == i - 1)
    {
        // 新建结点
        auto s = new LNode<E>();
        s->data = e;
        // 在链表中插入结点
        s->next = p->next;
        p->next = s;
    }
    else
    {
        throw out_of_range("i out of range");
    }
}

///
/// 删除数据
///
template <typename E>
void ListDelete(LinkList<E> &L, int i, E &e)
{
    // 寻找找第 i-1 个结点 p
    int j = 0;
    auto p = L;
    while (p && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    // 若找到且存在第 i 个结点，则删除 p 的下一个结点，否则抛出异常
    if (p && p->next && j == i - 1)
    {
        auto q = p->next;  // q 指向第 i 个结点
        p->next = q->next; // 从链表中移除结点 q
        e = q->data;       // 取被删除结点的数据
        delete q;          // 释放结点的存储空间
    }
    else
    {
        throw out_of_range("i out of range");
    }
}

///
/// 返回单链表 L 中第一个与 e 满足关系 compare 的数据结点的指针
/// 若这样的数据元素不存在，则返回空指针 NULL。
///
template <typename E, typename Cmp>
LinkList<E> LocateElem(LinkList<E> L, const E &e, Cmp compare)
{
    // 逐个取出元素与 e 比较
    for (auto p = L->next; p; p = p->next)
    {
        // 若满足条件，则返回指针
        if (compare(p->data, e))
            return p;
    }

    return NULL; // 不存在
}

///
/// 遍历单链表，依次对 L 中的每个数据元素调用函数 visit
///
template <typename E, typename Func>
void ListTraverse(LinkList<E> L, Func visit)
{
    for (auto p = L->next; p; p = p->next)
    {
        visit(p->data);
    }
}
