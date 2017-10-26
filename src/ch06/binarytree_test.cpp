///////////////////////////////////////
/// file: binarytree_test.cpp
/// 二叉树测试
///////////////////////////////////////

#include <iostream>
#include "binarytree.h"
using namespace std;

int main()
{
    auto pa = new BiTNode<char>{'a', nullptr, nullptr};
    auto pb = new BiTNode<char>{'b', nullptr, nullptr};
    auto pc = new BiTNode<char>{'c', nullptr, nullptr};
    auto pm = new BiTNode<char>{'*', pa, pb};
    auto ps = new BiTNode<char>{'-', pm, pc};

    auto T = ps; // ps 作为二叉树的根

    // 打印二叉树
    Print(T);

    auto print = [](char c) { cout << c; return true; };

    // 先序、中序和后序遍历
    cout << "\nPreorder: ";
    Preorder(T, print);
    cout << "\nInorder: ";
    Inorder(T, print);
    cout << "\nPostorder: ";
    Postorder(T, print);

    // 先序、中序和后序遍历
    cout << "\nPreorderTraverse: ";
    PreorderTraverse(T, print);
    cout << "\nInorderTraverse: ";
    InorderTraverse(T, print);
    cout << "\nPostorderTraverse: ";
    PostorderTraverse(T, print);

    // 按层遍历
    cout << "\nLevelOrder: ";
    LevelOrder(T, print);

    // 非递归遍历
    cout << "\nInorderNR: ";
    InorderNR(T, print);
    cout << "\nPreorderNR: ";
    PreorderNR(T, print);
    cout << "\nPostorderNR: ";
    PostorderNR(T, print);

    cout << endl;

    // 结点数，叶子结点数，深度
    cout << "NodeCount: " << NodeCount(T) << endl;
    cout << "LeafCount: " << LeafCount(T) << endl;
    cout << "Depth: " << Depth(T) << endl;

    // 输入先序序列，创建二叉树
    cout << "Input preorder with null tree (e.g. `AB C  `): ";
    auto bt = CreateBinaryTree();
    Print(bt);

    return 0;
}