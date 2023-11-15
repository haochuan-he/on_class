// 23.11.10
// on class: recurision--a function that calls itself
// by HHC

#include <stdio.h>

int Sum(const int nums[], int len);

int main()
{
    const int numbers[] = {1, 2, 3, 4, 5};

    // int sum = Sum(numbers, sizeof numbers / sizeof(int));
    int sum = Sum(numbers, sizeof numbers / sizeof(numbers[0]));
    printf("%d", sum);
    return 0;
}

int Sum(const int nums[], int len)
{
    if (len == 0) // find the smallest task to solve
    {
        return 0;
    }

    int partical_sum = Sum(nums, len - 1);

    return partical_sum + nums[len - 1];
}