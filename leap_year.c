// 23.10.8 16:01
// on class
// by HHC

#include <stdio.h>

int main()
{
    int year = 0;
    scanf("%d", &year);

    // boolean variable; indicator ,flag
    int leap = 0;

    // TODO: leap year or not

    // 代码压行
    //   if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
    //  {
    //      printf("%d is a leap year\n", year);
    //  }
    //  else
    //  {
    //      printf("%d is a NOT leap year\n", year);
    //  }

    // 找充要条件，逻辑语句一步判断
    // 注意存在“短路求值”
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
    {
        leap = 1;
    }
    else
    {
        leap = 0;
    }

    // // 级联if else语句
    // if (year % 4 != 0)
    // {
    //     leap = 0;
    // }
    // else if (year % 100 != 0)
    // {
    //     leap = 1; // year % 4 ==0 && year % 100 !=0
    // }
    // else if (year % 400 != 0)
    // {
    //     leap = 0;
    // }
    // else
    // {
    //     leap = 1; //year % 400 == 0
    // }

    // if (year % 4 != 0)
    // {
    //     leap = 0;
    // }
    // else
    // {
    //     if (year % 100 != 0)
    //     {
    //         leap = 1;
    //     }
    //     else
    //     {
    //         if (year % 400 != 0)
    //         {
    //             leap = 0;
    //         }
    //         else
    //         {
    //             leap = 1;
    //         }
    //     }
    // }

    // 箭头式代码，不美观
    //  if (year % 4 == 0) // double =
    //  {
    //      if (year % 100 == 0)
    //      {
    //          if (year % 400 == 0)
    //          {
    //              leap = 1;
    //          }
    //          else
    //          {
    //              leap = 0;
    //          }
    //      }
    //      else
    //      {
    //          leap = 1;
    //      }
    //  }
    //  else
    //  {
    //      leap = 0;
    //  }

    // output
    if (leap == 1)
    {
        printf("%d is a leap year\n", year);
    }
    else
    {
        printf("%d is a NOT leap year\n", year);
    }

    return 0;
}