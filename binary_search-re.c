// 23.11.10
// on class: recurision--a function that calls itself
// by HHC

#include <stdio.h>
#define LEN 10

int BinarySearch(int key, const int dict[], int low, int high);

int main()
{
    int dictionary[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int key;
    scanf("%d", &key);

    printf("the index of the key is %d \n", BinarySearch(key, dictionary, 0, sizeof dictionary / sizeof(dictionary[0])));

    return 0;
}

int BinarySearch(int key, const int dict[], int low, int high)
{
    // delete the repeative code by changi the base task
    // if (low == high)
    // {
    //     if (dict[low] == key)
    //     {
    //         return low;
    //     }
    //     else
    //     {
    //         return -1;
    //     }
    // }

    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;
    if (dict[mid] == key)
    {
        return mid;
    }

    if (dict[mid] > key)
    {
        return BinarySearch(key, dict, low, mid - 1);
    }
    else
    {
        return BinarySearch(key, dict, mid + 1, high);
    }
}
