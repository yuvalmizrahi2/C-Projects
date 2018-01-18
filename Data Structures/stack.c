#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"
stack* createstack(int size)
{
    stack* temp = (stack*)malloc(sizeof(stack));
    if(temp == NULL)
        exit(1);
    temp->arr = (char*)malloc(sizeof(char)*size);
    if(temp->arr == NULL)
        exit(1);
    temp->size = 0;
    return temp;
}
void push(stack* s , char num)
{
    s->size++;
    s->arr[s->size - 1] = num;
}
char pop(stack* s)
{
    char temp = '\0';
    if(s->size != 0)
    {
        temp = s->arr[s->size - 1];
        s->size--;
    }
    return temp;
}
char peek(stack* s)
{
    char temp = '\0';
    if(s->size != 0)
    {
        temp = s->arr[s->size - 1];
    }
    return temp;
}
bool isempty(stack* s)
{
    return s->size == 0;
}