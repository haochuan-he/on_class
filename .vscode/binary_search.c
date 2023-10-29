#include <stdio.h>
#define LEN 10

/**********************/
// VERY IMPROTAN !!!!!//
/**********************/

// // global variable
// // file scope
// int dictionary[LEN] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

// int dict[]:the address of the first element of thr array,not all elements in the array
int BinarySearch(int key, const int dict[], int len); // 数组[]内不写，写了编译器也会删除，没用
                                                      // 传入数组的长度来在写函数的时候使用，防止数组访问越界
                                                      // 对于字符串，可以不给长度，因为最后一位\0可以自己计算长度

int main()
{
    int dictionary[LEN] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

    int key = 0;
    scanf("%d", &key);

    // dictionary(actual argument实际参数):const int[]
    // dict(formal parameter):int []
    // C语言易错点：dictiona若为const int而函数为int，进入函数的时候会“擦除”const，使得数组被修改；
    // 故应该加const的地方一定要加
    int index = BinarySearch(key, dictionary, LEN);

    printf("index=%d", index);

    return 0;
}

int BinarySearch(int key, const int dict[], int len)
//"const": declare that the funtion will NOT modify the vatiable;
//
{
    int low = 0;
    int high = LEN - 1;
    int index = -1;
    while (low <= high)
    {

        int mid = (low + high) / 2;

        if (key > dict[mid])
        {
            low = mid + 1;
        }
        else if (key < dict[mid])
        {
            high = mid - 1;
        }
        else // key == dict[mid]
        {
            return mid;
        }
    }
    return -1;
}
/*
// 23.10.13
// on calss
// by HHC

// VERY IMPROTANT!!!

#include <stdio.h>
#define LEN 10

int dict[LEN] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

int main()
{
    int key = 0;
    scanf("%d", &key);

    int low = 0;
    int high = LEN - 1;
    int index = -1;
    while (low <= high)
    {

        int mid = (low + high) / 2;

        if (key > dict[mid])
        {
            low = mid + 1;
        }
        else if (key < dict[mid])
        {
            high = mid - 1;
        }
        else
        {
            index = mid;
            // break;
            // to find the left index
            high = mid - 1; // fantastic!
        }
    }
    printf("index=%d", index);

    return 0;
}
*/