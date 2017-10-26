///////////////////////////////////////
/// file: infixtopostfix.cpp
/// 中缀表达式转化为后缀表达式
//////////////////////////////////////

#include <iostream>
#include "sqstack.h"
using namespace std;

///
/// 运算符（+-*/()）之间的优先级关系
///
char Precede(char opl, char opr)
{
    // 语法错误
    if (opl == ')' && opr == '(')
        return 'X';
    // 括号匹配的情况
    if (opl == '(' && opr == ')')
        return '=';
    // 全 > 的情况
    if (opl == ')' || opr == ')')
        return '>';
    // 全 < 的情况
    if (opl == '(' || opr == '(')
        return '<';
    // 剩余 +-*/ 中 > 的情况
    if (opl == '*' || opl == '/' || opr == '+' || opr == '-')
        return '>';
    // 其他为 < 的情况
    if (opr == '*' || opr == '/')
        return '<';
    return 'X'; // 其他意外情况
}

/// 判断是否是运算符（+-*/()）
bool IsOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

///
/// 输入中缀表达式（操作数为单字母，等号=结束）转换为后缀表达式输出
///
void InfixToPostfix()
{
    SqStack<char> S; // 运算符栈
    char c, op;
    // 初始化运算符栈为空
    InitStack(S);
    // 读取一个字符（运算符或操作数）
    cin >> skipws >> c; // skipws 跳过空白符
    // 转换表达式直到遇到等号
    while (c != '=')
    {
        if (!IsOperator(c))
        { // 非运算符即操作数
            // 遇到操作数，直接输出，继续读下一个字符
            cout << c;
            cin >> skipws >> c;
        }
        else
        { // 遇到运算符
            if (StackEmpty(S))
            { // 运算符栈空
                // 运算符入栈，继续读下一个字符
                Push(S, c);
                cin >> skipws >> c;
            }
            else
            { // 运算符栈不空
                // 栈顶运算符与 c 比较优先级
                char p = Precede(GetTop(S), c);
                // 根据优先级分别处理
                if (p == '<')
                { // 栈顶运算符优先级低
                    // 运算符入栈，继续读下一个字符
                    Push(S, c);
                    cin >> skipws >> c;
                }
                else if (p == '>')
                { // 栈顶运算符优先级高
                    // 栈顶运算符出栈并输出
                    Pop(S, op);
                    cout << op;
                }
                else
                { // 优先级相等（括号匹配）
                    // 出栈不输出（脱括号），继续读下一个字符
                    Pop(S, op);
                    cin >> skipws >> c;
                }
            }
        }
    }

    // 输出栈中剩余的运算符
    while (!StackEmpty(S))
    {
        Pop(S, op);
        cout << op;
    }
    cout << endl;
}

int main()
{
    cout << "Input an infix expression (support +-*/(), char as operand, end with =)" << endl;
    cout << "e.g. input a+b*(c-d)-e/f=, get abcd-*+ef/-" << endl;

    InfixToPostfix();

    return 0;
}