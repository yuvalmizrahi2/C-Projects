#include "ex2function.h"
#include <stdio.h>

int main()
{
    char matrix[MATRIX_SIZE][MATRIX_SIZE] =
    { 
        {'C','A','R','T'},
        {'E','T','A','K'},
        {'E','S','M','E'},
        {'L','L','P','N'}
    };
    int count = printWords(matrix);
    printf("amount of words: %d",count);
    return 0;
}
