///////////////////////////////////////
/// file: binarytree_test.cpp
/// 二叉树测试
///////////////////////////////////////

#include <iostream>
#include "binarytree.h"
using namespace std;

int main()
{
    auto pa = new BiTNode<char> { 'a', nullptr, nullptr };
    auto pb = new BiTNode<char> { 'b', nullptr, nullptr };
    auto pc = new BiTNode<char> { 'c', nullptr, nullptr };
    auto pm = new BiTNode<char> { '*', pa, pb };
    auto ps = new BiTNode<char> { '-', pm, pc };

    auto print = [](char c) { cout << c; return true; };

    PreOrderTraverse(ps,print); cout << endl;
    InOrderTraverse(ps,print); cout << endl;
    PostOrderTraverse(ps,print); cout << endl;
    
    return 0;
}