// 23.11.17
// on class: recursion && data types
// by HHC

// John von Neumann 1945
// the smaller task:depart the original list into two half lists;
//                  mergesort the two lists;
//                  merge the sorted two part into the original ans

#include <stdio.h>

#define LEN 7

void Mergesort(int nums[], int left, int right);
void Merge(int nums[], int left, int mid, int right);
/**一个/加两个**，换行自动补全:文档注释
 * sort nums[left...right]
 *
 *
 */

int main()
{
    int numbers[LEN] = {4, 8, 6, 5, 12, 2, 3};
    for (int i = 0; i < LEN; i++)
    {
        printf("%d", numbers[i]);
    }
    return 0;
}

void Mergesort(int nums[], int left, int right)
{
    if (left == right) // the base task
    {
        return;
    }

    // deal with subtasks
    int mid = (right + left) / 2;
    Mergesort(nums, left, mid);
    Mergesort(nums, mid + 1, right);

    Merge(nums, left, mid, right);
}

void Merge(int nums[], int left, int mid, int right)
{
    // in_place 原地合并(此处未用，而是复制了一个数组来进行操作，再把值复制回去)
    // int copy[LEN] = {0};//否则每次调用Merge都会开一个数组，占用空间

    static int copy[LEN] = {0}; // 只会开一次数组

    int left_index = left;
    int right_index = right;
    int copy_index = left;

    while (left_index <= mid && right_index <= right)
    {
        if (nums[left_index] <= nums[right_index])
        {
        }
    }

    while (left_index <= mid)
    {
        copy[copy_index] = nums[right_index]
    }
}
