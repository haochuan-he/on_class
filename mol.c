// 2023.9.24
// after class review
// by HHC
#include <stdio.h>
int main(void)
{
    const double NA = 6.02e+23, MASS_PRE_MOL = 32;
    double mass = 6, quantity;
    quantity = mass / MASS_PRE_MOL * NA;
    // e:exponent
    // g:significant digits
    printf("%.3e\n%.4e\n", quantity, quantity);
    // another way:.5g
    printf("%.5g", quantity);
    return 0;
}