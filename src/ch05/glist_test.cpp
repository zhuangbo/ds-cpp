///////////////////////////////////////
/// file: glist_test.cpp
/// 广义表测试
///////////////////////////////////////

#include <iostream>
using namespace std;
#include "glist.h"

void Print(const GList<char>& L)
{
    if (L==nullptr)  cout << "()";
    else if (L->tag==ATOM)  cout << L->atom;
    else {
        cout << "(";
        for(auto p=L; p; p=p->ptr.tp) {
            Print(p->ptr.hp);
        }
        cout << ")";
    }
}

int main()
{
    GList<char> L;

    CreateGList(L,"((),(e),(a,(b,c,d)))");
    Print(L); cout << endl;

    cout << "Depth: " << GListDepth(L) << endl;
    
    GList<char> C;
    CopyGList(C,L);
    Print(C); cout << endl;

    DestroyGList(L);
    DestroyGList(C);
    
    return 0;
}