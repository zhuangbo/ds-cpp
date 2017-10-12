///////////////////////////////////////
/// file : amgraph_test.cpp
/// 测试邻接表和图的遍历
///////////////////////////////////////

#include <iostream>
using namespace std;

#include "algraph.h"

int main()
{
    // 建立图
    typedef ALGraph<char,int> Graph;
    typedef ALGraph<char,int>::ArcNode ArcNode;
    // 弧结点
    auto pac = new ArcNode{1, 2, nullptr};
    auto pab = new ArcNode{1, 1, pac};
    auto pbe = new ArcNode{1, 4, nullptr};
    auto pcd = new ArcNode{1, 3, nullptr};
    auto pcb = new ArcNode{1, 1, pcd};
    auto pdb = new ArcNode{1, 1, nullptr};
    auto ped = new ArcNode{1, 3, nullptr};
    auto pea = new ArcNode{1, 0, ped};
    // 邻接表
    Graph G {
        { // 顶点
            {'A', pab}, // AB, AC
            {'B', pbe}, // BE
            {'C', pcb}, // CB, CD
            {'D', pdb}, // DB
            {'E', pea}, // EA, ED
        },
        5, //顶点数
    };

    // 深度优先遍历
    DFSTraverse(G, [](char c){ cout << c; });
    cout << endl;

    // 广度优先遍历
    BFSTraverse(G, [](char c){ cout << c; });
    cout << endl;

    return 0;
}