///////////////////////////////////////
/// file: kmp.h
/// KMP算法
///////////////////////////////////////

#pragma once

#include "ssting.h"

///
/// KMP算法
///
void get_next(SString,int[]);    // 计算失配函数值
void get_nextval(SString,int[]); // 计算修正的失配函数值

int Index_KMP(SString S, SString T, int pos)
{
    int next[MAXSTRLEN+2];
    get_nextval(T, next);
    int i = pos, j = 1;
    while (i<=S[0] && j<=T[0]) {
        if (j==0 || S[i] == T[j]) { ++i; ++j; }
        else j = next[j];
    }
    return j>T[0] ? i-T[0] : 0;
}

/// 根据模式串 T 计算失配函数值 next[]
void get_next(SString T,int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T[0]) {
        if (j==0 || T[i]==T[j]) {
            ++i; ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

/// 根据模式串 T 计算失配函数值 nextval[]
void get_nextval(SString T,int nextval[])
{
    int i = 1, j = 0;
    nextval[1] = 0;
    while (i < T[0]) {
        if (j==0 || T[i]==T[j]) {
            ++i; ++j;
            nextval[i] = T[i]!=T[j] ? j : nextval[j];
        } else {
            j = nextval[j];
        }
    }
}
