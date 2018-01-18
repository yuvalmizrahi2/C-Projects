typedef struct minheap{
    int* arr;    
    int size;
}minheap;
minheap* createminheap();
void swapmin(int* x , int* y);
void swapupmin(int i , minheap* heap);
void addmin(minheap* heap , int num);
void swapdownmin(int i , minheap* heap);
int getmin(minheap* heap);
void printmin(minheap* heap);