// 23.10.20
// on class
// by HHC

// also called Cellular Automata 元胞自动机
// Rules:
// any live cell with two or three live neighbours survives
// all other live cells die in the next generation
// any dead cell with three live neighbours becomes a live cell
// all other dead cells stay dead

#include <stdio.h>
#define SIZE 6

const int board[SIZE][SIZE] =
    {{0},
     {0, 1, 1, 0, 0, 0},
     {0, 1, 1, 0, 0, 0},
     {0, 0, 0, 1, 1, 0},
     {0, 0, 0, 1, 1, 0}};

// alse {[1][1] = 1, [1][2] = 1 ......} to initiative

int main()
{
    // TODO: play game of life

    // add two rows and culomns to slove解决边界问题
    int old_board[SIZE + 2][SIZE + 2] = {0};

    for (int row = 1; row <= SIZE; row++)
    {
        for (int col = 1; col <= SIZE; col++)
        {
            old_board[row][col] = board[row - 1][col - 1];
        }
    }

    // to print the initiative
    for (int row = 1; row <= SIZE; row++)
    {
        for (int col = 1; col <= SIZE; col++)
        {
            printf("%c", (old_board[row][col] ? '*' : ' '));
        }
        printf("\n");
    }

    int new_board[SIZE + 2][SIZE + 2] = {0};
    for (int row = 1; row <= SIZE; row++)
    {
        for (int col = 1; col <= SIZE; col++)
        { // counting live cells in the neighbour on old_board[i][j]

            int neighbors = old_board[row - 1][col - 1] +
                            old_board[row - 1][col] +
                            old_board[row - 1][col + 1] +
                            old_board[row][col - 1] +
                            old_board[row][col + 1] +
                            old_board[row + 1][col - 1] +
                            old_board[row + 1][col] +
                            old_board[row + 1][col + 1];
            if (old_board[row][col])
            {
                new_board[row][col] = (neighbors == 2 || neighbors == 3);
                // if (neighbors == 2 || neighbors == 3)
                // {
                //     new_board[row][col] = 1;
                // }
                // else
                // {
                //     new_board[row][col] = 0;
                // }
            }
            else
            { // revive
                new_board[row][col] = (neighbors == 3);
            }
        }
    }

    // board = apply the rule > new_board
    // apply the rule
    // counting live cells in the neighbour board[i][j]
    // int count = 0;
    // if (board[i - 1][j - 1] == 1)
    // {
    //     count++;
    // }
    return 0;
}
