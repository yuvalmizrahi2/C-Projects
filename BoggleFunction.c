#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "BoggleFunction.h"

static int count = 0;
bool isWord(char* s){

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
void findWords(char matrix[MATRIX_SIZE][MATRIX_SIZE], bool visit[MATRIX_SIZE][MATRIX_SIZE], int i,int j,int k, char word[17])
{
    if(i >= 0 && j >= 0 && i < MATRIX_SIZE && j < MATRIX_SIZE &&  visit[i][j] != true )
    {
        visit[i][j] = true;
        word[k] = matrix[i][j];
        word[k+1] = '\0';
        if(isWord(word))
        {
            printf("%s\n",word);
            count = count + 1;
        }
        findWords(matrix,visit,i-1,j,k+1,word);
        findWords(matrix,visit,i+1,j,k+1,word);
        findWords(matrix,visit,i,j-1,k+1,word);
        findWords(matrix,visit,i,j+1,k+1,word);
        visit[i][j] = false;
        word[k] = '\0';
    }
    
}
int printWords(char A[MATRIX_SIZE][MATRIX_SIZE])
{
    char word[MATRIX_SIZE*MATRIX_SIZE+1] = "";
    bool visit[MATRIX_SIZE][MATRIX_SIZE]=
    {
        {false,false,false,false}
    };
    int i , j , k = 0; 
    for(i = 0 ; i < MATRIX_SIZE ; i++)
        {
            for(j = 0 ; j < MATRIX_SIZE ; j++)
            {
                findWords(A, visit, i , j , k , word);
            }
        }
    return count;
} 