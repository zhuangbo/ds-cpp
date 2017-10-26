///////////////////////////////////////
/// file: bst_test.cpp
/// 二叉排序树的测试
///////////////////////////////////////

#include <iostream>
using namespace std;

#include "bst.h"

template <typename E>
void Print(BSTree<E> T, int level = 0)
{
    if (!T)
        return;
    Print(T->rchild, level + 1);
    for (int i = 0; i < level; i++)
        cout << "   ";
    cout << T->data << endl;
    Print(T->lchild, level + 1);
}

int main()
{
    // 创建空的二叉排序树
    BSTree<int> T = nullptr;
    // 插入数据 {53,45,12,24,90,45,80} 构造二叉排序树
    int a[] = {53, 45, 12, 24, 90, 45, 80};
    for (auto x : a)
    {
        Insert(T, x);
        cout << x << " added:" << endl;
        Print(T);
    }
    // 最小和最大元素
    cout << "FindMin: " << FindMin(T)->data << endl;
    cout << "FindMax: " << FindMax(T)->data << endl;
    // 查找数据
    auto p = Search(T, 12);
    cout << "Search 12: " << p->data << endl;
    // 删除 80, 12, 53
    cout << "Delete 80: " << boolalpha << Delete(T, 80) << endl;
    Print(T);
    cout << "Delete 12: " << boolalpha << Delete(T, 12) << endl;
    Print(T);
    cout << "Delete 53: " << boolalpha << Delete(T, 53) << endl;
    Print(T);
    cout << "Delete 40: " << boolalpha << Delete(T, 40) << endl;
    Print(T);

    return 0;
}