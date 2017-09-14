///////////////////////////////////////
/// file: printer.cpp
/// 操作系统打印排队模拟
///////////////////////////////////////

#include <iostream>
#include "sqqueue.h"

using namespace std;

/// 打印作业
struct Task
{
    int id;
    int pages;
};

/// 打印
void Print(const Task& job)
{
    cout << "#" << job.id << "(" << job.pages << ")";
    for(int i=0; i<job.pages; i++) cout << "../";
    cout << endl;
}

///
/// 模拟打印队列
///
int main()
{
    // 初始化打印队列
    SqQueue<Task,10> Q;
    InitQueue(Q);

    // 多个打印任务进入队列
    EnQueue(Q,Task{1,5});
    EnQueue(Q,Task{2,3});
    EnQueue(Q,Task{3,8});
    EnQueue(Q,Task{4,2});
    EnQueue(Q,Task{5,4});

    // 开始打印
    while(!QueueEmpty(Q)) {
        auto job = DeQueue(Q);
        Print(job);
    }

    return 0;
}