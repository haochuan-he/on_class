// 23.11.24
// on class: pointers and arrays(3+2=5)
//
// THREE SENTENCES FOR POINTERS :
// A variavle has its type,value,and address;
// A variable can be used as a lvalue or a rvalue(左值/右值);
// A pointer is a variable that contains the address of a variable.
//
// TWO SENTENCES FOR ARRAYS :
// In expressions,the name of an array is a synonym for the address of its first element;
// But an array name is NOT a pointer.
//
// by HHC

#include <stdio.h>
#define PI 3.1415926535

int main()
{
    int radius1 = 100; // type:int ,value:100,address: &radius(&:address-of operator)

    printf("radius=%d\n", radius1);
    printf("&radius=%p\n", &radius1); // do not use %d of %s,just use %p

    radius1 = 150;                           // radius is used as left value
    double circumference = 2 * PI * radius1; // radius is used as right value
    printf("circumference=%f\n", circumference);

    int *ptr_radius1 = &radius1; // type int *;value: &radius1;address:&ptr_radius
    // int* prt_radius1  is also legal,but do NOT use this;
    // int * prt_radius1 is alse legal ,but do NOT use this ,too.

    printf("&prt_radius=%p\n", &ptr_radius1);

    int radius_1 = 1000;
    int *ptr_radius_1 = &radius_1;

    // ptr_radius1 = ptr_radius_1; // 两个指针同时指向radius_1;

    *ptr_radius1 = 200; // used as lvalue
    printf("radius1=%d\n", radius1);
    circumference = 2 * PI * (*ptr_radius1); // used as right value

    ptr_radius1 = ptr_radius_1;
    *ptr_radius_1 = 2000;
    printf("radius_1=%d\n", *ptr_radius1);
    // * :indirection/derefernce operatot;
    //*ptr_radius1 behaves like radius1

    //--WRONG--
    int v = 100;
    int *pv = &v;
    pv = &pv; // 类型不匹配，双重指针int **

    //--WRONG--
    int arr[] = {1, 2, 3, 12};
    arr = arr + 1; // the name of an array can NOT be changed,can NOT be used as lvalue
    return 0;
}
