///////////////////////////////////////
/// file: glis.h
/// 广义表
///////////////////////////////////////

#pragma once

///////////////////////////////////////
/// 存储结构

/// 结点标志
enum ElemTag { ATOM, LIST };

/// 广义表结点结构
template<typename E>
struct GLNode {
    ElemTag tag;
    union {
        E atom;
        struct {
            GLNode *hp, *tp;
        } ptr;
    };
};

/// 广义表类型
template<typename E>
using GList = GLNode<E>*;

///////////////////////////////////////
/// 基本操作

///
/// 求广义表的深度
///
template<typename E>
int GListDepth(GList<E> L)
{
    if (!L) return 1;  // 空表深度为 1
    if (L->tag == ATOM) return 0;  // 原子的深度为 0
    // 求各个子表的深度的最大值
    auto max = 0;
    for (auto p = L; p; p=p->ptr.tp) {
        auto dep = GListDepth(p->ptr.hp);
        if (dep > max) max = dep;
    }
    // 非空表的深度是深度是各元素的深度的最大值加 1
    return max + 1;
}


///
/// 复制广义表
///
template<typename E>
void CopyGList(GList<E> &T, GList<E> L)
{
    if (!L)  T = nullptr; // 复制空表
    else {
        T = new GLNode<E>;
        T->tag = L->tag;
        if (L->tag == ATOM) {
            T->atom = L->atom;
        } else {
            CopyGList(T->ptr.hp, L->ptr.hp);
            CopyGList(T->ptr.tp, L->ptr.tp);
        }
    }
}

///
/// 销毁广义表
///
template<typename E>
void DestroyGList(GList<E> &L)
{
    if (L==nullptr)  return;
    if (L->tag==ATOM) {
        delete L;
        L = nullptr;
    } else {
        DestroyGList(L->ptr.hp);
        DestroyGList(L->ptr.tp);
        delete L;
        L = nullptr;
    }
}


#include <string>
using std::string;

///
/// 建立广义表
///
string extract_head(string& s);  // 抽取表头
void CreateGList(GList<char>& L, const string& s)
{
    if (s=="()")  L = nullptr;
    else {
        L = new GLNode<char>;
        if (s.length()==1) {
            L->tag = ATOM;
            L->atom = s[0];
        } else {
            L->tag = LIST;
            auto p = L;
            auto sub = s.substr(1,s.length()-2);
            while (!sub.empty()) {
                auto hsub = extract_head(sub);
                CreateGList(p->ptr.hp, hsub);
                if (!sub.empty()) {
                    auto q = new GLNode<char>;
                    q->tag = LIST;
                    p->ptr.tp = q;
                    p = q;
                }
            }
            p->ptr.tp = nullptr;
        }
    }
}

string extract_head(string& s)
{
    int i, k = 0;
    for (i = 0; i<s.length(); i++) {
        if (s[i]=='(')  ++k;
        else if (s[i]==')')  --k;
        if (s[i]==',' && k==0) break;
    }
    if (i<s.length()) {
        auto h = s.substr(0,i);
        s = s.substr(i+1);
        return h;
    } else {
        auto h = s;
        s.clear();
        return h;
    }
}