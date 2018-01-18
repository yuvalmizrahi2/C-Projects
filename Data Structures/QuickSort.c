#include <stdio.h>
#include <stdlib.h>
void swap(int* min , int* max)
{
    int temp = *min;
    *min = *max;
    *max = temp;
}
int partition(int arr[] , int start , int end)
{
    int r = start + rand() % (end - start + 1);
    swap(&arr[start] , &arr[r]);
    int pivot = start;
    int l = pivot + 1;
    int h = end;
    while(h >= l)
    {
        if(arr[l] <= arr[pivot])
            l++;
        else if(arr[h] > arr[pivot])
            h--;
        else
            swap(&arr[l] , &arr[h]);
    }
    swap(&arr[pivot] , &arr[h]);
    return h;
}
void sort(int arr[] , int start , int end)
{
    if(end - start > 0)
    {
        int pivot = partition(arr , start , end);
        sort(arr , start , pivot - 1);
        sort(arr , pivot + 1 , end);
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
    sort(arr , 0 , size - 1);
    for(int i = 0 ; i < size ; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}