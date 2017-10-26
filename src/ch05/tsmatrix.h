///////////////////////////////////////
/// file: tsmatrix.h
/// 三元组顺序表
///////////////////////////////////////

#pragma once

///////////////////////////////////////
/// 存储结构

/// 三元组
template <typename E>
struct Triple
{
    int i, j; // 行下标和列下标
    E e;      // 元素值
};

template <typename E, int MS>
struct TSMatrix
{
    Triple<E> data[MS + 1]; // 非零元三元组表，data[0] 未用
    int mu, nu, tu;         // 矩阵行数、列数和非零元数
};

///////////////////////////////////////
/// 算法

///
/// 三元组顺序表矩阵 M 转置为 矩阵 T
///
template <typename E, int MS>
void FastTranspose(const TSMatrix<E, MS> &M, TSMatrix<E, MS> &T)
{
    T.mu = M.nu, T.nu = M.mu, T.tu = M.tu;
    if (T.tu == 0)
        return;
    // 求 M 中每列包含的非零元数量
    int num[MS + 1] = {0}; // num[...] = 0
    for (int t = 1; t <= M.tu; t++)
        num[M.data[t].j]++;
    // 计算每一列中第一个非零元的起始序号
    int cpot[MS + 1] = {0, 1}; // cpot[1] = 1
    for (int col = 2; col <= M.nu; col++)
        cpot[col] = cpot[col - 1] + num[col - 1];
    // 求每个元素的转置
    for (int p = 1; p <= M.tu; p++)
    {
        // 根据列下标得到该列的插入位置
        int col = M.data[p].j; // 列下标
        int q = cpot[col];     // 目标位置
        // 复制非零元
        T.data[q].i = M.data[p].j;
        T.data[q].j = M.data[p].i;
        T.data[q].e = M.data[p].e;
        // 更新该列的插入位置
        ++cpot[col];
    }
}