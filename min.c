// 23.10.8 16:01
// on class
// by HHC

#include <stdio.h>
// #include <limits.h>
#define NUM 5

int main()
{

    // VLA:variable-length array can not be initialized 不提倡使用变长数组
    // 预处理以可以初始化
    int numbers[NUM] = {0};

    // 局部变量i可以重名(限于for内声明，非是for前int i；)
    // scope作用域 since C99
    for (int i = 0; i < NUM; i++)
    {
        scanf("%d", &numbers[i]);
    }

    //[]: array subscripting operator
    int min = numbers[0];

    // for(init clause; condition expression; iteration expression ){loop-body} //iteration 迭代
    /*opration order: init clause(only one time )
                        condition expression
                        iteration expression
                        condition expression
                        iteration expression
                        ......
                        when the condition expression flase,run the code after the for loop
    */

    for (int i = 1; i < 5; i++)
    {
        if (numbers[i] < min)
        {
            min = numbers[i];
        }
    }

    printf("%d", min);

    return 0;
}

/* a,b,c
int main()
{
    int a = 0;
    int b = 0;
    int c = 0;

    scanf("%d%d%d", &a, &b, &c);

    int min = 0;

    if (a > b)
    {
        if (b > c)
        {
            min = c;
        }
        else
        {
            min = b;
        }
    }
    else // a <= b
    {
        if (a > c)
        {
            min = c;
        }
        else
        {
            min = a;
        }
    }

    printf("min(%d,%d,%d)=%d", a, b, c, min);

    return 0;
}
*/

/*  a,b
int main()
{
    int a = 0;
    int b = 0;

    scanf("%d%d", &a, &b);

    // TODO:calculate the minimum of a and b
    int min = 0;

    // // code style: reserve the space
    // if (a < b)
    // {
    //     min = a;
    // }
    // else
    // {
    //     min = b;
    // }

    // C语言唯一三元运算符，不要经常用，尤其不要嵌套用，不要代码压行
    // DO NOT TO BE TOO CLEVER
    min = a < b ? a : b;

    printf("min(%d,%d)=%d\n", a, b, min);

    return 0;
}
*/