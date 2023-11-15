// 23.11.10
// on class: recurision--a function that calls itself
// by HHC

#include <stdio.h>
#define NUM 3
const int numbers[NUM] = {65, 28, 37}; // static variable 静态变量，与程序的生命周期相同
int Min(const int nums[], int len);

int main()
{
    int min = Min(numbers, NUM);
    printf("%d", min);
    return 0;
}

int Min(const int nums[], int len)
{
    if (len == 1) // solve the base task
    {
        return nums[0];
    }

    int partial_min = Min(nums, len - 1); // solve the smaller task

    return partial_min < nums[len - 1] ? partial_min : nums[len - 1];
}

// VERSION 1.0

// #include <stdio.h>

// int Min(int a, int b);

// int main()
// {
//     int a = 25, b = 37; // local variable（作用域）; automatic variable（生命周期角度，自动变量随着函数的生命周期而存在）

//     int min = Min(a, b);
//     printf("%d", min);

//     return 0;
// }

// int Min(int a, int b)
// {
//     return a > b ? b : a;
// }