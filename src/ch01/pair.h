///////////////////////////////////////
/// file: pair.h
/// Pair of elements
///////////////////////////////////////

#pragma once

///
/// 任意两个元素组成的对
///
template <typename T1, typename T2>
struct Pair
{
    T1 e1;
    T2 e2;
};

///
/// 创建对
///
template <typename T1, typename T2>
Pair<T1,T2> create_pair(const T1& v1, const T2& v2)
{
    Pair<T1,T2> p = {v1,v2};
    return p;
}

///
/// 取第一个元素
///
template <typename T1, typename T2>
T1 first(const Pair<T1,T2>& p)
{
    return p.e1;
}

///
/// 取第二个元素
///
template <typename T1, typename T2>
T2 second(const Pair<T1,T2>& p)
{
    return p.e2;
}