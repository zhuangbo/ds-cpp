///////////////////////////////////////
/// file: binarytree.h
/// Binary tree
///////////////////////////////////////

#pragma once

///////////////////////////////////////
/// 存储结构

/// 二叉树结点结构
template <typename E>
struct BiTNode
{
    E data;
    BiTNode *lchild, *rchild;
};

/// 二叉树
template <typename E>
using BiTree = BiTNode<E> *; // c++11 only

///////////////////////////////////////
/// 基本操作

///
/// 先序遍历二叉树（所有结点）
///
template <typename E, typename F>
void Preorder(BiTree<E> T, F visit)
{
    if (T)
    {
        visit(T->data);
        Preorder(T->lchild, visit);
        Preorder(T->rchild, visit);
    }
}

///
/// 中序遍历二叉树（所有结点）
///
template <typename E, typename F>
void Inorder(BiTree<E> T, F visit)
{
    if (T)
    {
        Inorder(T->lchild, visit);
        visit(T->data);
        Inorder(T->rchild, visit);
    }
}

///
/// 后序遍历二叉树（所有结点）
///
template <typename E, typename F>
void Postorder(BiTree<E> T, F visit)
{
    if (T)
    {
        Postorder(T->lchild, visit);
        Postorder(T->rchild, visit);
        visit(T->data);
    }
}

///
/// 先序遍历二叉树（快速失败，失败时只遍历部分结点尽快返回）
///
template <typename E, typename F>
bool PreorderTraverse(BiTree<E> T, F visit)
{
    if (T)
    {
        if (!visit(T->data))
            return false;
        if (!PreorderTraverse(T->lchild, visit))
            return false;
        if (!PreorderTraverse(T->rchild, visit))
            return false;
    }
    return true;
}

///
/// 中序遍历二叉树（快速失败，失败时只遍历部分结点尽快返回）
///
template <typename E, typename F>
bool InorderTraverse(BiTree<E> T, F visit)
{
    if (T)
    {
        if (!InorderTraverse(T->lchild, visit))
            return false;
        if (!visit(T->data))
            return false;
        if (!InorderTraverse(T->rchild, visit))
            return false;
    }
    return true;
}

///
/// 后序遍历二叉树（快速失败，失败时只遍历部分结点尽快返回）
///
template <typename E, typename F>
bool PostorderTraverse(BiTree<E> T, F visit)
{
    if (T)
    {
        if (!PostorderTraverse(T->lchild, visit))
            return false;
        if (!PostorderTraverse(T->rchild, visit))
            return false;
        if (!visit(T->data))
            return false;
    }
    return true;
}

#include "../ch03/sqqueue.h"

///
/// 按层次遍历二叉树
///
template <typename E, typename F>
void LevelOrder(BiTree<E> T, F visit)
{
    // 若二叉树为空，则返回
    if (T == nullptr)
        return;

    SqQueue<BiTree<E>, 1024> Q;
    // 队列初始化为空
    InitQueue(Q);
    // 根入队列
    EnQueue(Q, T);
    // 队列不空则继续遍历
    while (!QueueEmpty(Q))
    {
        // 出队列
        auto p = DeQueue(Q);
        // 访问结点
        visit(p->data);
        // 非空左、右子树入队列
        if (p->lchild)
            EnQueue(Q, p->lchild);
        if (p->rchild)
            EnQueue(Q, p->rchild);
    }
}

#include "../ch03/sqstack.h"

///
/// 中序非递归遍历二叉树
///
template <typename E, typename F>
void InorderNR(BiTree<E> T, F visit)
{
    SqStack<BiTree<E>, 1024> S;
    InitStack(S);
    auto p = T;
    while (p || !StackEmpty(S))
    {
        if (p)
        { // 非空子树入栈，沿左子树继续
            Push(S, p);
            p = p->lchild;
        }
        else
        { // 遇到空子树出栈，沿右子树继续
            Pop(S, p);
            visit(p->data); // 从左子树返回时访问
            p = p->rchild;
        }
    }
}

///
/// 先序非递归遍历二叉树
///
template <typename E, typename F>
void PreorderNR(BiTree<E> T, F visit)
{
    SqStack<BiTree<E>, 1024> S;

    InitStack(S);
    auto p = T;
    while (p || !StackEmpty(S))
    {
        if (p)
        { // 非空子树入栈，沿左子树继续
            visit(p->data); // 遇到结点即访问
            Push(S, p);
            p = p->lchild;
        }
        else
        { // 遇到空子树，出栈沿右子树继续
            Pop(S, p);
            p = p->rchild;
        }
    }
}

///
/// 后序非递归遍历二叉树
///
template <typename E, typename F>
void PostorderNR(BiTree<E> T, F visit)
{
    SqStack<BiTree<E>, 1024> S;
    SqStack<int, 1024> tag; // 标志栈，区分第一次和第二次出栈

    InitStack(S), InitStack(tag);
    auto p = T;
    while (p || !StackEmpty(S))
    {
        if (p)
        {
            Push(S, p), Push(tag, 1);
            p = p->lchild;
        }
        else
        {
            int f;
            Pop(S, p), Pop(tag, f); // 第一次入栈
            if (f == 1)
            {
                // 从左子树返回，二次入栈，p 转右子树
                Push(S, p), Push(tag, 2);
                p = p->rchild;
            }
            else
            {
                // 从右子树返回（二次出栈），访问，p 转上层
                visit(p->data);
                p = nullptr; // 接下来继续出栈（不要忘记！）
            }
        }
    }
}

///
/// 求结点个数
///
template <typename E>
int NodeCount(BiTree<E> T)
{
    if (T == nullptr)
        return 0;
    else
        return 1 + NodeCount(T->lchild) + NodeCount(T->rchild);
}

///
/// 求叶子结点数
///
template <typename E>
int LeafCount(BiTree<E> T)
{
    if (T == nullptr)
        return 0;
    if (T->lchild == nullptr && T->rchild == nullptr)
        return 1;
    else
        return LeafCount(T->lchild) + LeafCount(T->rchild);
}

///
/// 求二叉树的深度
///
template <typename E>
int Depth(BiTree<E> T)
{
    if (T == nullptr)
        return 0;
    else
    {
        int L = Depth(T->lchild);
        int R = Depth(T->rchild);
        return L > R ? 1 + L : 1 + R;
    }
}

#include <iostream>
using std::cout;
using std::endl;

///
/// 缩进打印二叉树
///
template <typename E>
void Print(BiTree<E> T, int level)
{
    if (T)
    {
        Print(T->rchild, level + 1);
        for (int i = 0; i < level; i++)
            cout << "  ";
        cout << T->data << endl;
        Print(T->lchild, level + 1);
    }
}

template <typename E>
void Print(BiTree<E> T)
{
    Print(T, 0);
}

#include <iostream>
using std::cin;
using std::noskipws;

///
/// 根据先序序列（含空树，用空格表示）建立二叉树
///
BiTree<char> CreateBinaryTree()
{
    // 输入字符
    char e;
    cin >> noskipws >> e;
    if (e == ' ')
        return nullptr; // 空格表示空二叉树
    // 建立根结点
    auto p = new BiTNode<char>;
    p->data = e;
    // 建立左子树
    p->lchild = CreateBinaryTree();
    // 建立右子树
    p->rchild = CreateBinaryTree();

    return p;
}
