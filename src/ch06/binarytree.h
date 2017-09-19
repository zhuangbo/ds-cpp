///////////////////////////////////////
/// file: binarytree.h
/// Binary tree
///////////////////////////////////////

#pragma once

///////////////////////////////////////
/// 存储结构

/// 二叉树结点结构
template<typename E>
struct BiTNode
{
    E data;
    BiTNode *lchild, *rchild;
};

/// 二叉树
template<typename E>
using BiTree = BiTNode<E>*;


///////////////////////////////////////
/// 基本操作

///
/// 先序遍历
///
template<typename E, typename F>
bool PreOrderTraverse(BiTree<E> T, F visit)
{
    if (T) {
        if (! visit(T->data)) return false;
        if (! PreOrderTraverse(T->lchild, visit)) return false;
        if (! PreOrderTraverse(T->rchild, visit)) return false;
    }
    return true;
}

///
/// 中序遍历
///
template<typename E, typename F>
bool InOrderTraverse(BiTree<E> T, F visit)
{
    if (T) {
        if (! InOrderTraverse(T->lchild, visit)) return false;
        if (! visit(T->data)) return false;
        if (! InOrderTraverse(T->rchild, visit)) return false;
    }
    return true;
}

///
/// 后序遍历
///
template<typename E, typename F>
bool PostOrderTraverse(BiTree<E> T, F visit)
{
    if (T) {
        if (! PostOrderTraverse(T->lchild, visit)) return false;
        if (! PostOrderTraverse(T->rchild, visit)) return false;
        if (! visit(T->data)) return false;
    }
    return true;
}
