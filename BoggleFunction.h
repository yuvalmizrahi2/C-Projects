#include <stdbool.h>
#define MATRIX_SIZE 4
bool isWord(char* s);
void findWords(char matrix[MATRIX_SIZE][MATRIX_SIZE]);
void findWordsUp(char matrix[MATRIX_SIZE][MATRIX_SIZE]);
void findWordsDown(char matrix[MATRIX_SIZE][MATRIX_SIZE]);
void findWordsLeft(char matrix[MATRIX_SIZE][MATRIX_SIZE]);
void findWordsRight(char matrix[MATRIX_SIZE][MATRIX_SIZE]);
int printWords(char A[MATRIX_SIZE][MATRIX_SIZE]);
