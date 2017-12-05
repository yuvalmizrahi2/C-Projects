#include "BoggleFunction.h"
                  
int main()
{
    char matrix[MATRIX_SIZE][MATRIX_SIZE] =
    { 
        {'C','A','R','T'},
        {'E','T','A','K'},
        {'E','S','M','E'},
        {'L','L','P','N'}
    };
    return printWords(matrix);;
}
