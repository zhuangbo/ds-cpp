///////////////////////////////////////
/// file: dijkstra.cpp
/// Dijkstra algorithm
///////////////////////////////////////

#include <iostream>
#include <limits>
using namespace std;

///
/// 邻接矩阵
///
template <typename V, typename E, int M = 20>
struct AMGraph
{
    V vexs[M];          // 图中的顶点
    E arcs[M][M];       // 邻接矩阵
    int vexnum, arcnum; // 顶点数和弧数
};

///
/// Dijkstra 算法
///  P[] 最短路径上的前驱顶点
///  D[] 最短路径
///
template <typename V, typename E, int M>
void Dijkstra(const AMGraph<V, E, M> &G, int v0, int P[], E D[])
{
    const E INFINITY = std::numeric_limits<E>::max();
    bool finish[M]; // 已求得最短路径的顶点

    // 初始化终点标志、最短路径和路径长度
    for (int v = 0; v < G.vexnum; v++)
    {
        finish[v] = false;
        D[v] = G.arcs[v0][v];
        P[v] = (G.arcs[v0][v] != INFINITY) ? v0 : -1;
    }

    // 初始化到起点 v0 的最短路径和路径长度
    D[v0] = 0;
    P[v0] = -1;
    finish[v0] = true;

    // 求得从 v0 到其余顶点的最短路径
    for (int i = 1; i < G.vexnum; i++)
    {
        // 找出未求得最短路径的顶点中路径长度最短的顶点 v
        auto min = INFINITY;
        int v = -1;
        for (int w = 0; w < G.vexnum; w++)
            if (!finish[w] && D[w] < min)
            {
                min = D[w];
                v = w;
            }
        // 得到 v0 到 v 的最短路径
        finish[v] = true;
        // 更新 v 的（未求得最短路径的）邻接点的最短路径和路径长度
        for (int w = 0; w < G.vexnum; w++)
            if (G.arcs[v][w] != INFINITY && !finish[w] && min + G.arcs[v][w] < D[w])
            {
                P[w] = v;
                D[w] = min + G.arcs[v][w];
            }
    }
}

int main()
{
    // 建立图
    const int N = 6;
    const int X = numeric_limits<int>::max();
    AMGraph<char, int> G{
        {'A', 'B', 'C', 'D', 'E', 'F'},
        {
            {0, 8, 2, X, X, 6},
            {8, 0, 4, X, 3, X},
            {2, 4, 0, 6, X, 3},
            {X, X, 6, 0, 1, 2},
            {X, 3, X, 1, 0, 5},
            {6, X, 3, 2, 5, 0},
        },
        N,
    };

    // 求 A 到其他各顶点的最短路径
    int P[N];
    int D[N];
    Dijkstra(G, 0, P, D);

    // 输出求得的最短路径
    for (int i = 0; i < N; i++)
    {
        // 输出起点和终点
        cout << G.vexs[0] << "->" << G.vexs[i] << " : ";
        // 输出最短路径
        if (D[i] < X)
        {
            cout << D[i];
            cout << " " << G.vexs[i];
            for (int j = P[i]; j != -1; j = P[j])
                cout << "<-" << G.vexs[j];
            cout << endl;
        }
        else
        {
            cout << "No path" << endl;
        }
    }

    return 0;
}