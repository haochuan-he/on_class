//
// Created by hfwei on 2022/12/8.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef enum gender // 枚举类型,成员习惯上全大写
// 枚举类型机器实现的时候实际上是一个数（整形），这个特性很不安全，比如允许 gender='M'赋值一个数，但没有意义
{
  MALE,
  FEMALE
} Gender;

typedef struct score
{
  int c_score;
  int java_score;
  int python_score;
} Score;

// struct musician
// struct musician : tag
//  struct定义了一个类型，后面跟一个名字有用于指代{}中的信息，最后的是声明属于这个类型的变量
typedef struct musician
{
  // alignment(对齐) 内存中需要地址对齐，所以Musician这个类型所占空间可能会大于每个成员加起来所占空间；此处成员之和为29，实际是40
  // CPU一次读一个字word,而不是字节byte
  // 1. 找出成员中占用最大的（*name,*album 8 bytes）,则会从地址%8==0的地方开始存储,结尾的时候也要%8==0
  //    如果结尾的地址%8！=0，会填充一些字节使得最后结尾的地址能被8整除
  // 2. gender要求%1==0，可以直接存在*name后面
  // 3. *album要求模8==0，因为gender存了，不能满足，故要填充7个字节，然后再存
  // 总和：8+1+7(填充)+8+4+4+4+4(一次读一个word,此平台是8个byte，结尾填充)
  char *name; // 成员member,域field  //8 bytes
  // char gender; // 1 byte
  Gender gender;

  char *album; // 8

  Score score;

  // int c_score;      // 4
  // int java_score;   // 4
  // int python_score; // 4
} Musician; // Musician 是typedef后的别名
// } luo, cui, zhang, *musician_ptr;

// void PrintMusician(const Musician m);
void PrintMusician(const Musician *m);

int CompareMusician(const void *m1, const void *m2);

int main()
{
  // printf("sizeof Musician=%zu\n", sizeof(Musician));
  struct musician luo =
      {
          // "Luo Dayou", 'M', "ZhiHuZheYe", 0, 10, 20 //可以按照成员的顺序挨个初始化

          // 指示器初始化，指定某个成员进行赋值;不必按照顺序；可以某些成员不赋值而隐式地初始化为0
          .name = "Luo Dayou",
          // .gender = 'M',
          .gender = MALE,
          .album = "ZhiHuZheYe",
          // .c_score = 0,
          // .java_score = 10,
          // .python_score = 20};

          // .score.c_score = 0, // 可以两次 . 来访问成员，但不推荐这样，可读性不高

          .score = {
              .c_score = 0,
              .java_score = 10,
              .python_score = 20,
          },
      };

  struct musician cui =
      {
          .name = "Cui Jian",
          // .gender = 'M',
          .gender = MALE,

          .album = "XinChangZhengLuShangDeYaoGun",
          .score = {
              .c_score = 0,
              .java_score = 10,
              .python_score = 20,
          },
      };

  char album[] = "YiKeBuKeMeiSuDeXin";
  struct musician zhang =
      {

          .name = "Zhang Chu",
          // .gender = 'M',
          .gender = MALE,
          // .album = "YiKeBuKeMeiSuDeXin",
          .album = album,
          .score = {
              .c_score = 0,
              .java_score = 10,
              .python_score = 20,
          },
      };

  Musician guo = zhang;
  // 结构体赋值,完全的拷贝
  // 特别注意指针赋值之后指向同一个对象，修改其中一个会牵扯到另一个

  guo.name = "Guo";                    // 此处是让guo.name这个指针指向"Guo"，并不会改动"Zhang Chu"
  strcpy(guo.album, "YiKeMeiSuDeXin"); // strcpy的时候通过指针修改了album[]的内容，所以张楚和郭富城输出的专辑一样

  // PrintMusician(&guo);
  // PrintMusician(&zhang);

  Musician musicians[] = {luo, cui, zhang};
  int len = sizeof musicians / sizeof *musicians;
  for (int i = 0; i < len; i++)
  {
    qsort(musicians, len, sizeof *musicians, CompareMusician);
  }

  return 0;
}

// m1,m2 : Musician * 指向Musician的指针
int CompareMusician(const void *m1, const void *m2)
{
  const Musician *left = m1;
  const Musician *right = m2;
  return strcmp(left->name, right->name);

  // const char *const *left = m1; // 指向结构体的指针转化为指向结构体第一个的指针，这是因为结构体、首个成员是同一个地址，只是类型不同
  // const char *const *right = m2;
  // return strcmp(*left, *right);
}

