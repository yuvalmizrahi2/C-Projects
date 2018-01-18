#include <stdbool.h>
typedef struct LinkedList{
    Node* head;
    Node* tail;
    int size;
    Node* middle;
}LinkedList;
LinkedList* makelinkedlist();
void add(LinkedList* list , int num);
