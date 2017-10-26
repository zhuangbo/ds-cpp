///////////////////////////////////////
/// file: linkqueue.h
/// 链队列
///////////////////////////////////////

#pragma once

#include <stdexcept>
using std::underflow_error;

///////////////////////////////////////
/// 存储结构

/// 结点结构
template <typename E>
struct QNode
{
    E data;
    QNode *next;
};

/// 链队列结构
template <typename E>
struct LinkQueue
{
    QNode<E> *front;
    QNode<E> *rear;
};

///////////////////////////////////////
/// 基本操作

///
/// 初始化空队列
///
template <typename E>
void InitQueue(LinkQueue<E> &Q)
{
    Q.front = new QNode<E>;
    Q.front->next = nullptr;
    Q.rear = Q.front;
}

///
/// 队列判空
///
template <typename E>
bool QueueEmpty(const LinkQueue<E> &Q)
{
    return Q.front == Q.rear;
    // 或 return Q.front->next == nullptr;
}

///
/// 清空队列
///
template <typename E>
void ClearQueue(LinkQueue<E> &Q)
{
    auto p = Q.front;
    while (p->next)
    {
        auto s = p->next;
        p->next = s->next;
        delete s;
    }
}

///
/// 销毁队列
///
template <typename E>
void DestroyQueue(LinkQueue<E> &Q)
{
    ClearQueue(Q);
    delete Q.front;
    Q.front = Q.rear = nullptr;
}

///
/// 入队列
///
template <typename E>
void EnQueue(LinkQueue<E> &Q, E e)
{
    // 新建结点
    auto p = new QNode<E>;
    p->data = e;
    p->next = nullptr;
    // 插入队尾
    Q.rear->next = p;
    // 更新队尾
    Q.rear = p; // 新队尾
}

///
/// 出队列
///
template <typename E>
void DeQueue(LinkQueue<E> &Q, E &e)
{
    // 如果队列空则出错
    if (Q.front == Q.rear)
        throw underflow_error("Queue empty");
    // 取队头元素
    auto p = Q.front->next;
    e = p->data;
    // 从队列中删除队头结点
    Q.front->next = p->next;
    // 必要时更新队尾指针
    if (p == Q.rear)
        Q.rear = Q.front;
    // 释放结点
    delete p;
}

///
/// 出队列
///
template <typename E>
E DeQueue(LinkQueue<E> &Q)
{
    E e;
    DeQueue(Q, e);
    return e;
}

///
/// 取队头元素
///
template <typename E>
void GetHead(const LinkQueue<E> &Q, E &e)
{
    // 如果队列空则出错
    if (Q.front == Q.rear)
        throw underflow_error("Queue empty");
    // 取队头元素
    e = Q.front->next->data;
}

///
/// 取队头元素
///
template <typename E>
E GetHead(const LinkQueue<E> &Q)
{
    E e;
    GetHead(Q, e);
    return e;
}

///
/// 遍历队列中的元素
///
template <typename E, typename F>
void QueueTraverse(const LinkQueue<E> &Q, F visit)
{
    for (auto p = Q.front->next; p; p = p->next)
    {
        visit(p->data);
    }
}