///////////////////////////////////////
/// file: linkqueue_test.cpp
/// 链队列测试程序
///////////////////////////////////////

#include <iostream>
#include "linkqueue.h"
using namespace std;

///
/// 链队列测试程序
///
int main()
{
    // 打印数据功能
    auto print = [](int x) { cout << x << " "; };

    // 创建队列并初始化
    LinkQueue<int> Q;
    InitQueue(Q);
    QueueTraverse(Q, print);
    cout << "\nQueueEmpty = " << QueueEmpty(Q) << endl;
    
    // 入队列
    EnQueue(Q, 3);
    EnQueue(Q, 1);
    EnQueue(Q, 4);
    EnQueue(Q, 1);
    EnQueue(Q, 5);
    EnQueue(Q, 9);
    QueueTraverse(Q, print);
    cout << "\nQueueEmpty = " << QueueEmpty(Q) << endl;

    // 出队列
    while(!QueueEmpty(Q)) {
        auto e = DeQueue(Q);
        cout << "DeQueue = " << e << endl;
    }
    cout << "\nQueueEmpty = " << QueueEmpty(Q) << endl;    
    
    return 0;
}