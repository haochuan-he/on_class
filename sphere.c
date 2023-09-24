// 2023.9.24
// review after class
// by HHC
#include <stdio.h>
int main(void)
{
    const double PI = 3.1415926535;
    double radius = 100, surface_area, volume;

    surface_area = 4.0 * PI * radius * radius;
    volume = 4.0 / 3 * PI * radius * radius * radius;
    //.4:precision
    // 15:minimun width
    //-:flag(left-justified)
    printf("%-15.4f:surface_area\n%-15.4f:volume", surface_area, volume);

    return 0;
}