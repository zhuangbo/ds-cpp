///////////////////////////////////////
/// file: pair.h
/// Pair of elements
///////////////////////////////////////

#pragma once

///
/// 任意两个元素组成的对
///
template <typename E1, typename E2>
struct Pair
{
    E1 e1;
    E2 e2;
};

///
/// 创建对
///
template <typename E1, typename E2>
Pair<E1,E2> create_pair(const E1& v1, const E2& v2)
{
    Pair<E1,E2> p = {v1,v2};
    return p;
}

///
/// 取第一个元素
///
template <typename E1, typename E2>
E1 first(const Pair<E1,E2>& p)
{
    return p.e1;
}

///
/// 取第二个元素
///
template <typename E1, typename E2>
E2 second(const Pair<E1,E2>& p)
{
    return p.e2;
}