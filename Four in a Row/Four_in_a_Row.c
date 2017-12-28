#inFour_in_a_RowFunctionunction.h"
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define row 6
#define column 7
bool turn = true;
char matrix[row][column];
int count = 0 , place = 0;
bool win = false;
int pointer[42];
bool doub = false;
int main()
{
    int val;
    bool rule = true;
    char input[10];
    memset(matrix,' ', sizeof(matrix[0][0]) * row * column);
    printf("Welcome!\n"); 
    while(!gamestatus(count)&& !win)
    {
        while(rule)
        {
            printmatrix(matrix , turn);
            scanf("%s",input);
            if(doub)
            {
                printf("Invalid input, bye-bye!\n");
                exit(0);
            }
            else if(!cheackifisdigit(input,&doub))
            {
                printf("Invalid input, bye-bye!\n");
                exit(0);
            }
            else if(atoi(input) < 0 || atoi(input) > 7)
            {
                printf("Invalid input, the number must be between 1 to 7:\n");
            }
            else if((val = changeboard(atoi(input),matrix,turn,pointer[place-1])) == -1 || val == -2)
            {
                if(val == -1)
                    printf("Invalid input, this column is full. Please choose another one: \n");
                else
                    printf("Board is empty - can't undo!\n");
            }
            else
            {
                if(atoi(input) == 0)
                {
                    place--;
                    count --;
                }
                else
                {
                    pointer[place] = atoi(input)-1;
                    place++;
                    count ++ ;
                    win = cheackwin(val , atoi(input)-1,matrix,turn);
                }
                rule = false;                
            }
        }
        turn = !turn;
        rule = true;
    }
    printmatrixend(matrix);
    if(win)
    {
        if(turn)
            printf("Player O wins! ");
        else
            printf("Player X wins! ");
    }
    else
        printf("It's a tie! ");
}

