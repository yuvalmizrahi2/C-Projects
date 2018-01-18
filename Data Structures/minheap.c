#include <stdio.h>
#include <stdlib.h>
#include "minheap.h"
minheap* createminheap()
{
    minheap* heap = (minheap*)malloc(sizeof(heap)*1);
    if(heap == NULL)
        exit(1);
    heap->size = 0;
    heap->arr = (int*)malloc(sizeof(int)*heap->size);
    if(heap->arr == NULL)
        exit(1);
    return heap;
}
void swapmin(int* x , int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void swapupmin(int i , minheap* heap)
{
    int parent = i/2;
    if(heap->arr[parent] > heap->arr[i])
    {
        swapmin(&heap->arr[parent] , &heap->arr[i]);
        swapupmin(parent , heap);
    }
}
void addmin(minheap* heap , int num)
{
    heap->arr[heap->size] = num;
    swapupmin(heap->size, heap);
    heap->size++;
    heap->arr = (int*)realloc(heap->arr , sizeof(int)*heap->size);
    if(heap->arr == NULL)
        exit(1);
}
void swapdownmin(int i , minheap* heap)
{
    int left = 2*i;
    int right = 2*i + 1;
    if(left == heap->size)
    {
        if(heap->arr[i] > heap->arr[left])
            swapmin(&heap->arr[i] , &heap->arr[left]);
    }
    if(left < heap->size)
    {
        int largest = left;
        if(heap->arr[left] > heap->arr[right])
            largest = right;
        if(heap->arr[i] > heap->arr[largest])
        {
            swapmin(&heap->arr[i] , &heap->arr[largest] );
            swapupmin(largest , heap);
        }
    }
}
int getmin(minheap* heap)
{
    int max = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    swapdownmin(0 , heap);
    return max;
}
void printmin(minheap* heap)
{
    for(int i = 0 ; i < heap->size ; i++)
    {
        printf("%d ",heap->arr[i]);
    }
    printf("\n");
}