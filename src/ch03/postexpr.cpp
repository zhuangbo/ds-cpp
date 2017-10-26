///////////////////////////////////////
/// file: postexpr.cpp
/// 计算后缀表达式
///////////////////////////////////////

#include <iostream>
#include "sqstack.h"
using namespace std;

///
/// 执行计算
///
int Operate(int a, char theta, int b)
{
    switch (theta)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    throw "Unknown operator";
}

/// 读取运算符或操作数，分别返回 OPERATOR 或 OPERAND
/// op 返回运算符，num 返回操作数
enum
{
    OPERATOR,
    OPERAND
};
int Read(char &op, int &num)
{
    char c = cin.peek(); // 查看输入流中的下一个字符
    while (isspace(c))
    {
        cin.ignore(1);
        c = cin.peek();
    } // 跳过空白
    if (c >= '0' && c <= '9')
    {               // 数字开头即为操作数
        cin >> num; // 读取操作数
        return OPERAND;
    }
    else
    {              // 非数字即为运算符
        cin >> op; // 读取运算符
        return OPERATOR;
    }
}

///
/// 计算后缀表达式
///
int EvaluatePostfixExpression()
{
    SqStack<int> S;
    char c;
    bool isop;
    char op;
    int num;
    // 初始化操作数栈
    InitStack(S);
    // 读取一个运算符 op 或操作数 num
    isop = Read(op, num);
    while (isop == OPERAND || op != '=')
    {
        // 处理运算符或操作数
        if (isop == OPERAND)
        { // 遇到操作数直接入栈
            Push(S, num);
        }
        else
        { // 遇到运算符执行运算，结果入栈
            int a, b;
            Pop(S, b);
            Pop(S, a);
            Push(S, Operate(a, op, b));
        }
        // 继续读取运算符或操作数
        isop = Read(op, num);
    }

    // 返回计算结果
    int result;
    Pop(S, result);
    return result;
}

/// 输入后缀表达式（支持+-*/，以等号=结尾），计算并输出结果
/// 如 1+2*3+(4*5+6)*7 对于的后缀表达式为：
/// 1 2 3 * + 4 5 * 6 + 7 * + =
/// 正确结果 189
int main()
{
    cout << "Input a postfix expression (support +-*/ and end with =)" << endl;
    int result = EvaluatePostfixExpression();
    cout << result << endl;

    return 0;
}