// 23.10.13
// on calss
// by HHC
#include <stdio.h>

void Print(char ch, int count);

int main()
{
    int lines = 0;

    scanf("%d", &lines);

    for (int i = 0; i < lines; i++)
    {
        // // print lines - 1 - i spaces
        // for (int j = 0; j < lines - i; j++)
        // {
        //     printf(" ");
        // }
        Print(' ', lines - 1 - i);
        Print('*', 2 * i + 1);
        // print 2 * i + 1 stars
        //     for (int j = 0; j < 2 * i - 1; j++)
        // {

        //     printf("*");
        // }
        printf("\n");
    }

    return 0;
}

void Print(char ch, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%c", ch);
    }
}