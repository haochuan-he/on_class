// 23.12.8
// on class

//  file: selection-sort-strings.c
//  Created by hfwei on 2023/12/07.

#include <stdio.h>
#include <string.h>

#define LEN 10

void SelectionSort(const char *arr[], int len);
int GetMinIndex(const char *arr[], int begin, int end);
void Swap(const char **left, const char **right);
void Print(const char *arr[], int len);
// const char *arr[],保护的是字面量，没有保护指针本身
// * const arr[],保护的是指针

int main(void)
{
  char *musicians[LEN] = {
      "Luo Dayou",   // 罗大佑
      "Cui Jian",    // 崔健
      "Dou Wei",     // 窦唯
      "Zhang Chu",   // 张楚
      "Wan Qing",    // 万青
      "Li Zhi",      // 李志
      "Yao",         // （某乐队）
      "ZuoXiao",     // 左小祖咒（跑调著称）
      "ErShou Rose", // 二手玫瑰
      "Hu Mage"      // 胡吗个？
  };
  // 声明的语法和表达式的语法一样，查表可知 *的优先级大于[]————
  // 指针数组 *musicians[]，每一位储存一个指针

  Print(musicians, LEN);
  SelectionSort(musicians, LEN);
  Print(musicians, LEN);

  return 0;
}

void SelectionSort(const char *arr[], int len)
{
  for (int i = 0; i < len; i++)
  {
    int min_index = GetMinIndex(arr, i, len);

    // Swap plus: do not exchange the string, just exchange the two pointers
    // arr: char *[] ; now the [] is * ; => arr is char** now
    // const char ** 传递给char **会使得const被抹除
    Swap(arr + i, arr + min_index);
  }
}

int GetMinIndex(const char *arr[], int begin, int end)
{
  const char *min = arr[begin];
  int min_index = begin;

  for (int i = begin + 1; i < end; ++i)
  {
    if (strcmp(arr[i], min) < 0)
    {
      min = arr[i];
      min_index = i;
    }
  }

  return min_index;
}

void Swap(const char **left, const char **right)
// plus: do not exchange the string, just exchange the two pointers
{
  const char *temp = *left;
  *left = *right;
  *right = temp;
}

void Print(const char *arr[], int len)
{
  for (int i = 0; i < len; i++)
  { // arr[i]
    printf("%s ", arr[i]);
  }
  printf("\n");
}

// "Luo Dayou",
// "Cui Jian",
// "Dou Wei",
// "Zhang Chu",
// "Wan Qing",
// "Li Zhi",
// "Yao",
// "ZuoXiao",
// "ErShou Rose",
// "Hu Mage",
/*// file: selection-sort-strings.c
// Created by hfwei on 2023/12/07.

#include <stdio.h>

#define LEN 5

void SelectionSort(int arr[], int len);
int GetMinIndex(int arr[], int begin, int end);
void Swap(int *left, int *right);
void Print(int arr[], int len);

int main(void)
{
  int numbers[LEN] = {15, 78, 23, 8, 50};

  Print(numbers, LEN);
  SelectionSort(numbers, LEN);
  Print(numbers, LEN);

  return 0;
}

void SelectionSort(int arr[], int len)
{
  for (int i = 0; i < len; i++)
  {
    int min_index = GetMinIndex(arr, i, len);

    Swap(arr + i, arr + min_index);
  }
}

int GetMinIndex(int arr[], int begin, int end)
{
  int min = arr[begin];
  int min_index = begin;

  for (int i = begin + 1; i < end; ++i)
  {
    if (arr[i] < min)
    {
      min = arr[i];
      min_index = i;
    }
  }

  return min_index;
}

void Swap(int *left, int *right)
{
  int temp = *left;
  *left = *right;
  *right = temp;
}

void Print(int arr[], int len)
{
  for (int i = 0; i < len; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// "Luo Dayou",
// "Cui Jian",
// "Dou Wei",
// "Zhang Chu",
// "Wan Qing",
// "Li Zhi",
// "Yao",
// "ZuoXiao",
// "ErShou Rose",
// "Hu Mage",*/