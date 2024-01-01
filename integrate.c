//
// file: integrate.c
// Created by hfwei on 2023/12/13.
// A nice function pointer example on Riemann integration:
// https://en.wikipedia.org/wiki/Function_pointer
//

#include <stdio.h>
#include <math.h>

#define NUM_OF_PARTITIONS 100000

double Integrate(double low, double high,
                 double (*func)(double)); // must *(func), *func(double) is wrong

double Square(double x);
int main()
{
  double low = 0.0;
  double high = 1.0;
  double integration = 0.0;

  integration = Integrate(low, high, sin); // sin会被C语言隐式转换为函数指针，可以不取地址;实际上平时调用sin(1.0)的时候也存在隐式转换

  printf("Sin(0.0 ... 1.0)=%lf\n", integration);

  integration = Integrate(low, high, cos);
  printf("Cos(0.0 ... 1.0)=%lf\n", integration);

  integration = Integrate(low, high, Square);
  printf("Square(0.0 ... 1.0)=%lf\n", integration);

  double (*funcs[])(double) = {sin, cos, Square};
  // 解释： 首先是数组，数组有三个元素，每个元素是一个指针；
  // 指针指向一个函数，这个函数接受double，返回double

  for (int i = 0; i < 3; i++)
  {
    printf("integration=%f\n",
           Integrate(low, high, funcs[i]));
  }
  return 0;
}

double Integrate(double low, double high, double (*func)(double))
{
  double interval = (high - low) / NUM_OF_PARTITIONS;

  double sum = 0.0;
  for (int i = 0; i < NUM_OF_PARTITIONS; i++)
  {
    double xi = low + interval * i;
    double yi = func(xi); // 使用形参名即可,会有隐式转换，可以不用解引用，写成 (*func)(xi) 也可以，
                          // 但是解引用之后马上就会隐式转换，实际上解引用多少次都没用 (********func)(xi)
    sum += yi * interval;
  }

  return sum;
}
double Square(double x)
{
  return x * x;
}