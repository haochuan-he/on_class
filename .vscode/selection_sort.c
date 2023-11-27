// 23.11.24
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int len = 0;
    scanf("%d", &len);
    // malloc: void *malloc(size_t size)
    // size_t size: unsigned long / long long  --- So ensure the size is positive
    //  int *numbers = malloc(len * sizeof(int)); // void *malloc,可转成任何想要的指针类型
    int *numbers = malloc(len * sizeof(*numbers)); // sizeof(*numbers)可以使得修改*numbers类型的时候仍然正确

    // NULL :null pointer ((void*)0)
    if (numbers == NULL) // 判断返回的是不是空指针来判断 malloc是否成功分配内存,并决定程序是否继续进行
    {
        return 0;
    }

    for (int i = 0; i < len; i++)
    {
        scanf("%d", &numbers[i]);
    }

    // malloc 分配的内存在“堆空间”(heap)中,当main函数结束的时候，栈空间(stack)的main还给了操作系统，但堆空间中的内存一直被占用
    //--"内存泄漏"，当复杂程序长时间运行的时候会不断泄露内存(但小型程序结束后操作系统会回收所有栈空间和堆空间)
    free(numbers);
    // void free(void *point);
    //  不能多次free，UBs
    //  之后不能再对numbers操作
    //  不能free其他变量，即不应该free栈空间，只能free由malloc动态申请的堆空间

    return 0;
}

/*
// 23.10.13
// on calss
// by HHC

// select the min or max in the array,do it many times

#include <stdio.h>
#define LEN 20

int main()
{
    int numbers[LEN] = {0};
    int len = -1;
    while (scanf("%d", &numbers[++len]) != EOF)
        ;
    // 空语句{ ; }

    // scanf return:
    //      input failure(EOF,end of file,usually=-1)
    //      numbers of matched items

    // 换行的时候才会把缓冲区的内容发送给scanf
    // ubuntu环境下 换行再在行的开始ctrl+d 或者 在行的末尾按两次ctrl+d 可以输出EOF
    //      ctrl +d 是强行把缓冲区的内容交给scanf（原理是在缓冲区为空的时候输出EOF，enter或者前一次crlt+d可以实现“清空”缓冲区）
    // 在run下，可能不起作用，是clion本身的bug
    // windos下，可能ctrl+z，或者都无效

    // 除了标准输入（控制台），可以从文件里读入数据（输入重定向）
    // 同理，还有输出重定向，结果显示在另一个文件而非控制台
    // OJ系统也是使用这种方法
    for (int i = 0; i < len; i++)
    {

        printf("%d", numbers[i]);
    }

    printf("\n");

    for (int i = 0; i < len; i++)
    {
        int min = numbers[i];
        int min_index = i;
        for (int j = i + 1; j < len; j++)
        {
            if (numbers[j] < min)
            {
                min = numbers[j];
                min_index = j;
            }
        }

        int temp = 0;
        temp = numbers[min_index];
        numbers[min_index] = numbers[i];
        numbers[i] = temp;
    }

    for (int m = 0; m < len; m++)
    {
        printf("%d ", numbers[m]);
    }
    return 0;
}
*/