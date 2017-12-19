#include <stdio.h>
#include "ex1function.h"
#include <ctype.h>
#include <string.h>
#include<stdlib.h>
#include "ex1function.h"

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 void bubbleSort(int arr[])
{
   int i, j;
   for (i = 0; i < 3; i++)      
       for (j = 0; j < 2-i; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
void printArray(int arr[])
{
    int i;
    printf("packet sizes are : ");
    for (i=0; i < 3; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
bool start(int arr[])
{
    if(arr[0] == 1 && arr[1] == 1 && arr[2] == 1)
        return true;
    if(arr[0] == 0 && arr[1] == 1 && arr[2] == 1)
        return false;
    if(arr[0] == 0 && arr[1] == 0 && arr[2] == 1)
        return true;
    int i , j , z;
    for(i = 0 ; i < 3 ; i++)
    {
        for(j = i + 1 ; j < 3 ; j ++)
        {
            for(z = 0 ; z < 3 ; z++)
            {
                if(arr[i] + arr[j] == arr[z])
                    return true;
            }
        }
    }
    return false;
}
bool cheackifisdigit(char s[])
{
    int i;
    for (i = 0; i < strlen(s); ++i)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}
void changepacket(int arr[])
{
    int original , replace, i = 0 ;
    char s[max_line];
    printf("please state how much to take ?\n");
    scanf("%s" , s);
    if(cheackifisdigit(s))
        original = atoi(s);
    while(!cheackifisdigit(s) ||( arr[0] != original && arr[1] != original && arr[2] != original))
    {
        
        printf("error try again\n");
        printf("please state how much to take ?\n");
        scanf("%s" , s);
        if(cheackifisdigit(s))
            original = atoi(s);
    }   
    while(arr[i] != original)
    {
        i = i + 1;
    }
    printf(" to ");
    scanf("%s" , s);
    if(cheackifisdigit(s))
        replace = atoi(s);
    while(!cheackifisdigit(s) ||(arr[i] <= replace || replace < 0))
    {
        printf("error try again\n");
        printf(" to ");
        scanf("%s" , s);
        if(cheackifisdigit(s))
            replace = atoi(s);
    }
    arr[i] = replace;
    bubbleSort(arr);
}
bool gamestatus(int arr[])
{
    if(arr[0] == 1 && arr[1] == 0 && arr[2] == 0)
        return false;
    if(arr[0] == 0 && arr[1] == 1 && arr[2] == 0)
        return false;
    if(arr[0] == 0 && arr[1] == 0 && arr[2] == 1)
        return false;
    return true;
}
void computerchange(int arr[])
{
    if(arr[1] == arr[2] && arr[0] != 0)
    {
        printf("I turned %d to 0\n " , arr[0]);
        arr[0] = 0;
    }
    else if(arr[1] == arr[2] && arr[0] == 0)
    {
        printf("I turned %d to 0\n " , arr[1]);
        arr[1] = 0;
    }
    else if(arr[0] == 0 && arr[1] == 0 && arr[2] > 1)
    {
        printf("I turned %d to 1\n " , arr[2]);
        arr[2] = 1;
    }
    else if(arr[0] == 0 && arr[1] == 1 && arr[2] > 1)
    {
        printf("I turned %d to 0\n " , arr[2]);
        arr[2] = 0;
    }
    else if(arr[0] == 1 && arr[1] == 1 && arr[2] > 1)
    {
        printf("I turned %d to 1\n " , arr[2]);
        arr[2] = 1;
    }
    else if(arr[2] > 1 && arr[1] > 1)
    {
        int num = arr[1] - arr[0];
        printf("I turned %d to %d\n " , arr[2], num);
        arr[2] = num;
    }
    bubbleSort(arr);
}
int * getthreenumbers()
{
    static int arr[3];
    int i;
    char s[max_line];
    for(i = 0; i < 3 ; i++)
    {
        printf("please enter a numbers : \n");
        scanf("%s" , s);
        while(!cheackifisdigit(s))
        {
            printf("error try again\n");
            printf("please enter a number : \n");
            scanf("%s" , s);
        }
        arr[i] = atoi(s);
    } 
    return arr;    
}