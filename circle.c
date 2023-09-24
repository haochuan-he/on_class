// 23.9.24
// after class,to review
// byHHC

#include <stdio.h>

int main(void)
{
    int radius = 10;

    // avoid magic number
    const double PI = 3.141592653589793;

    double circumference = 2 * PI * radius;
    double area = PI * radius * radius;

    //%d:decimal
    //.2:precision
    printf("radius=%d\n circumference=%.2f\n "
           "area = % .2f\n ",
           radius,
           circumference, area);

    return 0;
}