// void PrintMusician(const Musician m)
void PrintMusician(const Musician *m)
// 结构体作为参数的时候全部都要拷贝过来，会造成较大开销，所以通常传入指针，不传入结构体
{
  // printf("\n%s\t%d\t%s\t%d\t%d\t%d\n",
  //        (*m).name,
  //        (*m).gender,
  //        (*m).album,
  //        (*m).score.c_score,
  //        (*m).score.java_score,
  //        (*m).score.python_score);

  printf("\n%s\t%d\t%s\t%d\t%d\t%d\n",
         m->name, // 推荐箭头运算符，意味着先解引用，再访问成员
         m->gender,
         m->album,
         m->score.c_score,
         m->score.java_score,
         m->score.python_score);
}

// //
// // Created by hfwei on 2022/12/8.
// //

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <stddef.h>
// #include <time.h>

// typedef enum gender {
//   MALE,
//   FEMALE,
// } Gender;

// typedef struct score {
//   int c_score;
//   int java_score;
//   int python_score;
// } Score;

// typedef struct musician {
//   char *name;
//   // char gender;
//   Gender gender;
//   struct tm birth;

//   char *album;

//   Score score;
// } Musician;

// // void PrintMusician(const Musician m);
// void PrintMusician(const Musician *m);
// int CompareMusician(const void *m1, const void *m2);

// int main() {
//   printf("sizeof(Score) = %zu\n", sizeof(Score));
//   printf("sizeof(Musician) = %zu\n", sizeof(Musician));
//   printf("offsetof(Musician, name) = %zu\n", offsetof(Musician, name));
//   printf("offsetof(Musician, gender) = %zu\n", offsetof(Musician, gender));
//   printf("offsetof(Musician, album) = %zu\n", offsetof(Musician, album));
//   printf("offsetof(Musician, score) = %zu\n", offsetof(Musician, score));

//   Musician luo = {
//       .name = "Luo Dayou",
//       .gender = MALE,
//       .birth = {
//           .tm_year = 1954 - 1900,
//           .tm_mon = 7 - 1,
//           .tm_mday = 20,
//           .tm_wday = 2, // Tuesday
//       },
//       .album = "ZhiHuZheYe",
//       .score = {
//           .c_score = 0,
//           .java_score = 10,
//           .python_score = 20,
//       },
//   };

//   Musician cui = {
//       .name = "Cui Jian",
//       .gender = MALE,
//       .birth = {
//           .tm_year = 1961 - 1900,
//           .tm_mon = 8 - 1,
//           .tm_mday = 2,
//           .tm_wday = 3, // Wednesday
//       },
//       .album = "XinChangZhengLuShangDeYaoGun",
//       .score = {
//           .c_score = 10,
//           .java_score = 20,
//           .python_score = 30,
//       },
//   };

//   char album[] = "YiKeBuKenMeiSuDeXin";
//   Musician zhang = {
//       .name = "Zhang Chu",
//       .gender = MALE,
//       .birth = {
//           .tm_year = 1968 - 1900,
//           .tm_mon = 11 - 1,
//           .tm_mday = 17,
//           .tm_wday = 0, // Sunday
//       },
//       // .album = "YiKeBuKenMeiSuDeXin",
//       .album = album,
//       .score = {
//           .c_score = 20,
//           .java_score = 30,
//           .python_score = 40,
//       },
//   };

//   Musician guo = zhang;
//   guo.name = "Guo Fucheng";
//   strcpy(guo.album, "YiKeJiuMeiSuDeXin");
//   // PrintMusician(guo);
//   // PrintMusician(zhang);
//   PrintMusician(&guo);
//   PrintMusician(&zhang);

//   Musician musicians[] = { luo, cui, zhang, };
//   int len = sizeof musicians / sizeof *musicians;
//   for (int i = 0; i < len; ++i) {
//     // PrintMusician(musicians[i]);
//     PrintMusician(&musicians[i]);
//   }

//   qsort(musicians, len,
//         sizeof *musicians,
//         CompareMusician);

//   for (int i = 0; i < len; ++i) {
//     // PrintMusician(musicians[i]);
//     PrintMusician(&musicians[i]);
//   }

//   return 0;
// }

// // void PrintMusician(const Musician m) {
// //   printf("\n%s\t%d\t%s\t%d\t%d\t%d\n",
// //          m.name,
// //          m.gender,
// //          m.album,
// //          m.score.c_score,
// //          m.score.java_score,
// //          m.score.python_score);
// // }

// void PrintMusician(const Musician *m) {
//   printf("\n%s\t%d\t%s\t%s\t%d\t%d\t%d\n",
//          m->name,
//          m->gender,
//          asctime(&m->birth),
//          m->album,
//          m->score.c_score,
//          m->score.java_score,
//          m->score.python_score);
// }

// int CompareMusician(const void *m1, const void *m2) {
//   const Musician *m_left = m1;
//   const Musician *m_right = m2;

//   return strcmp(m_left->album, m_right->album);

//   // char *name_left = *(char **) m1;
//   // char *name_right = *(char **) m2;

//   // return strcmp(name_left, name_left);
// }