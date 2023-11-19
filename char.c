// 23.11.17
// on class: recursion && data types
// by HHC

#include <stdio.h>

int main()
{
    // char c = 150; // char虽然比int 少占字节，但是不要用char表示小整数；
    unsigned char c = 150;
    // 也不要假设unsighed char || sighed char 这不确定，没有在C标准中规定
    int i = 900;

    printf("i/c=%d\n", i / c);

    return 0;
}
