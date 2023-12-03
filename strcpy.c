//
// file: strcpy.c
// 7 versions of strcpy
// Created by hfwei on 2022/11/29.
//
// C Operator Precedence: https://en.cppreference.com/w/c/language/operator_precedence#:~:text=C%20Operator%20Precedence%20%20%20%20Precedence%20,union%20member%20access%20%2028%20more%20rows%20
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void StrCpy(char *dest, const char *src);
void StrCpy1(char *dest, const char *src);
void StrCpy2(char *dest, const char *src);
void StrCpy3(char *dest, const char *src);
void StrCpy4(char *dest, const char *src);
void StrCpy5(char *dest, const char *src);

char *StrCpyStd(char *dest, const char *src);

int main()
{
  const char *src = "Hello World";
  char *dest = malloc(strlen(src) + 1); //+1 for '\0'

  StrCpy5(dest, src);

  printf("dest = %s\n", dest);

  return 0;
}

char *StrCpyStd(char *dest, const char *src)
{
  for (char *s = dest; (*s++ = *src) != '\0';)
    ;
  return dest; // 这样使得可以在main中方便地连用  strlen( StrCpyStd(dest,src));
}

void StrCpy5(char *dest, const char *src)
{ // \0 : NULL ; 0 在计算机中表示的值就是0,真正的整数0
  // NULL: null pointer  空指针 ;(void *)0 转化成了指针的0
  // Not Recommended!!!
  while (*dest++ = *src++)
    ;
}
void StrCpy4(char *dest, const char *src)
{ // dest++: dest + 1,but the value of dest++ is dest (evaluated to dest)
  // 注意： 这段程序结束后dest src指向\0后面的一位
  while ((*dest++ = *src++) != '\0')
    ;
}

void StrCpy3(char *dest, const char *src)
{
  while ((*dest = *src) != '\0')
  {
    dest++;
    src++;
  }
}

void StrCpy2(char *dest, const char *src)
{
  int i = 0;
  // src[i] : *(src+i)
  while ((*(dest + i) = *(src + i)) != '\0')
  {
    i++;
  }
}

void StrCpy1(char *dest, const char *src)
{
  int i = 0;
  while ((dest[i] = src[i]) != '\0')
  {
    i++;
  }
}

void StrCpy(char *dest, const char *src)
{
  int i = 0;
  while (src[i] != '\0')
  {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
}
