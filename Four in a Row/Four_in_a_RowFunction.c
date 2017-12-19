#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Four_in_a_RowFunction.h"
static int count = 0 , k = 0 , i , j;
static char word[MATRIX_SIZE*MATRIX_SIZE+1] = "";
static bool visit[MATRIX_SIZE][MATRIX_SIZE];
bool isWord(char* s)
{

		return (!strcmp(s,"CAT") |
			!strcmp(s,"CATS") |
			!strcmp(s,"TRAM") |
			!strcmp(s,"TRAMS") |
			!strcmp(s,"TAME") |
			!strcmp(s,"CAR") |
			!strcmp(s,"CARS") |
			!strcmp(s,"RAT") |
			!strcmp(s,"RATS") |
			!strcmp(s,"RAMP") |
			!strcmp(s,"ART") |
			!strcmp(s,"CART") |
			!strcmp(s,"STAMP") |
			!strcmp(s,"TAKEN") |
			!strcmp(s,"MEN") |
			!strcmp(s,"MAKE") |
			!strcmp(s,"TAKE") |
			!strcmp(s,"ATE") |
			!strcmp(s,"SELL") |
			!strcmp(s,"STEEL") |
			!strcmp(s,"RAKE") );

}
void findWords(char matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    if(i >= 0 && j >= 0 && i < MATRIX_SIZE && j < MATRIX_SIZE &&  visit[i][j] != true )
    {
        visit[i][j] = true;
        word[k] = matrix[i][j];
        word[k+1] = '\0';
        k++;
        if(isWord(word))
        {
            printf("%s\n",word);
            count = count + 1;
        }
        i--;
        findWords(matrix);
        i = i + 2;
        findWords(matrix);
        i--;
        j--;
        findWords(matrix);
        j = j + 2;
        findWords(matrix);
        j--;
        k--;
        visit[i][j] = false;
        word[k] = '\0';
    }
    
}
int printWords(char A[MATRIX_SIZE][MATRIX_SIZE])
{
    memset(visit, 0, sizeof(visit[0][0]) * MATRIX_SIZE * MATRIX_SIZE);    
    for(i = 0 ; i < MATRIX_SIZE ; i++)
        {
            for(j = 0 ; j < MATRIX_SIZE ; j++)
            {
                findWords(A);
            }
        }
    return count;
} 