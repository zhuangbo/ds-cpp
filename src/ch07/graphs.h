///////////////////////////////////////
/// file: graphs.h
/// 图的存储结构
///////////////////////////////////////

///
/// 图的邻接矩阵(Adjacency-Matrix)存储结构
///
template <typename V, typename E, int M = 20>
struct AMGraph
{
    V vexs[M];          // 图中的顶点
    E arcs[M][M];       // 邻接矩阵
    int vexnum, arcnum; // 顶点和弧的数量
};

///
/// 图的邻接表(Adjacency-List)存储结构
///
template <typename V, typename E, int M = 20>
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
};

///
/// 图的十字链表(Orthogonal-List)存储结构
///
template <typename V, typename E, int M = 20>
struct OLGraph
{
    // 弧结点结构
    struct ArcNode
    {
        E weight;               // 弧上的权值
        int tailvex, headvex;   // 弧尾和弧头
        ArcNode *tlink, *hlink; // 分别指向同弧尾和同弧头的下一个弧结点
    };
    // 顶点结点结构
    struct VexNode
    {
        V data;                      // 顶点数据
        ArcNode *firstin, *firstout; // 分别指向第一个入弧和出弧结点
    };

    VexNode vexs[M];    // 图中的顶点
    int vexnum, arcnum; // 顶点和弧的数量
};

///
/// 无向图的邻接多重表(Adjacency-Multilist)存储结构
///
template <typename V, typename E, int M = 20>
struct AMLGraph
{
    // 边结点结构
    struct ENode
    {
        E weight;             // 边上的权值
        int ivex, jvex;       // 依附于该边的两个顶点
        ENode *ilink, *jlink; // 分别指向依附于两个顶点的下一条边
    };

    // 顶点结点结构
    struct VexNode
    {
        V data;           // 顶点数据
        ENode *firstedge; // 指向依附于该顶点的第一条边
    };

    VexNode vexs[M];     // 图中的顶点
    int vexnum, edgenum; // 顶点和边的数量
};