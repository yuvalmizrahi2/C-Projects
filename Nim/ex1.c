#include "ex1function.h"
#include <stdio.h>

int main()
{
    int *arr;
    bool computerstart = true;
    arr = getthreenumbers();
    bubbleSort(arr);    
    printArray(arr);
    computerstart = start(arr);
    while(gamestatus(arr))
    {
        if(computerstart)
        {
            changepacket(arr);
            printArray(arr);
             
        }
        else
        {
            computerchange(arr);
            printArray(arr);
        }
        computerstart = !computerstart;
    }
    if(computerstart)
        printf("Game Over - You Lost !! ");
    else
        printf("Game Over - You Win !! ");
    return 0;
}