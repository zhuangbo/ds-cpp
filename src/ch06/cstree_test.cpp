///////////////////////////////////////
/// file: cstree_test.cpp
/// 树（孩子兄弟链表）测试
///////////////////////////////////////

#include <iostream>
using namespace std;

#include "cstree.h"

int main()
{
    // 创建孩子兄弟链表
    auto
        pk = new CSNode<char>{'K', nullptr, nullptr},
        pj = new CSNode<char>{'J', nullptr, pk},
        pi = new CSNode<char>{'I', pj, nullptr},
        ph = new CSNode<char>{'H', nullptr, nullptr},
        pg = new CSNode<char>{'G', ph, pi},
        pf = new CSNode<char>{'F', nullptr, nullptr},
        pe = new CSNode<char>{'E', nullptr, nullptr},
        pd = new CSNode<char>{'D', pe, pf},
        pc = new CSNode<char>{'C', nullptr, pd},
        pb = new CSNode<char>{'B', pc, pg},
        pa = new CSNode<char>{'A', pb, nullptr};
    auto T = pa;

    // 打印树
    Print(T);

    // 结点数
    cout << "NodeCount = " << NodeCount(T) << endl;

    // 叶子结点数
    cout << "LeafCount = " << LeafCount(T) << endl;

    // 深度
    cout << "Depth = " << Depth(T) << endl;

    // 先根遍历
    cout << "Preorder: ";
    Preorder(T, [](char c) { cout << c; });
    cout << endl;

    // 后根遍历
    cout << "Postorder: ";
    Postorder(T, [](char c) { cout << c; });
    cout << endl;

    // 建立树
    char a[] = "ABCDEFGHIJK";
    char b[] = "CEDFBHGJKIA";
    T = CreateTree(a, 0, 10, b, 0, 10);
    Print(T);

    return 0;
}