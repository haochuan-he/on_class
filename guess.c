// 22-9-15
// on class
// by HHC
#include <stdio.h>
#include <time.h>

int main(void)
{                   // print the rule of the game
    int high = 100; // 最大数
    int chance = 7;
    printf("the computer will generate a random number between 1 and %d \n"
           "you have %d chances",
           high, chance);

    // generate a random number

    srand(time(NULL)); // use current time as seed for random generator
    int secret = rand() % high + 1;

    // let the player enter his/her guess number
    int guess;
    printf("enter your guess number\n");
    scanf("%d", &guess);
    while (chance > 0)
    {
        chance--;
        if (guess == secret)
        {
            printf("you win!\n");
            break;
        }
        else if (guess > secret)
        {
            printf("guess>secret\n");
        }
        else
            printf("guess<secret");
        
    }

    // store the gurss number
    // compare it with the secret number
    // inform thhe player of the resule

    // loop:repeat until the player wins or loses

    printf("rule of the game\n");
    return 0;
}