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
    if(opl=='(' && opr=='#') return 'X';
    if(opl=='#' && opr==')') return 'X';
    if(opl==')' && opr=='(') return 'X';
    // 括号匹配的情况
    if(opl=='#' && opr=='#') return '=';
    if(opl=='(' && opr==')') return '=';
    // 全 > 的情况
    if(opl==')' || opr==')' || opr=='#') return '>';
    // 全 < 的情况
    if(opl=='(' || opr=='(' || opl=='#') return '<';
    // 剩余 +-*/ 中 > 的情况
    if(opl=='*' || opl=='/' || opr=='+' || opr=='-') return '>';
    // 其他为 < 的情况
    if(opr=='*' || opr=='/') return '<';
    return 'X';  // 其他意外情况
}

///
/// 执行计算
///
int Operate(int a, char theta, int b)
{
    switch(theta) {
    case '+': return a+b;
    case '-': return a-b;
    case '*': return a*b;
    case '/': return a/b;
    }
    throw "Unknown operator";
}

/// 读取运算符或操作数，返回读取的第一个字符
/// 若为运算符，isop 为 true 且 op 返回运算符
/// 否则，num 返回操作数
char Read(bool& isop, char& op, int& num)
{
    char c = cin.peek();  // 查看输入流中的下一个字符
    while(isspace(c)) { cin.ignore(1); c = cin.peek(); } // 跳过空白
    isop = c<'0' || c>'9';  // 非数字即为运算符
    isop ? (cin >> op) : (cin >> num); // 读取运算符或操作数
    return c;
}

///
/// 输入表达式计算结果
/// 操作数为非负整数，运算符包括+-*/()，以#结尾
///
int EvaluateExpression() {
    char c, x;
    bool isop;  // 当前输入是运算符时为 true
    char op;    // 当前输入的运算符
    int num;    // 当前输入的操作数
    SqStack<char> optr;  // 运算符栈
    SqStack<int>  opnd;  // 操作数栈
    char theta;
    int a, b;
    // 初始化运算符和操作数栈
    InitStack(optr);
    InitStack(opnd);
    // 表达式开始
    Push(optr, '#');
    // 读取一个运算符 op 或操作数 num，读取操作数时 isop 为真
    c = Read(isop, op, num); // c 为第一个字符
    // 当表达式未结束或还有未计算的运算符时继续
    while(c!='#' || GetTop(optr)!='#') {
        // 处理运算符或操作数
        if(! isop) { // 遇到操作数，直接入栈，继续读取
            Push(opnd, num);
            c = Read(isop, op, num);
        } else {  // 遇到运算符，根据优先级分别处理
            switch(Precede(GetTop(optr), op)) {
            case '<':  // 栈顶运算符优先级低，运算符入栈，继续读取
                Push(optr, op);
                c = Read(isop, op, num);
                break;
            case '=':  // 脱括号，继续读取
                Pop(optr, x);
                c = Read(isop, op, num);
                break;
            case '>':  // 栈顶运算符优先级高，执行运算，结果入栈
                Pop(optr, theta);
                Pop(opnd, b); Pop(opnd, a);
                Push(opnd, Operate(a, theta, b));
                break;
            }
        }
    }

    return GetTop(opnd);  // 返回运算结果
}

int main()
{
    cout << "Input an expression (support +-*/() and end with #)" << endl;
    int result = EvaluateExpression();
    cout << result << endl;

    return 0;
}