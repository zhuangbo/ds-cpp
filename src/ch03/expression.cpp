///////////////////////////////////////
/// file: expression.cpp
/// 计算中缀表达式
///////////////////////////////////////

#include <iostream>
#include "sqstack.h"
using namespace std;

///
/// 运算符之间的优先级关系
///
char Precede(char opl, char opr)
{
    // 语法错误
    if (opl == '(' && opr == '#')
        return 'X';
    if (opl == '#' && opr == ')')
        return 'X';
    if (opl == ')' && opr == '(')
        return 'X';
    // 括号匹配的情况
    if (opl == '#' && opr == '#')
        return '=';
    if (opl == '(' && opr == ')')
        return '=';
    // 全 > 的情况
    if (opl == ')' || opr == ')' || opr == '#')
        return '>';
    // 全 < 的情况
    if (opl == '(' || opr == '(' || opl == '#')
        return '<';
    // 剩余 +-*/ 中 > 的情况
    if (opl == '*' || opl == '/' || opr == '+' || opr == '-')
        return '>';
    // 其他为 < 的情况
    if (opr == '*' || opr == '/')
        return '<';
    return 'X'; // 其他意外情况
}

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
/// 输入表达式计算结果
/// 操作数为非负整数，运算符包括+-*/()，以#结尾
///
int EvaluateExpression()
{
    char c, x;
    int isop;           // 当前输入是运算符（OPERATOR）或操作数（OPERAND）
    char op;            // 当前输入的运算符
    int num;            // 当前输入的操作数
    SqStack<char> optr; // 运算符栈
    SqStack<int> opnd;  // 操作数栈
    char theta;
    int a, b;
    // 初始化运算符和操作数栈
    InitStack(optr);
    InitStack(opnd);
    // 表达式开始
    Push(optr, '#');
    // 读取一个运算符 op 或操作数 num
    isop = Read(op, num);
    // 当表达式未结束或还有未计算的运算符时继续
    while (isop == OPERAND || op != '#' || GetTop(optr) != '#')
    {
        // 处理运算符或操作数
        if (isop == OPERAND)
        { // 遇到操作数，直接入栈，继续读取
            Push(opnd, num);
            isop = Read(op, num);
        }
        else
        { // 遇到运算符，根据优先级分别处理
            switch (Precede(GetTop(optr), op))
            {
            case '<': // 栈顶运算符优先级低，运算符入栈，继续读取
                Push(optr, op);
                isop = Read(op, num);
                break;
            case '=': // 脱括号，继续读取
                Pop(optr, x);
                isop = Read(op, num);
                break;
            case '>': // 栈顶运算符优先级高，执行运算，结果入栈
                Pop(optr, theta);
                Pop(opnd, b);
                Pop(opnd, a);
                Push(opnd, Operate(a, theta, b));
                break;
            }
        }
    }

    return GetTop(opnd); // 返回运算结果
}

int main()
{
    cout << "Input an expression (support +-*/() and end with #)" << endl;
    int result = EvaluateExpression();
    cout << result << endl;

    return 0;
}