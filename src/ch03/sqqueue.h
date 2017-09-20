///////////////////////////////////////
/// file: sqqueue.h
/// 循环队列
///////////////////////////////////////

#pragma once

#include <stdexcept>
using std::overflow_error;
using std::underflow_error;

///////////////////////////////////////
/// 存储结构

/// 循环队列
template<typename T, int MAXSIZE=256>
struct SqQueue
{
    T elem[MAXSIZE];    // 数据元素
    int front, rear;    // 头尾位置
};


///////////////////////////////////////
/// 基本操作

///
/// 初始化空队列
///
template<typename T, int M>
void InitQueue(SqQueue<T,M>& Q)
{
    Q.front = Q.rear = 0;
}

///
/// 队列判空
///
template<typename T, int M>
bool QueueEmpty(const SqQueue<T,M>& Q)
{
    return Q.front == Q.rear;
}

///
/// 入队列
///
template<typename T, int MAXSIZE>
void EnQueue(SqQueue<T,MAXSIZE>& Q, T e)
{
    // 若队列满，则上溢
    if((Q.rear+1) % MAXSIZE == Q.front)
        throw overflow_error("Queue full");
    // 在队尾插入元素
    Q.elem[Q.rear] = e;
    Q.rear = (Q.rear+1) % MAXSIZE;
}

///
/// 出队列
///
template<typename T, int MAXSIZE>
void DeQueue(SqQueue<T,MAXSIZE>& Q, T& e)
{
    // 若队列空，则出错
    if(Q.front == Q.rear)
        throw underflow_error("Queue empty");
    // 返回并删除队头元素
    e = Q.elem[Q.front];
    Q.front = (Q.front+1) % MAXSIZE;
}

///
/// 出队列
///
template<typename T, int MAXSIZE>
T DeQueue(SqQueue<T,MAXSIZE>& Q)
{
    T e;
    DeQueue(Q,e);
    return e;
}

///
/// 取队头元素
///
template<typename T, int MAXSIZE>
void GetHead(SqQueue<T,MAXSIZE>& Q, T& e)
{
    // 若队列空，则出错
    if(Q.front == Q.rear)
        throw underflow_error("Queue empty");
    // 返回队头元素
    e = Q.elem[Q.front];
}


///
/// 遍历队列中的元素
///
template<typename T, int MAXSIZE, typename F>
void QueueTraverse(const SqQueue<T,MAXSIZE>& Q, F visit)
{
    for(int i=Q.front; i<Q.rear; i=(i+1)%MAXSIZE) {
        visit(Q.elem[i]);
    }
}