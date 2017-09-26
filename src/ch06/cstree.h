///////////////////////////////////////
/// file: cstree.h
/// 树的孩子兄弟表示
///////////////////////////////////////

#pragma once

///////////////////////////////////////
/// 存储结构

/// 孩子兄弟结点
template<typename E>
struct CSNode
{
    E data;
    CSNode *firstchild, *nextsibling;
};

/// 树
template<typename E>
using CSTree = CSNode<E> *;  // c++11 only


///////////////////////////////////////
/// 算法

///
/// 先根（序）遍历
///
template<typename E, typename F>
void Preorder(CSTree<E> T, F visit)
{
    if ( T ) {
        visit(T->data);
        Preorder(T->firstchild, visit);
        Preorder(T->nextsibling, visit);
    }
}

///
/// 后根（序）遍历
///
template<typename E, typename F>
void Postorder(CSTree<E> T, F visit)
{
    if ( T ) {
        Postorder(T->firstchild, visit);
        visit(T->data);
        Postorder(T->nextsibling, visit);
    }
}

///
/// 求树的结点数
///
template<typename E>
int NodeCount(CSTree<E> T)
{
    if (T==nullptr) return 0;
    return 1 + NodeCount(T->firstchild) + NodeCount(T->nextsibling);
}

///
/// 求树的叶子结点数
///
template<typename E>
int LeafCount(CSTree<E> T)
{
    if (T==nullptr) return 0;
    if (T->firstchild==nullptr) return 1 + LeafCount(T->nextsibling);
    return LeafCount(T->firstchild) + LeafCount(T->nextsibling);
}

///
/// 求树的深度
///
template<typename E>
int Depth(CSTree<E> T)
{
    if (T==nullptr) return 0;
    auto fc = Depth(T->firstchild);
    auto ns = Depth(T->nextsibling);
    return max(fc+1, ns);
}

#include <iostream>
using std::cout;
using std::endl;

///
/// 缩进打印树
///
template<typename E>
void Print(CSTree<E> T, int level=0)
{
    if (T) {
        for (int i=0; i<level; i++) cout << "  ";
        cout << T->data << endl;
        Print(T->firstchild, level+1);
        Print(T->nextsibling, level);
    }
}


///
/// 根据先根遍历序列 a[si..ti] 和后根遍历序列 b[sj..tj] 建立树
///
template<typename E>
CSTree<E> CreateTree(E a[], int si, int ti, E b[], int sj, int tj)
{
    if (ti-si+1 <= 0) return nullptr;  // 空树
    // 建立根结点
    auto p = new CSNode<E>;
    p->data = a[si];
    // 建立第一棵子树
    int k = sj;
    while (b[k]!=a[si]) ++k;
    p->firstchild = CreateTree(a, si+1, si+k-sj, b, sj, k-1); 
    // 建立兄弟子树
    p->nextsibling = CreateTree(a, si+k-sj+1, ti, b, k+1, tj);
    // 返回树
    return p;
}