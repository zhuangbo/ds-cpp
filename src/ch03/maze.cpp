///////////////////////////////////////
/// file: maze.
/// 求解迷宫
///////////////////////////////////////

#include <iostream>
#include "sqstack.h"
using namespace std;

/// 迷宫类型
const int M = 10; // 迷宫行数
const int N = 10; // 迷宫列数

typedef char Maze[M][N + 1]; // 迷宫类型

const char EMPTY = ' ';     // 迷宫中的通道
const char FOOTPRINT = '*'; // 探索的足记
const char CLOSED = 'x';    // 不能通过的印记

/// 打印迷宫
void Print(const Maze &maze)
{
    for (int i = 0; i < M; i++)
    {
        cout << maze[i] << endl;
    }
}

/// 迷宫中的位置
struct Position
{
    int row;
    int col;
};

/// 判断两个位置相等
bool operator==(const Position &a, const Position &b)
{
    return a.row == b.row && a.col == b.col;
}

/// 判断迷宫中的指定位置是否可以通过
bool Pass(const Maze &maze, const Position &pos)
{
    return maze[pos.row][pos.col] == EMPTY;
}

/// 在迷宫中的指定位置留下足记
void FootPrint(Maze &maze, const Position &pos)
{
    maze[pos.row][pos.col] = FOOTPRINT;
}

/// 在迷宫中指定位置留下不能通过的印记
void MarkPrint(Maze &maze, const Position &pos)
{
    maze[pos.row][pos.col] = CLOSED;
}

/// 移动方向
enum Direction
{
    EAST = 1,
    SOUTH = 2,
    WEST = 3,
    NORTH = 4,
};

/// 下一个位置
Position NextPos(const Position &pos, int dir)
{
    Position p = pos;
    switch (dir)
    {
    case EAST:
        p.col++;
        break;
    case SOUTH:
        p.row++;
        break;
    case WEST:
        p.col--;
        break;
    case NORTH:
        p.row--;
        break;
    }
    return p;
}

/// 迷宫路径上的一步
struct Step
{
    int order;    // 步骤序号
    Position pos; // 位置
    int dir;      // 方向
};

///
/// 走迷宫
///
bool MazePath(Maze &maze, Position start, Position end)
{
    // 初始化空栈
    SqStack<Step, M * N> S;
    InitStack(S);
    // 从起点开始求解迷宫
    Position curpos = start;
    int curord = 1;
    do
    {
        if (Pass(maze, curpos))
        { // 当前位置可行
            // 当前位置作为路径上的一步并入栈
            FootPrint(maze, curpos);
            Step e = {curord, curpos, EAST};
            Push(S, e);
            // 若当前位置为终点，则找到一条路径
            if (curpos == end)
            {
                Print(maze);
                return true;
            }
            // 当前位置不是终点，移动到新的位置
            curpos = NextPos(curpos, EAST);
            curord++;
        }
        else
        {
            if (!StackEmpty(S))
            { // 栈中还有部分路径
                // 从栈中取出最近一步
                Step e;
                Pop(S, e);
                // 如果四个方向都尝试过，则标记为不通的路径
                while (e.dir == NORTH && !StackEmpty(S))
                {
                    MarkPrint(maze, e.pos);
                    Pop(S, e);
                }
                // 如果还有部分方向尚未尝试，则入栈继续尝试
                if (e.dir < NORTH)
                {
                    e.dir++;
                    Push(S, e);
                    curpos = NextPos(e.pos, e.dir);
                }
            }
        }
    } while (!StackEmpty(S));

    return false; // 没有找到任何路径
}

///
/// 利用栈求解迷宫
///
int main()
{
    /// MxN 迷宫
    Maze maze = {
        "##########",
        "#  #   # #",
        "#  #   # #",
        "#    ##  #",
        "# ###    #",
        "#   #    #",
        "# #   #  #",
        "# ### ## #",
        "##       #",
        "##########",
    };
    // 起点和终点
    Position start = {1, 1};
    Position end = {8, 8};

    if (MazePath(maze, start, end))
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "NO WAY" << endl;
    }

    return 0;
}