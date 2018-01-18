#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
#include "LinkedList.h"
LinkedList* makelinkedlist()
{
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if(list == NULL)
        exit(1);
    list->head = list->tail = list->middle = NULL;
    return list;
}
void add(LinkedList* list , int num)
{
    Node* temp = makenode(num);
    if(list->head == NULL)
        list->head = list->tail = list->middle = temp;
    else
    {    
        setnext(list->tail , temp);
        list->tail = temp;
        if((list->size + 1) % 2 == 0 )
        {
            list->middle = list->middle->next;
        }
    }
    list->size++;
}