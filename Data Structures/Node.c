#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
Node* makenode(int num)
{
    Node* n = (Node*)malloc(sizeof(Node));
    if(n == NULL)
        exit(1);
    n->data = num;
    n->next = NULL;
    return n;
}
int getdata(Node* node)
{
    return node->data;
}
Node* getnext(Node* node)
{
    return node->next;
}
void setdata(Node* node , int num)
{
    node->data = num;
}
void setnext(Node* node , Node* next)
{
    node->next = next;
}