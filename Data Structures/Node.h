typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node* makenode(int num);
int getdata(Node* node);
Node* getnext(Node* node);
void setdata(Node* node , int num);
void setnext(Node* node , Node* next);
