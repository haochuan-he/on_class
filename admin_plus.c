// 2023.9.24
// review after class
// by HHC

#include <stdio.h>
#include <math.h>
#include <ctype.h>
int main(void)
{
    char first_name[10];
    char last_name[10];

    char gender;

    int birth_year;
    int birth_month;
    int birth_day;

    char weekday[10];

    int c_score;
    int music_score;
    int medicine_score;

    double mean;
    double sd;
    int rank;
    // 数组本身就表示了地址，不需要取地址符&
    //%c不会忽略前导的空白符（空格 制表符 换行符均可）
    //%d可以忽略前面的空白符
    // double 输入必须用lf
    //%s可以忽略空白符，9s可以限制最多读取9个（\0自带）
    scanf("%9s%9s %c%d%d%d %9s %d%d%d %lf%lf %d%%",
          first_name, last_name, &gender,
          &birth_month, &birth_day, &birth_year, weekday, &c_score,
          &music_score, &medicine_score, &mean, &sd, &rank);

    printf("%s\t%s\t%c\n"
           "%.2d-%.2d-%.2d\n"
           "%d\t%d\t%d\n"
           "%.1f\t%.2f\t%d%%",
           first_name, last_name, toupper(gender),
           birth_month, birth_day, birth_year,
           c_score, music_score, medicine_score,
           mean, sd, rank);

    return 0;
}