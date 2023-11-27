// 23.11.24
// on class: pointers and arrays(3+2=5)
//
// THREE SENTENCES FOR POINTERS :
// A variavle has its type,value,and address;
// A variable can be used as a lvalue or a rvalue(左值/右值);
// A pointer is a variable that contains the address of a variable.
//
// TWO SENTENCES FOR ARRAYS :
// by HHC

#include <stdio.h>

void Swap(int *a, int *b);

int main()
{
    int a = 1, b = 10;
    printf("a=%d b=%d\n", a, b);
    Swap(&a, &b);
    printf("a=%d b=%d\n", a, b);

    return 0;
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
