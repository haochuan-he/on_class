// 23.10.13
// on calss
// by HHC
#include <stdio.h>

int main()
{
    int lines = 0;

    scanf("%d", &lines);

    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < lines - i; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < 2 * i - 1; j++)
        {

            printf("*");
        }
        printf("\n");
    }

    return 0;
}