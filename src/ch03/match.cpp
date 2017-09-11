///////////////////////////////////////
/// file: match.cpp
/// 括号匹配的检验
///////////////////////////////////////

#include <iostream>
#include "sqstack.h"

using namespace std;

///
/// 输入一行字符串，检验其中括号是否匹配
///
bool match(const char *expr)
{
    // 匹配括号
    SqStack<char> s;
    InitStack(s);
    for(int i = 0; expr[i]; i++) {
        char c = expr[i];
        if(c=='(' || c=='[' || c=='{') {
            // 左括号入栈
            Push(s,c);
        } else if(c==')' || c==']' || c=='}') {
            // 右括号与栈顶括号进行匹配
            if(StackEmpty(s)) return false; // 栈空则匹配失败
            // 出栈
            char b;
            Pop(s,b);
            // 匹配失败则返回
            if(( c==')' && b!='(' ) ||
              ( c==']' && b!='[' ) ||
              ( c=='{' &&b !='}' ))
                return false;
        }
    }

    // 若栈空，则匹配成功
    return StackEmpty(s);
}


int main()
{
    const int N = 5;
    const char *expr[N] = {
        "([]())",
        "[([][])]",
        "[([][]]",
        "[([][])])",
        "(([][])]",
    };

    for(int i=0; i<N; i++) {
        cout << expr[i] << " match = "
            << boolalpha << match(expr[i]) << endl;
    }
    
    return 0;
}