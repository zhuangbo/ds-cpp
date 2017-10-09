///////////////////////////////////////
/// file: bithrtree_test.cpp
/// 线索二叉树测试
///////////////////////////////////////

#include <iostream>
using namespace std;

#include "bithrtree.h"

int main()
{
    // 创建二叉树
    //      e
    //   c     d
    // a   b
    BiThrTree<char>
    pa = new BiThrNode<char>{'a', nullptr, nullptr},
    pb = new BiThrNode<char>{'b', nullptr, nullptr},
    pc = new BiThrNode<char>{'c', pa, pb},
    pd = new BiThrNode<char>{'d', nullptr, nullptr},
    pe = new BiThrNode<char>{'e', pc, pd};
    BiThrTree<char> Thrt, T = pe;

    // 线索化二叉树
    InorderThreading(Thrt, T);

    // 中序遍历线索二叉树
    Inorder(Thrt, [](char c){ cout << c;});

    return 0;
}