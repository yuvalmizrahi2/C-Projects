#include <stdbool.h>
#define MATRIX_SIZE 4
bool isWord(char* s);
void findWords(char matrix[MATRIX_SIZE][MATRIX_SIZE], bool visit[MATRIX_SIZE][MATRIX_SIZE], int i,int j,int k, char word[17]);
int printWords(char A[MATRIX_SIZE][MATRIX_SIZE]);
