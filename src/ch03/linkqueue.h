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
template<typename T>
struct QNode
{
    T data;
    QNode *next;
};

/// 链队列结构
template<typename T>
struct LinkQueue {
    QNode<T> *front;
    QNode<T> *rear;
};

///////////////////////////////////////
/// 基本操作

///
/// 初始化空队列
///
template<typename T>
void InitQueue(LinkQueue<T>& Q)
{
    Q.front = new QNode<T>;
    Q.front->next = nullptr;
    Q.rear = Q.front;
}

///
/// 队列判空
///
template<typename T>
bool QueueEmpty(const LinkQueue<T>& Q)
{
    return Q.front == Q.rear;
    // 或 return Q.front->next == nullptr;
}

///
/// 清空队列
///
template<typename T>
void ClearQueue(LinkQueue<T>& Q)
{
    auto p = Q.front;
    while(p->next) {
        auto s = p->next;
        p->next = s->next;
        delete s;
    }
}

///
/// 销毁队列
///
template<typename T>
void DestroyQueue(LinkQueue<T>& Q)
{
    ClearQueue(Q);
    delete Q.front;
    Q.front = Q.rear = nullptr;
}

///
/// 入队列
///
template<typename T>
void EnQueue(LinkQueue<T>& Q, T e)
{
    // 新建结点
    auto p = new QNode<T>;
    p->data = e;
    p->next = nullptr;
    // 插入队尾
    Q.rear->next = p;
    // 更新队尾
    Q.rear = p;  // 新队尾
}

///
/// 出队列
///
template<typename T>
void DeQueue(LinkQueue<T>& Q, T& e)
{
    // 如果队列空则出错
    if(Q.front==Q.rear)
        throw underflow_error("Queue underflow.");
    // 取队头元素
    auto p = Q.front->next;
    e = p->data;
    // 从队列中删除队头结点
    Q.front->next = p->next;
    // 必要时更新队尾指针
    if(p==Q.rear) Q.rear = Q.front;
    // 释放结点
    delete p;
}

///
/// 出队列
///
template<typename T>
T DeQueue(LinkQueue<T>& Q)
{
    T e;
    DeQueue(Q,e);
    return e;
}

///
/// 遍历队列中的元素
///
template<typename T, typename F>
void QueueTraverse(const LinkQueue<T>& Q, F visit)
{
    for(auto p = Q.front->next; p; p = p->next) {
        visit(p->data);
    }
}