#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#define row 6
#define column 7

void printmatrix(char matrix[row][column] , bool turn);
bool gamestatus(int count);
int changeboard(int c , char matrix[row][column] , bool turn  ,int k);
bool cheackifisdigit(char s[] ,bool* doub);
void printmatrixend(char matrix[row][column]);
bool cheackwin(int x , int y  ,char matrix[row][column] , bool turn);
int row4(int x , int y , char matrix[row][column] , char ch);
int column4(int x , int y , char matrix[row][column] , char ch);
int diagonalmain4(int x , int y , char matrix[row][column] , char ch);
int diagonalsecond4(int x , int y , char matrix[row][column] , char ch);