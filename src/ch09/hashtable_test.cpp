///////////////////////////////////////
/// file: hashtable_test.cpp
/// Hash table test
///////////////////////////////////////

#include <iostream>
using namespace std;

#include "hashtable.h"

int main()
{
    // 关键字
    int keys[] = {19, 14, 23, 1, 68, 20, 85, 9};
    // 新建哈希表并初始化
    HashTable<int,11> H;
    InitHashTable(H);

    // 插入关键字
    for (auto key : keys)
        Insert(H,key);
    
    // 查找
    for (auto key : keys) {
        auto p = Find(H,key);
        if (p!=nullptr) {
            cout << "Key " << p->data << " found" << endl;
        } else {
            cout << "Key " << key << " NOT found" << endl;            
        }
    }

    // 打印哈希表结构
    int k = 0;
    for (auto p : H.table) {
        cout << k++ << " : ";
        for (auto q = p; q; q=q->next)
            cout << q->data << " -> ";
        cout << "/\\" << endl;
    }

    return 0;
}