// 2023.9.24
// after class review
// by HHC
#include <stdio.h>
#include <math.h>
#include <ctype.h>
int main(void)
{
    char first_name[] = "Dayou";
    char last_name[] = "Luo";

    char gender = 'm';

    int birth_year = 1954;
    int birth_month = 7;
    int birth_day = 20;

    char weekday[] = "Tuesday";

    int c_score = 30;
    int music_score = 100;
    int medicine_score = 85;

    double mean = (c_score +
                   music_score +
                   medicine_score) /
                  3.0;
    double sd = sqrt((pow(c_score - mean, 2) +
                      pow(music_score - mean, 2) +
                      pow(medicine_score - mean, 2)) /
                     3.0);
    int rank = 5;
    // transfer"a"to"A":toupper() (include<ctype.h>)
    //  or gender=genfer-'a'+'A'
    printf("%s\t%s\t%c\n"
           "%.2d-%.2d-%.2d\n"
           "%d\t%d\t%d\n"
           "%.1f\t%.2f\t%d%%", //%.2d:precision ; %%print%
           first_name, last_name, toupper(gender),
           birth_month, birth_day, birth_year,
           c_score, music_score, medicine_score,
           mean, sd, rank);

    // gender = gender - 'a' + 'A';//don't use "-32":avoid magic number
    // printf("\n%c", gender);

    return 0;
}