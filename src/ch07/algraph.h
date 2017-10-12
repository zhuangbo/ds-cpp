///////////////////////////////////////
/// file: algraph.h
/// 邻接表与图的遍历
///////////////////////////////////////

#pragma once

///////////////////////////////////////
/// 存储结构

///
/// 图的邻接表(Adjacency-List)存储结构
///
template <typename V, typename E, int M=20>
struct ALGraph
{
    // 弧结点结构
    struct ArcNode
    {
        E weight;         // 弧上的权值
        int adjvex;       // 邻接点（弧头）
        ArcNode *nextarc; // 指向下一个弧结点（同弧尾的）
    };

    // 顶点结点结构
    struct VexNode
    {
        V data;            // 顶点数据
        ArcNode *firstarc; // 指向第一个弧结点（以该顶点为弧尾的）
    };

    VexNode vexs[M];    // 图中的顶点
    int vexnum, arcnum; // 顶点和弧的数量

    bool visited[M];    // 顶点访问标志
};


///////////////////////////////////////
/// 基本操作

///
/// 从顶点 v 出发深度优先遍历图 G
///
template <typename V, typename E, int M, typename F>
void DFS(ALGraph<V, E, M> &G, int v, F visit)
{
    // 访问顶点 v
    visit(G.vexs[v].data);
    G.visited[v] = true;
    // 从顶点 v 的未被访问的邻接点 w 开始继续深度优先搜索
    for (auto p = G.vexs[v].firstarc; p; p=p->nextarc) {
        auto w = p->adjvex;
        if (!G.visited[w])
            DFS(G, w, visit);
    }
}

///
/// 深度优先搜索遍历图 G
///
template <typename V, typename E, int M, typename F>
void DFSTraverse(ALGraph<V, E, M> &G, F visit)
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
void BFS(ALGraph<V, E, M> &G, int v, F visit)
{
    // 访问顶点 v
    visit(G.vexs[v].data);
    G.visited[v] = true;
    // 利用队列，从 v 出发广度优先搜索
    SqQueue<int, M> Q;
    InitQueue(Q);
    EnQueue(Q, v);
    while (!QueueEmpty(Q))
    {
        auto v = DeQueue(Q);
        // 访问 v 的未被访问的邻接点 w 并入队列
        for (auto p = G.vexs[v].firstarc; p; p=p->nextarc) {
            auto w = p->adjvex;
            if (!G.visited[w])
            {
                visit(G.vexs[w].data);
                G.visited[w] = true;
                EnQueue(Q, w);
            }
        }
    }
}

///
/// 广度优先搜索遍历图 G
///
template <typename V, typename E, int M, typename F>
void BFSTraverse(ALGraph<V, E, M> &G, F visit)
{
    // 初始化顶点访问标志 visited
    for (int v = 0; v < G.vexnum; ++v)
        G.visited[v] = false;
    // 从一个未访问的顶点 v 出发广度优先遍历图 G
    for (int v = 0; v < G.vexnum; ++v)
        if (!G.visited[v])
            BFS(G, v, visit);
}
