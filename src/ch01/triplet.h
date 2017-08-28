///////////////////////////////////////
/// file: triplet.h
/// 三元组数据类型
///////////////////////////////////////

#pragma once

#include <stdexcept> // for std::out_of_range

///////////////////////////////////////
/// 存储结构定义
///
template <typename T>
struct Triplet {
    T elem[3];
};

///////////////////////////////////////
/// 基本操作
///

///
/// 返回三元组 t 的第 i 个元素（1<=i<=3）。
///
template <typename T>
const T& Get(const Triplet<T>& t, int i)
{
    if(i<1 || i>3)
        throw std::out_of_range("i<1 or i>3");
    
    return t.elem[i-1];
}

///
/// 改变三元组 t 的第 i 个元素（1<=i<=3）的值为 e。
///
template <typename T>
void Put(Triplet<T>& t, int i, const T& e)
{
    if(i<1 || i>3)
        throw std::out_of_range("i<1 or i>3");
    
    t.elem[i-1] = e;
}

// ///////////////////////////////////////
// /// 对比以下简化版本，理解引用型参数的作用
// ///

// // 不足之处：与上述常引用版本相比，在参数传递和返回结果时
// // 都会产生额外的存储分配和释放，可能导致低效率。
// // 没有检查参数合法性，缺少错误处理。
// template <typename T>
// T Get(Triplet<T> t, int i)
// {
//     return t.elem[i-1];
// }

// // 不足之处：与上述常引用版本相比，在参数传递时会产生
// // 额外的存储分配和释放，可能导致低效率。
// // 没有检查参数合法性，缺少错误处理。
// template <typename T>
// void Put(Triplet<T>& t, int i, T e)
// {
//     t.elem[i-1] = e;
// }
