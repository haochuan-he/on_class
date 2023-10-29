#include <stdio.h>
#include <stdbool.h> //bool

bool IsPrime(int number);

int main()
{
    int max = 0, cnt = 0;
    scanf("%d", &max);

    for (int number = 2; number <= max; ++number)
    {
        if (IsPrime(number))
        {
            // printf("%d ", number);//printf will take time,many time.
            cnt++;
        }
    }
    printf("\ncnt=%d", cnt);

    return 0;
}

bool IsPrime(int number)
{
    for (int factor = 2; factor * factor <= number; factor++)
    {
        if (number % factor == false)
        {
            return false;
        }
    }

    return true;
}
/*
// 23.10.13
// on calss
// by HHC
#include <stdio.h>
#include <stdbool.h> //bool



int main()
{
    int max = 0, cnt = 0;
    scanf("%d", &max);

    for (int number = 2; number <= max; ++number)
    {

        int is_prime = true;

        for (int factor = 2; factor * factor <= number; factor++)
        {
            if (number % factor == false)
            {
                is_prime = 0;
                break;
            }
        }
        if (is_prime)
        {

            // printf("%d ", number);//printf will take time,many time.
            cnt++;
        }
    }
    printf("\ncnt=%d", cnt);

    return 0;
}
*/