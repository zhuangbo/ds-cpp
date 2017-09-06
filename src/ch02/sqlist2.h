///////////////////////////////////////
/// file: sqlist2.h
/// Sequential list using dynamic memory
///////////////////////////////////////

#pragma once

#include <stdexcept>  // for std::out_of_range
using std::out_of_range;  // 导入名称

///////////////////////////////////////
/// 存储结构

///
/// 线性表的顺序存储结构（初始空间大小为 S）
///
template<typename T, int S=16>
struct SqList {
    T *elem;
    int listsize;
    int length;
};

///////////////////////////////////////
/// 基本操作

///
/// 构造空的顺序表 L
///
template<typename T, int S>
void InitList(SqList<T,S>& L) {
    L.elem = new T[S];  // 初始分配空间大小为 S
    L.listsize = S;
    L.length = 0;  // 空表长度为 0
}

///
/// 销毁顺序表 L
///
template<typename T, int S>
void DestroyList(SqList<T,S>& L)
{
    delete[] L.elem;
    L.elem = NULL;
    L.listsize = 0;
    L.length = 0;
}

///
/// 将顺序表 L 置为空表
///
template<typename T, int S>
void ClearList(SqList<T,S>& L)
{
    L.length = 0;
}

///
/// 若 L 为空表，则返回 true，否则返回 false
///
template<typename T, int S>
bool ListEmpty(const SqList<T,S>& L)
{
    return L.length == 0;
}

///
/// 返回顺序表 L 中数据元素个数
///
template<typename T, int S>
int ListLength(const SqList<T,S>& L)
{
    return L.length;
}

///
/// 用 e 返回顺序表 L 中第 i 个数据元素，1<=i<=length
///
template<typename T, int S>
bool GetElem(const SqList<T,S>& L, int i, T& e)
{
    // 若 i 值不合法，则返回 false
    if(i<1 || i>L.length)  return false;

    // 取第 i 个元素
    e = L.elem[i-1];

    // 返回 true 表示操作成功
    return true;
}

///
/// 取顺序表 L 中第 i 个元素
///
template<typename T, int S>
const T& GetElem(const SqList<T,S>& L, int i)
{
    // 若 i 值不合法，不能取元素
    if(i<1 || i>L.length) throw out_of_range("i out of range");

    // 返回第 i 个元素
    return L.elem[i-1];
}

///
/// 扩展顺序表 L 的存储空间
///
template<typename T, int S>
void expand(SqList<T,S>& L)
{
    int n = L.listsize * 2;
    // 分配新空间
    T *p = new T[n];
    // 复制数据
    for(int i=0; i<L.length; i++) p[i] = L.elem[i];
    // 释放旧空间
    delete[] L.elem;
    // 使用新空间
    L.elem = p;
    L.listsize = n;
}

///
/// 在顺序表 L 中第 i 个位置之前插入新的数据元素 e
///
template<typename T, int S>
void ListInsert(SqList<T,S>& L, int i, T e)
{
    // 若 i 值不合法，则不能插入
    if(i<1 || i>L.length+1) throw out_of_range("i out of range");
    // 若表满，则扩展存储空间
    if(L.length==L.listsize) expand(L);  // 扩展存储空间
    
    // 插入位置及之后的元素后移
    for(int j=L.length-1; j>=i-1; j--) {
        L.elem[j+1] = L.elem[j];
    }
    // 插入元素
    L.elem[i-1] = e;
    // 表长增 1
    L.length++;
}

///
/// 在顺序表 L 中删除第 i 个元素，用 e 返回
///
template<typename T, int S>
void ListDelete(SqList<T,S>& L, int i, T& e)
{
    // 若 i 值不合法，则不能删除
    if(i<1 || i>L.length) throw out_of_range("i out of range");
    
    // 取出被删除元素
    e = L.elem[i-1];
    // 被删除元素之后的元素前移
    for(int j=i; j<L.length; j++) {
        L.elem[j-1] = L.elem[j];
    }
    // 表长减 1
    L.length--;
}
