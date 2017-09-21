///////////////////////////////////////
/// file: sstring.h
/// 定长顺序表
///////////////////////////////////////

#pragma once

#include <stdexcept>
using std::length_error;

///////////////////////////////////////
/// 存储结构

/// 定长顺序串
const int MAXSTRLEN = 254;
typedef unsigned char SString[MAXSTRLEN+2];

///////////////////////////////////////
/// 基本操作

///
/// 创建串
///
void StrAssign(SString& T, const char *chars)
{
    int i = 1;
    auto p = chars;
    while (*p && i<=MAXSTRLEN) {
        T[i++] = *p++;
    }
    T[i] = '\0';  // 以 '\0' 结尾
    T[0] = i-1;       // 串长度
}

///
/// 清空串
///
void ClearString(SString& S)
{
    S[0] = 0;
    S[1] = '\0';
}

///
/// 判空
///
bool StrEmpty(SString S)
{
    return S[0] == 0;
}

///
/// 求长度
///
int StrLength(SString S)
{
    return S[0];
}

///
/// 串比较
///
int StrCompare(SString S, SString T)
{
    int i=1, j=1;
    while (i<=S[0] && j<=T[0] && S[i]==T[j]) {
        ++i; ++j;
    }
    return S[i]-T[j];
}

///
/// 串连接
///
void Concat(SString& T, SString S1, SString S2)
{
    for (int i=1; i<=S1[0]; i++) T[i] = S1[i];
    for (int j=1; j<=S2[0] && S1[0]+j<=MAXSTRLEN; j++) T[S1[0]+j] = S2[j];
    T[0] = S1[0]+S2[0]<=MAXSTRLEN ? S1[0]+S2[0] : MAXSTRLEN;
    T[T[0]+1] = '\0';
}

///
/// 求子串
///
void SubString(SString& Sub, SString S, int pos, int len)
{
    if (pos < 1) pos = 1;
    if (pos > S[0]) pos = S[0]+1;
    if (len < 0) len = 0;
    if (len > S[0]-pos+1) len = S[0]-pos+1;

    for (int i=1; i<=len; i++) {
        Sub[i] = S[pos+i-1];
    }
    Sub[0] = len;
    Sub[Sub[0]+1] = '\0';
}

///
/// 定位子串
///
int Index(SString S, SString T, int pos)
{
    int i = pos, j = 1;
    while (i<=S[0] && j<=T[0]) {
        if (S[i] == T[j]) { ++i; ++j; }
        else {
            i = i-j+2;  // 主串回溯
            j = 1;
        }
    }
    return j>T[0] ? i-T[0] : 0;
}
