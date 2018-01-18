#include <stdio.h>
#include <string.h>

int search(int arr[] , int l , int r , int num)
{
    int m;
    while(l <= r)
    {
        m = (l + r)/2;
        if(arr[m] == num)
            return m;
         else if(arr[m] > num)
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int num;
    printf("enter a number for searching in the array\n");
    scanf("%d",&num);
    int result = Search(arr , 0 , size - 1 , num);
    if(result != -1 )
        printf("the number found in the array in place %d",result);
    else
        printf("the number don't found");
    return 0;
}