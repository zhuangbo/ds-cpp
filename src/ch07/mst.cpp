///////////////////////////////////////
/// file: mst.cpp
/// Minimum cost spanning tree
///////////////////////////////////////

#include <iostream>
#include <limits>
using namespace std;

///
/// 邻接矩阵
///
template <typename V, typename E = bool, int M = 20>
struct AMGraph
{
    V vexs[M];          // 图中的顶点
    E arcs[M][M];       // 邻接矩阵
    int vexnum, arcnum; // 顶点数和弧数
};


///
/// 最小生成树 Prim 算法
///  P[v] 表示最小生成树中与顶点 v 关联的边 (v,P[v])
///
template <typename V, typename E, int M>
void Prim(const AMGraph<V, E, M> &G, int P[])
{
    const E INFINITY = std::numeric_limits<E>::max();
    // 标记顶点是否在已求得最小生成树中
    bool inmst[M];
    E cost[M];
    // 从第一个顶点开始
    int u = 0;
    P[u] = -1;   // -1 表示没有关联的边
    cost[u] = 0; //  0 表示没有对应的代价
    inmst[u] = true;
    // 初始化 u 到其他顶点边和代价
    for (int v = 1; v < G.vexnum; v++)
    {
        inmst[v] = false;
        P[v] = G.arcs[u][v] ? u : -1;
        cost[v] = G.arcs[u][v] ? G.arcs[u][v] : INFINITY;
    }
    // 从其余顶点中选择最小代价边
    for (int k = 1; k < G.vexnum; k++)
    {
        // 选择最小代价边 (vk,P[vk])
        int vk = -1;
        E ck = INFINITY;
        for (int v = 1; v < G.vexnum; v++)
            if (!inmst[v] && cost[v] != INFINITY)
            {
                if (cost[v] < ck)
                {
                    ck = cost[v];
                    vk = v;
                }
            }
        // 把对应的顶点 vk 添加到最小生成树
        inmst[vk] = true;
        // 更新最小代价边
        for (int v = 0; v < G.vexnum; v++)
            if (!inmst[v] && G.arcs[vk][v])
            {
                if (G.arcs[vk][v] < cost[v])
                {
                    P[v] = vk;
                    cost[v] = G.arcs[vk][v];
                }
            }
    }
}

int main()
{
    // 建立图
    const int N = 6;
    AMGraph<char, int> G{
        {'A', 'B', 'C', 'D', 'E', 'F'},
        {
            {0, 2, 0, 0, 4, 1},
            {2, 0, 1, 0, 0, 3},
            {0, 1, 0, 3, 0, 5},
            {0, 0, 3, 0, 2, 4},
            {4, 0, 0, 2, 0, 3},
            {1, 3, 5, 4, 3, 0},
        },
        N,
    };

    // 求最小生成树
    int P[N];
    Prim(G, P);
    // 打印最小生成树
    for (int i = 1; i < G.vexnum; i++)
        cout << "(" << G.vexs[P[i]] << "," << G.vexs[i] << ") ";
    cout << endl;
    return 0;
}