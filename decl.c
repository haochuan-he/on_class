/**
 * file: decl.c
 *
 * Created by hengxin on 12/01/22.
 */

int main()
{
  char **argv;

  int *names[10]; // 指针数组，数组元素是指针，指针指向int

  int(*musician_score_table)[10]; // 指向数组的指针，数组每个元素是int

  int *StrCpyStd(char *dest, const char *src); // 函数接受两个char*，返回int *

  int (*comp)(const void *left, const void *right); // 函数指针

  int atexit(void (*func)(void)); // 函数，函数接受一个参数，参数又是一个函数指针，这个参数不接受参数，返回int

  void (*signal(int sig, void (*handler)(int)))(int);
  // signal是一个函数，接受两个参数，一个是int，一个是函数指针，指向的函数指向int，返回int;
  // 接受int，返回void

  char (*(*func(int num, char *str))[])();
  // func是一个函数，接受两个参数，返回一个指针，指针指向数组，数组中每个元素又是指针
  // 函数没有参数，返回char

  char(*(*arr[3])())[5];
  //
}