#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct stack{
    char* arr;
    int size;
}stack;
stack* createstack();
void push(stack* s , char num);
char pop(stack* s);
char peek(stack* s);
bool isempty(stack* s);