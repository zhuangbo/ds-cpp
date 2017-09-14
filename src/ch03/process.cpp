///////////////////////////////////////
/// file: process.cpp
/// 分时操作系统进程调度模拟
///////////////////////////////////////

#include <iostream>
#include <iomanip>  // for setw()
#include "sqqueue.h"

using namespace std;

/// 进程
struct Process
{
    int pid;  // 进程号
    int dt;   // 延迟时间（开始执行前）
    int rt;   // 运行时间
};

int main()
{
    // 操作系统进程队列
    SqQueue<Process,10> Q;
    InitQueue(Q);

    // 多个进程进入队列
    EnQueue(Q, Process{1, 0, 8});
    EnQueue(Q, Process{2, 3, 4});
    EnQueue(Q, Process{3, 12, 5});
    EnQueue(Q, Process{4, 25, 7});
    EnQueue(Q, Process{5, 3, 6});
    EnQueue(Q, Process{6, 10, 4});

    // 操作系统令每个进程依次获得处理器并执行一个时间片
    int t = 0;  // 系统时间
    cout << " T #1 #2 #3 #4 #5 #6" << endl;
    while(!QueueEmpty(Q)) {
        cout << setw(2) << t;  // 当前时刻
        // 取出一个进程
        auto p = DeQueue(Q);
        if(p.dt > t) {
            // 若需延迟，则重新插入队尾
            cout << setw(p.pid*3) << "." << endl;  // 进程等待
            EnQueue(Q,p);  // 重新入队
        } else {
            // 无需延迟，则执行一个时间片
            cout << setw(p.pid*3) << "*" << endl;  // 进程执行
            --p.rt;  // 运行时间减少
            if(p.rt>0) { // 未执行完
                EnQueue(Q,p);  // 重新入队            
            }
        }
        // 更新系统时间
        ++t;
        if(t%10==0) cout << " T #1 #2 #3 #4 #5 #6" << endl;        
    }

    return 0;
}