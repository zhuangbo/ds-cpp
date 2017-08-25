///////////////////////////////////////
/// file: minmax_test.cpp
/// Find minmum and maximum elements
///////////////////////////////////////

///
/// 返回数组 a[n] 中最小的元素
///
template <typename T>
T min(T a[], int n)
{
    T tmp = a[0];
    for(int i=1; i<n; i++)
        if(a[i] < tmp)
            tmp = a[i];
    return tmp;
}

///
/// 返回数组 a[n] 中最大的元素
///
template <typename T>
T max(T a[], int n)
{
    T tmp = a[0];
    for(int i=1; i<n; i++)
        if(a[i] > tmp)
            tmp = a[i];
    return tmp;
}

///
/// 返回数组 a[n] 中最小的和最大的元素 min 和 max
/// 总计 2n-2 次比较
///
template <typename T>
void minmax(T a[], int n, T& min, T& max)
{
    min = max = a[0];
    for(int i=1; i<n; i++) {
        if(a[i] < min)
            min = a[i];
        if(a[i] > max)
            max = a[i];
    }
}

///
/// 返回数组 a[n] 中最小的和最大的元素 min 和 max
/// 总计 ⌈3n/2⌉-2 次比较
///
template <typename T>
void minmax2(T a[], int n, T& min, T& max)
{
    if(n==1) {
        min = max = a[0];
    } else {
        // 比较前两个
        if(a[0] < a[1]) {
            min = a[0];
            max = a[1];
        } else {
            max = a[0];
            min = a[1];
        }
        // 逐次取出两个元素比较
        for(int i=2; i<n-1; i+=2) {
            if(a[i] < a[i+1]) {
                if(a[i] < min) min = a[i];
                if(a[i+1] > max) max = a[i+1];
            } else {
                if(a[i] > max) max = a[i];
                if(a[i+1] < min) min = a[i+1];
            }
        }
        // n 为奇数时最后余下一个元素
        if(n&1) {
            if(a[n-1] < min) min = a[n-1];
            if(a[n-1] > max) max = a[n-1];
        }
    }
}


#include <iostream>
using std::cout;
using std::endl;

///
/// 测试最小值最大值
///
template <typename T>
void test(T a[], int n)
{
    // 测试数据
    cout << "{ ";
    for(int i=0; i<n; i++)
        cout << a[i] << " ";
    cout << "}" << endl;

    // 求最小值、最大值
    cout << min(a,n) << endl;
    cout << max(a,n) << endl;
    int x,y;
    minmax(a,n,x,y);
    cout << x << "," << y << endl;
    minmax2(a,n,x,y);
    cout << x << "," << y << endl;
}

///
/// 求最小值和最大值
///
int main()
{
    {
        int a[] = {3,1,4,1,5,9,2,6};
        int n = 8;
        test(a,n);
    }

    {
        int a[] = {2,7,1,8,2,8,4,5,9};
        int n = 9;
        test(a,n);
    }

    return 0;
}