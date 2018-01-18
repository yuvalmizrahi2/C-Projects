#include <stdio.h>

void swap(int* min , int* max)
{
    int temp = *min;
    *min = *max;
    *max = temp;
}
void sort(int arr[] , int size)
{
    for(int i = 0 ; i< size - 1 ; i++)
    {
        for(int j = 0 ; j < size - 1 ; j++)
        {
            if(arr[j] > arr[j+1])
                swap(&arr[j] , &arr[j+1]);
        }
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