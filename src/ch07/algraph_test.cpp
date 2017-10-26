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
    // G = ({A,B,C,D,E}, {AB,AC,BE,CB,CD,DB,EA,ED})
    ALGraph<char, int> G;
    // 初始化
    InitGraph(G);
    // 添加顶点
    auto a = AddVertex(G, 'A');
    auto b = AddVertex(G, 'B');
    auto c = AddVertex(G, 'C');
    auto d = AddVertex(G, 'D');
    auto e = AddVertex(G, 'E');
    // 添加边
    AddEdge(G, a, b);
    AddEdge(G, a, c);
    AddEdge(G, b, e);
    AddEdge(G, c, b);
    AddEdge(G, c, d);
    AddEdge(G, d, b);
    AddEdge(G, e, a);
    AddEdge(G, e, d);

    // 打印顶点的方法
    auto print = [](char c) { cout << c; };

    // 深度优先遍历
    DFSTraverse(G, print);
    cout << endl;

    // 广度优先遍历
    BFSTraverse(G, print);
    cout << endl;

    return 0;
}