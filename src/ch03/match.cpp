///////////////////////////////////////
/// file: match.cpp
/// 括号匹配的检验
///////////////////////////////////////

#include <iostream>
#include <iomanip>  // for std::setw
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
            Push(s,c);
        } else if(c==')') {
            if(StackEmpty(s)) {
                cout << expr << endl;
                cout << setw(i+1) << '^' << " : 多余的 )" << endl;
                return false;
            }
            char b;
            Pop(s,b);
            if(b!='(') {
                cout << expr << endl;
                cout << setw(i+1) << '^' << " : 匹配错误 )" << endl;
                return false;
            }
        } else if(c==']') {
            if(StackEmpty(s)) {
                cout << expr << endl;
                cout << setw(i+1) << '^' << " : 多余的 ]" << endl;
                return false;
            }
            char b;
            Pop(s,b);
            if(b!='[') {
                cout << expr << endl;
                cout << setw(i+1) << '^' << " : 匹配错误 ]" << endl;
                return false;
            }
        } else if(c=='}') {
            if(StackEmpty(s)) {
                cout << expr << endl;
                cout << setw(i+1) << '^' << " : 多余的 }" << endl;
                return false;
            }
            char b;
            Pop(s,b);
            if(b!='{') {
                cout << expr << endl;
                cout << setw(i+1) << '^' << " : 匹配错误 }" << endl;
                return false;
            }
        }
    }

    // 若栈空，则匹配成功
    if(StackEmpty(s)) {
        cout << expr << endl;
        cout << "匹配成功" << endl;
        return true;
    } else {
        cout << expr << endl;
        cout << "缺少右括号" << endl;;
        return  false;
    }
}


int main()
{
    match("([]())");
    match("[([][])]");
    match("[([][]]");
    match("[([][])])");
    match("(([][])]");
    
    return 0;
}