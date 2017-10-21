///////////////////////////////////////
/// file: hashtable.h
/// Hash table
///////////////////////////////////////

#include <cstddef>  // for size_t
#include "../ch02/linklist.h" // for LinkList

///////////////////////////////////////
/// 存储结构

///
/// 哈希函数
///
template <typename E>
struct Hash
{
    // 重载 () 运算符
    size_t operator()(const E &key)
    {
        return static_cast<size_t>(key);
    }
};

///
/// 哈希表
///
template <typename E, int M = 29, typename F = Hash<E>>
struct HashTable
{
    LinkList<E> table[M];
};

///
/// 初始化空表
///
template <typename E, int M, typename F>
void InitHashTable(HashTable<E, M, F> &T)
{
    for (auto &p : T.table)
        p = nullptr;
}

///
/// 查找
///
template <typename E, int M, typename F>
LinkList<E> Find(HashTable<E, M, F> &T, const E &key)
{
    F hash;
    auto p = T.table[hash(key) % M];
    while (p && p->data != key)
        p = p->next;
    return p;
}

///
/// 插入
///
template <typename E, int M, typename F>
void Insert(HashTable<E, M, F> &T, const E &key)
{
    auto p = Find(T, key);
    if (p == nullptr)
    {
        F hash;
        auto h = hash(key) % M;
        T.table[h] = new LNode<E>{key, T.table[h]};
    }
}