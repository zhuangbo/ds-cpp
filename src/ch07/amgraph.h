///////////////////////////////////////
/// file: amgraph.h
/// 邻接矩阵与图的遍历
///////////////////////////////////////

#pragma once

///////////////////////////////////////
/// 存储结构

///
/// 邻接矩阵
///
template <typename V, typename E = bool, int M = 20>
struct AMGraph
{
    V vexs[M];          // 图中的顶点
    E arcs[M][M];       // 邻接矩阵
    int vexnum, arcnum; // 顶点数和弧数

    bool visited[M];    // 顶点访问标志
};


///////////////////////////////////////
/// 基本操作

///
/// 从顶点 v 出发深度优先遍历图 G
///
template <typename V, typename E, int M, typename F>
void DFS(AMGraph<V, E, M> &G, int v, F visit)
{
    // 访问顶点 v
    visit(G.vexs[v]);
    G.visited[v] = true;
    // 从顶点 v 的未被访问的邻接点 w 开始继续深度优先搜索
    for (int w = 0; w < G.vexnum; w++)
        if (G.arcs[v][w] && !G.visited[w])
            DFS(G, w, visit);
}

///
/// 深度优先搜索遍历图 G
///
template <typename V, typename E, int M, typename F>
void DFSTraverse(AMGraph<V, E, M> &G, F visit)
{
    // 初始化顶点访问标志 visited
    for (int v = 0; v < G.vexnum; ++v)
        G.visited[v] = false;
    // 从一个未访问的顶点 v 出发深度优先遍历图 G
    for (int v = 0; v < G.vexnum; ++v)
        if (!G.visited[v])
            DFS(G, v, visit);
}

#include "../ch03/sqqueue.h" // for SqQueue

///
/// 从顶点 v 出发广度优先遍历图 G
///
template <typename V, typename E, int M, typename F>
void BFS(AMGraph<V, E, M> &G, int v, F visit)
{
    // 访问顶点 v
    visit(G.vexs[v]);
    G.visited[v] = true;
    // 利用队列，从 v 出发广度优先搜索
    SqQueue<int, M> Q;
    InitQueue(Q);
    EnQueue(Q, v);
    while (!QueueEmpty(Q))
    {
        auto v = DeQueue(Q);
        // 访问 v 的未被访问的邻接点 w 并入队列
        for (int w = 0; w < G.vexnum; w++)
            if (G.arcs[v][w] && !G.visited[w])
            {
                visit(G.vexs[w]);
                G.visited[w] = true;
                EnQueue(Q, w);
            }
    }
}

///
/// 广度优先搜索遍历图 G
///
template <typename V, typename E, int M, typename F>
void BFSTraverse(AMGraph<V, E, M> &G, F visit)
{
    // 初始化顶点访问标志 visited
    for (int v = 0; v < G.vexnum; ++v)
        G.visited[v] = false;
    // 从一个未访问的顶点 v 出发广度优先遍历图 G
    for (int v = 0; v < G.vexnum; ++v)
        if (!G.visited[v])
            BFS(G, v, visit);
}
