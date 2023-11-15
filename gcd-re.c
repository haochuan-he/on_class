// 23.11.10
// on class: recurision--a function that calls itself
// by HHC

// gcd(a , b)=gcd(b , a % b)

#include <stdio.h>

// version 2.0迭代
int GCD(int a, int b);
int main()
{
    int a = 130, b = 124;
    printf("GCD(%d,%d)=%d", a, b, GCD(a, b));

    return 0;
}

int GCD(int a, int b)
{
    while (b != 0)
    {
        int tem = a;
        a = b;
        b = tem % b;
    }

    return a;
}

// //version 1.0递归
// #include <stdio.h>

// int GCD(int a, int b);
// int main()
// {
//     int a = 130, b = 124;
//     printf("GCD(%d,%d)=%d", a, b, GCD(a, b));

//     return 0;
// }

// int GCD(int a, int b)
// {

//     if (b == 0)
//     {
//         return a;
//     }
//     return GCD(b, a % b);
// }