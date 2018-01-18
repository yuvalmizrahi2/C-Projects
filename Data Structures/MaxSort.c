#include <stdio.h>
void swap(int* min , int* max)
{
    int temp = *min;
    *min = *max;
    *max = temp;
}
void sort(int arr[] , int size)
{
    int i , j , max = arr[0] , indexmax = 0;
    for(i = size - 1 ; i >= 0 ; i--)
    {
        for(j = 0 ; j <= i ; j++)
        {
            if(arr[j] > max)
            {
                max = arr[j];
                indexmax = j;
            }
        }
        Swap(&arr[i] , &arr[indexmax]);
        max = arr[0];
        indexmax = 0;
    }
}
int main()
{
    int arr[] = {3,8,7,10,5,4,9,2,6,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0 ; i < size ; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    Sort(arr , size);
    for(int i = 0 ; i < size ; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}