typedef struct maxheap{
    int* arr;    
    int size;
}maxheap;
maxheap* createmaxheap();
void swapmax(int* x , int* y);
void swapupmax(int i , maxheap* heap);
void addmax(maxheap* heap , int num);
void swapdownmax(int i , maxheap* heap);
int getmax(maxheap* heap);
void printmax(maxheap* heap);