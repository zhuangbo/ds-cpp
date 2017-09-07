///////////////////////////////////////
/// file: list.h
/// Linked list
///////////////////////////////////////

#pragma once

#include <stdexcept>
using std::out_of_range;

///////////////////////////////////////
/// 存储结构

///
/// 双向链表结点结构
///
template<typename T>
struct Node {
    T data;
    Node *next;
    Node *prev;
};

///
/// 指针作为双向链表类型
///
template<typename T>
using List = Node<T> *; // C++11 only
// 需要 C++11 编译（如：g++ -std=c++11 ...）

///////////////////////////////////////
/// 基本操作

///
/// 初始化双向循环链表
///
template<typename T>
void InitList(List<T>& L)
{
    // 创建头结点
    L = new Node<T>;
    // 初始化空表
    L->next = L->prev = L;
}

///
/// 链表清空
///
template<typename T>
void ClearList(List<T>& L)
{
    // 释放所有数据结点（仅保留头结点）
    while(L->next!=L) {
        List<T> p = L->next;
        L->next = p->next;
        delete p;
    }
}

///
/// 销毁链表
///
template<typename T>
void DestroyList(List<T>& L)
{
    ClearList(L);  // 链表清空
    delete L;  // 释放头结点
    L = NULL;
}

///
/// 链表判空
///
template<typename T>
bool ListEmpty(List<T> L)
{
    return L->next == L;
}

///
/// 求表长
///
template<typename T>
int ListLength(List<T> L)
{
    int n = 0;
    auto p=L->next;
    while(p!=L) {
        ++n;
        p=p->next;
    }
    return n;
}

///
/// 取元素
///
template<typename T>
void GetElem(List<T> L, int i, T& e)
{
    // 找到第 i 个结点 p
    int j = 1;
    auto p = L->next;
    while(p!=L && j<i) {
        p = p->next;
        ++j;
    }
    // 若存在，则取数据，否则抛出异常
    if(p!=L && j==i) {  // 找到第 i 个结点
        e = p->data;  // 取出结点数据
    } else {  // 不存在第 i 个结点
        throw std::out_of_range("i out of range");
    }
}

///
/// 取元素
///
template<typename T>
T GetElem(List<T> L, int i)
{
    // 找到第 i 个结点 p
    int j = 1;
    auto p = L->next;
    while(p!=L && j<i) {
        p = p->next;
        ++j;
    }
    // 若存在，则返回数据，否则抛出异常
    if(p!=L && j==i) {  // 找到第 i 个结点
        return p->data;  // 返回结点数据
    } else {  // 不存在第 i 个结点
        throw std::out_of_range("i out of range");
    }
}

///
/// 插入数据
///
template<typename T>
void ListInsert(List<T>& L, int i, T e)
{
    // 找到第 i 个结点 p
    int j = 1;
    auto p = L->next;
    while(p!=L && j<i) {  // 注意表尾的判别
        p = p->next;
        ++j;
    }
    // 若找到，则在 p 之前插入 e，否则抛出异常
    if(j==i) { // 若 p==L 则在表尾插入
        // 新建结点
        auto s = new Node<T>();
        s->data = e;
        // 在链表中插入结点（修改两个方向的指针）
        s->prev = p->prev;
        s->prev->next = s;
        s->next = p;
        p->prev = s;
    } else {
        throw out_of_range("i out of range");
    }
}

///
/// 删除数据
///
template<typename T>
void ListDelete(List<T>& L, int i, T& e)
{
    // 寻找找第 i 个结点 p
    int j = 1;
    auto p = L->next;
    while(p!=L && j<i) {
        p = p->next;
        ++j;
    }
    // 若找到第 i 个结点，则删除之，否则抛出异常
    if(p!=L && j==i) {
        // 从链表上移除结点
        p->prev->next = p->next;
        p->next->prev = p->prev;
        // 取出数据
        e = p->data;
        // 释放结点
        delete p;
    } else {
        throw out_of_range("i out of range");
    }
}
