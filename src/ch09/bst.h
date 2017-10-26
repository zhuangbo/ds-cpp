///////////////////////////////////////
/// file: bst.h
/// Binary search tree
///////////////////////////////////////

#pragma once

///
/// 二叉排序树
///
template <typename E>
struct BSTNode
{
    E data;
    BSTNode *lchild, *rchild;
};

template <typename E>
using BSTree = BSTNode<E> *;

///
/// 最小元素
///
template <typename E>
BSTree<E> FindMin(BSTree<E> T)
{
    if (T == nullptr)
        return nullptr;
    auto p = T;
    while (p->lchild)
        p = p->lchild;
    return p;
}

///
/// 最大元素
///
template <typename E>
BSTree<E> FindMax(BSTree<E> T)
{
    if (T == nullptr)
        return nullptr;
    auto p = T;
    while (p->rchild)
        p = p->rchild;
    return p;
}

///
/// 查找元素（递归算法）
///
template <typename E>
BSTree<E> SearchBST(BSTree<E> T, E e)
{
    if (T == nullptr)
        return T; // not found
    if (e == T->data)
        return T;
    else if (e < T->data)
        return SearchBST(T->lchild, e);
    else
        return SearchBST(T->rchild, e);
}

///
/// 查找元素（非递归）
///
template <typename E>
BSTree<E> Search(BSTree<E> T, E e)
{
    auto p = T;
    while (p && p->data != e)
        if (e < p->data)
            p = p->lchild;
        else
            p = p->rchild;

    return p;
}

///
/// 插入元素（递归）
///
template <typename E>
BSTree<E> InsertBST(BSTree<E> &T, E e)
{
    if (T == nullptr)
    {
        T = new BSTNode<E>{e, nullptr, nullptr};
        return T;
    }
    else if (e < T->data)
        return InsertBST(T->lchild, e);
    else if (e > T->data)
        return InsertBST(T->rchild, e);
    else
        return T; // x 已存在
}

///
/// 插入元素（非递归）
///
template <typename E>
BSTree<E> Insert(BSTree<E> &T, E e)
{
    // 查找元素 x 及其双亲 f
    BSTree<E> p, f;
    p = T, f = nullptr;
    while (p && p->data != e)
        if (e < p->data)
            f = p, p = p->lchild;
        else
            f = p, p = p->rchild;
    // 若找到 x，直接返回
    if (p)
        return p;
    // 若未找到 x，则插入新结点作为 f 的孩子
    auto s = new BSTNode<E>{e, nullptr, nullptr};
    if (f == nullptr)
        T = s; // 插入 s 作为根结点
    else if (e < f->data)
        f->lchild = s; // s 作为 f 的左孩子
    else
        f->rchild = s; // s 作为 f 的右孩子
    // 返回新插入结点
    return s;
}

///
/// 删除元素
///
template <typename E>
bool Delete(BSTree<E> &T, E e)
{
    // 查找元素 x 及其双亲 f
    BSTree<E> p, f;
    p = T, f = nullptr;
    while (p && p->data != e)
        if (e < p->data)
            f = p, p = p->lchild;
        else
            f = p, p = p->rchild;
    // 若未找到 x 则返回 false
    if (!p)
        return false;
    // 若找到 x 则删除并返回 true
    // (1) p 至少有一棵子树为空
    if (!p->lchild || !p->rchild)
    {
        // 从二叉树上删除结点 p
        auto s = !p->lchild ? p->rchild : p->lchild;
        if (f == nullptr)
            T = s;
        else if (f->lchild == p)
            f->lchild = s;
        else
            f->rchild = s;
        // 释放被删除的结点 p
        delete p;
    }
    // (2) p 左右子树均不空
    else
    {
        // 找到 p 的“前驱”（左子树上的最大元素）
        auto q = p, s = p->lchild; // q 为 s 的双亲
        while (s->rchild)
            q = s, s = s->rchild;
        //用 p 的“前驱” s 代替 p
        p->data = s->data;
        //删除 p 的“前驱” s （s的右子树必然为空）
        if (q != p)
            q->rchild = s->lchild;
        else
            q->lchild = s->lchild;
        // 释放被删除的结点 s (p 的“前驱”)
        delete s;
    }
    return true;
}