#include <stdio.h>
#include <stdlib.h>

void merge(int arr[] , int start , int middle , int end)
{
    int num = end - start + 1;
    int* temp = (int*)malloc(sizeof(int)*num);
    int i = start , j = middle + 1 , k = 0;
    while(i <= middle && j <= end)
    {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while(i <= middle)
        temp[k++] = arr[i++];
    while(j <= end)
        temp[k++] = arr[j++];
    for(int q = 0 ; q < end - start + 1 ; q++)
        arr[start + q] = temp[q];
    free(temp);
}
void sort(int arr[] , int start , int end)
{
    int middle = (start + end)/2;
    if(end - start > 0)
    {
        Sort(arr , start , middle);
        Sort(arr , middle + 1 , end);
        Merge(arr , start , middle , end);
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
    Sort(arr , 0 , size - 1);
    for(int i = 0 ; i < size ; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}