///////////////////////////////////////
/// file: sqlist.h
/// Sequential list
///////////////////////////////////////

#pragma once

#include <stdexcept>  // for std::out_of_range
using std::out_of_range;  // 导入名称
using std::length_error;

///////////////////////////////////////
/// 存储结构

///
/// 线性表的顺序存储结构
///
template<typename E, int MAXSIZE=256>
struct SqList {
    E elem[MAXSIZE];
    int length;
};

///////////////////////////////////////
/// 基本操作

///
/// 构造空的顺序表 L
///
template<typename E, int M>
void InitList(SqList<E,M>& L) {
    L.length = 0;  // 空表长度为 0
}

///
/// 销毁顺序表 L
///
template<typename E, int M>
void DestroyList(SqList<E,M>& L)
{
    // do nothing
}

///
/// 将顺序表 L 置为空表
///
template<typename E, int M>
void ClearList(SqList<E,M>& L)
{
    L.length = 0;
}

///
/// 若 L 为空表，则返回 true，否则返回 false
///
template<typename E, int M>
bool ListEmpty(const SqList<E,M>& L)
{
    return L.length == 0;
}

///
/// 返回顺序表 L 中数据元素个数
///
template<typename E, int M>
int ListLength(const SqList<E,M>& L)
{
    return L.length;
}

///
/// 用 e 返回顺序表 L 中第 i 个数据元素，1<=i<=length
///
template<typename E, int M>
bool GetElem(const SqList<E,M>& L, int i, E& e)
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
template<typename E, int M>
const E& GetElem(const SqList<E,M>& L, int i)
{
    // 若 i 值不合法，不能取元素
    if(i<1 || i>L.length) throw out_of_range("i out of range");

    // 返回第 i 个元素
    return L.elem[i-1];
}

///
/// 在顺序表 L 中第 i 个位置之前插入新的数据元素 e
///
template<typename E, int MAXSIZE>
void ListInsert(SqList<E,MAXSIZE>& L, int i, E e)
{
    // 若表满，则不能插入
    if(L.length==MAXSIZE) throw length_error("L is full");
    // 若 i 值不合法，则不能插入
    if(i<1 || i>L.length+1) throw out_of_range("i out of range");

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
template<typename E, int M>
void ListDelete(SqList<E,M>& L, int i, E& e)
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


///
/// 返回顺序表 L 中第一个与 e 满足关系 compare 的数据元素的位序
/// 若这样的数据元素不存在，则返回 0。
///
template<typename E, int M, typename Cmp>
int LocateElem(const SqList<E,M>& L, const E& e, Cmp compare)
{
    // 逐个取出元素与 e 比较
    for(int i = 0; i < L.length; i++) {
        // 若满足条件，则返回位序
        if(compare(L.elem[i],e))  return i+1;
    }

    return 0; // 不存在
}

///
/// 遍历顺序表，依次对 L 中的每个数据元素调用函数 visit
///
template<typename E, int M, typename Func>
void ListTraverse(const SqList<E,M>& L, Func visit)
{
    for(int i = 0; i < L.length; i++) {
        visit(L.elem[i]);
    }
}
