///////////////////////////////////////
/// file: hanoi.cpp
/// 汉诺塔
///////////////////////////////////////

#include <iostream>
using namespace std;

/// 移动一个盘子
void move(char from, int n, char to)
{
    cout << n << " : " << from << " -> " << to << endl;
}

///
/// 求解 n 阶汉诺塔问题（从 x 到 z 借助 y）
///
void hanoi(int n, char x, char y, char z)
{
    if (n == 1)
        move(x, 1, z);
    else
    {
        hanoi(n - 1, x, z, y);
        move(x, n, z);
        hanoi(n - 1, y, x, z);
    }
}

int main()
{
    int n;

    cout << "hanoi n = ";
    cin >> n;

    hanoi(n, 'X', 'Y', 'Z');

    return 0;
}
