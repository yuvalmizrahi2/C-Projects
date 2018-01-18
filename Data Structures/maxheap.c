#include <stdio.h>
#include <stdlib.h>
#include "maxheap.h"
maxheap* createmaxheap()
{
    maxheap* heap = (maxheap*)malloc(sizeof(maxheap)*1);
    if(heap == NULL)
        exit(1);
    heap->size = 0;
    heap->arr = (int*)malloc(sizeof(int)*heap->size);
    if(heap->arr == NULL)
        exit(1);
    return heap;
}
void swapmax(int* x , int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void swapupmax(int i , maxheap* heap)
{
    int parent = i/2;
    if(heap->arr[parent] < heap->arr[i])
    {
        swapmax(&heap->arr[parent] , &heap->arr[i]);
        swapupmax(parent , heap);
    }
}
void addmax(maxheap* heap , int num)
{
    heap->arr[heap->size] = num;
    swapupmax(heap->size, heap);
    heap->size++;
    heap->arr = (int*)realloc(heap->arr , sizeof(int)*heap->size);
    if(heap->arr == NULL)
        exit(1);
}
void swapdownmax(int i , maxheap* heap)
{
    int left = 2*i;
    int right = 2*i + 1;
    if(left == heap->size)
    {
        if(heap->arr[i] < heap->arr[left])
            swapmax(&heap->arr[i] , &heap->arr[left]);
    }
    if(left < heap->size)
    {
        int largest = left;
        if(heap->arr[left] < heap->arr[right])
            largest = right;
        if(heap->arr[i] < heap->arr[largest])
        {
            swapmax(&heap->arr[i] , &heap->arr[largest] );
            swapupmax(largest , heap);
        }
    }
}
int getmax(maxheap* heap)
{
    int max = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    swapdownmax(0 , heap);
    return max;
}
void printmax(maxheap* heap)
{
    for(int i = 0 ; i < heap->size ; i++)
    {
        printf("%d ",heap->arr[i]);
    }
    printf("\n");
}