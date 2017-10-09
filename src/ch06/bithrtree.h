///////////////////////////////////////
/// file: bithrtree.h
/// 线索化二叉树
///////////////////////////////////////

///////////////////////////////////////
/// 存储结构

/// 孩子/线索标志
typedef enum { LINK, THREAD } PointerTag;

/// 线索二叉树结点
template<typename E>
struct BiThrNode
{
    E data;
    BiThrNode *lchild, *rchild;
    PointerTag ltag, rtag;  // 指针标志
};

/// 线索二叉树
template<typename E>
using BiThrTree = BiThrNode<E> *;

///////////////////////////////////////
/// 基本操作

///
/// 遍历中序线索二叉树
///
template<typename E, typename F>
void Inorder(BiThrTree<E> T, F visit)
{
    auto p = T->lchild;
    while (p!=T) {
        while (p->ltag==LINK) p = p->lchild;
        visit(p->data);
        while (p->rtag==THREAD && p->rchild!=T) {
            p = p->rchild;
            visit(p->data);
        }
        p = p->rchild;
    }
}

///
/// 中序线索化二叉树
///
template<typename E>
void InThreading(BiThrTree<E> p, BiThrTree<E>& pre)
{
    if (p) {
        // 中序线索化左子树
        InThreading(p->lchild, pre);
        // 根结点 p 的前驱线索
        if (!p->lchild) {
            p->ltag = THREAD, p->lchild = pre;
        }
        // 前驱结点 pre 的后继线索
        if (!pre->rchild) {
            pre->rtag = THREAD, pre->rchild = p;
        }
        // 更新前驱结点
        pre = p;
        // 中序线索化右子树
        InThreading(p->rchild, pre);
    }
}

template<typename E>
void InorderThreading(BiThrTree<E>& Thrt, BiThrTree<E> T)
{
    // 建立头结点
    Thrt = new BiThrNode<E>;
    Thrt->ltag = LINK;
    Thrt->rtag = THREAD;
    if (T==nullptr) {
        // 线索化空二叉树
        Thrt->lchild = Thrt;
        Thrt->rchild = Thrt;
    } else {
        // 从头结点开始
        Thrt->lchild = T;
        auto pre = Thrt;
        // 线索化二叉树
        InThreading(T, pre);
        // 线索化最后一个结点
        pre->rtag = THREAD;
        pre->rchild = Thrt;
        Thrt->rchild = pre;
    }
}