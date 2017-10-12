///////////////////////////////////////
/// file : amgraph_test.cpp
/// 测试邻接矩阵和图的遍历
///////////////////////////////////////

#include <iostream>
using namespace std;

#include "amgraph.h"

int main()
{
    // 建立图
    AMGraph<char, int> G {
        {'A','B','C','D','E'},  // 顶点
        { // 邻接矩阵
            {0,1,1,0,0},
            {0,0,0,0,1},
            {0,1,0,1,0},
            {0,1,0,0,0},
            {1,0,0,1,0},
        },
        5, // 顶点数
    };

    // 深度优先遍历
    DFSTraverse(G, [](char c){ cout << c; });
    cout << endl;

    // 广度优先遍历
    BFSTraverse(G, [](char c){ cout << c; });
    cout << endl;

    return 0;
}