// 23-9-15
// on class
// by HHC

/*
multi-line comment
*/
#include <stdio.h> //directive，指令；.h:header file 头文件;stdio:standard input/output
// main函数，不接受参数故（），知道返回的类型是int;C99开始必须在main前加int；（）中void可以省略，但提倡加上，特别是自己声明函数时
int main(void)
{
    printf("Hellow,World\n"); // 必须以分号结尾;printf是一个函数，引号内是字符串;"f"意为format
    return 0;                 // return statement (return to operating system);  0:exit code(正常时0，1不正常)
}