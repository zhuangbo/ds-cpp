///////////////////////////////////////
/// file: floyd.cpp
/// Floyd algorithm
///////////////////////////////////////

#include <iostream>
#include <limits>
using namespace std;

///
/// 邻接矩阵
///
template <typename V, typename E, int N = 20>
struct AMGraph
{
    V vexs[N];          // 图中的顶点
    E arcs[N][N];       // 邻接矩阵
    int vexnum, arcnum; // 顶点数和弧数
};

///
/// Floyd 算法
///  P[i][j] i 到 j 的最短路径上的前驱顶点
///  D[i][j] i 到 j 最短路径
///
template <typename V, typename E, int N>
void Floyd(const AMGraph<V, E, N> &G, int P[N][N], E D[N][N])
{
    const E INFINITY = numeric_limits<E>::max();
    // 用邻接矩阵初始化最短路径
    for (int i = 0; i < G.vexnum; i++)
        for (int j = 0; j < G.vexnum; j++)
        {
            D[i][j] = G.arcs[i][j];
            P[i][j] = (G.arcs[i][j] != INFINITY) ? i : -1;
        }

    // 计算各对顶点之间的最短路径
    for (int k = 0; k < G.vexnum; k++)
        for (int i = 0; i < G.vexnum; i++)
            for (int j = 0; j < G.vexnum; j++)
                if (D[i][k] != INFINITY && D[k][j] != INFINITY && D[i][k] + D[k][j] < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = P[k][j];
                }
}

int main()
{
    // 建立图
    const int N = 4;
    const int X = numeric_limits<int>::max();
    AMGraph<char, int, N> G{
        {'A', 'B', 'C', 'D'},
        {
            {0, 3, 2, X},
            {X, 0, 4, X},
            {X, X, 0, 5},
            {6, 1, X, 0},
        },
        N,
    };

    // 求各对顶点间的最短路径
    int P[N][N];
    int D[N][N];
    Floyd(G, P, D);

    // 输出结果
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (D[i][j] != X)
            {
                cout << G.vexs[i] << G.vexs[j] << ":" << D[i][j];
                cout << "(" << G.vexs[j];
                for (int k = P[i][j]; k != i; k = P[i][k])
                    cout << "<-" << G.vexs[k];
                cout << "<-" << G.vexs[i] << ")  ";
            }
        }
        cout << endl;
    }

    return 0;
}