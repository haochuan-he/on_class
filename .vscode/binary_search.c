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