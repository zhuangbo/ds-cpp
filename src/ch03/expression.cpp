#include <iostream>
using namespace std;


char Precede(char opl, char opr)
{
    if(opl=='#' && opr=='#') return '=';
    if(opl=='(' && opr==')') return '=';
    if(opl=='(' && opr=='#') return 'X';
    if(opl=='#' && opr==')') return 'X';
    if(opl==')' && opr=='(') return 'X';

    if(opr=='#' || opl==')' || opr==')') return '>';
    if(opl=='#' || opl=='(' || opr=='(') return '<';
    if(opl=='*' || opl=='/' || opr=='+' || opr=='-') return '>';
    return '<';
}

int main()
{
    char ops[] = {"+-*/()#"};
    char pre[][8] = {
        ">><<<>>",
        ">><<<>>",
        ">>>><>>",
        ">>>><>>",
        "<<<<<=X",
        ">>>>X>>",
        "<<<<<X=",
    };

    for(int i=0; i<7; i++) {
        for(int j=0; j<7; j++) {
            cout << (Precede(ops[i], ops[j])==pre[i][j] ? '.' : '@');
        }
        cout << endl;
    }
}