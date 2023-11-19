// 23.11.17
// on class: recursion && data types
// by HHC

// size_t: typedef unsighed long long int size_t 真实情况被编译器和平台隐藏了

#include <stdio.h>

int main()
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 12};
    int i = -1;

    size_t size = sizeof array; // 可以摁住ctrl点击size_t
    printf("The size of the array is %d\n ", size);

    if (i <= size)
    {
        printf("i<=sizeof array\n");
    }
    else
    {
        printf("i>sizeof arrzy\n");
    }

    return 0;
}
