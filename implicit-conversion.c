// 23.11.17
// on class: recursion && data types
// by HHC

// 隐式类型转换很危险，尤其是缩小范围的
#include <stdio.h>
#include <limits.h>
int SquareInt(int num);
int SquareDouble(double num);
int main()
{
    // narrowing conversion(still in the range)
    int i = 3.14159;

    // out of the range: undefined behaviors!!
    int j = UINT_MAX;

    // argument; narrowing conversion
    double pi = 3.14159;
    SquareInt(pi);

    // return value;narrowing conversion
    int k = 12;
    int val = SquareDouble(k);

    return 0;
}

int SquareInt(int num)
{
    return num * num;
}

int SquareDouble(double num)
{
    return num * num;
}