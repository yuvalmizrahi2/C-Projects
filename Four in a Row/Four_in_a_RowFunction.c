#inFour_in_a_RowFunctionunction.h"

void printmatrix(char matrix[row][column] , bool turn)
{
    for(int i = 0; i < row ; i++)
    {
        for(int j = 0; j < column ; j++)
        {
            printf("|%c",matrix[i][j]);
        }
        printf("|\n");
    }
    printf(" 1 2 3 4 5 6 7\n");
    if(turn)
        printf("Player X, please enter a column number (or 0 to undo):");
    else
        printf("Player O, please enter a column number (or 0 to undo):");
    }
void printmatrixend(char matrix[row][column])
{
    for(int i = 0; i < row ; i++)
    {
        for(int j = 0; j < column ; j++)
        {
            printf("|%c",matrix[i][j]);
        }
        printf("|\n");
    }
    printf(" 1 2 3 4 5 6 7\n");
}
bool gamestatus(int count)
{
    if(count == 42)
        return true;
    return false;
}
int changeboard(int c, char matrix[row][column] , bool turn , int k)
{
    if(c == 0)
    {
        for(int i = 0 ; i < row; i++)
        {
            if(matrix[i][k] == 'X' || matrix[i][k] == 'O')
            {
                matrix[i][k] = ' ';
                return i;
            }
        }
        return -2;
    }
    else
    {
        c = c-1;
        for(int i = row-1; i >= 0 ; i--)
        {
            if(matrix[i][c] != 'X' && matrix[i][c] != 'O')
            {
                if(turn)
                    matrix[i][c] = 'X';
                else
                    matrix[i][c] = 'O';
                return i;
            }
        }
        return -1;
    }
}
bool cheackifisdigit(char s[] , bool* doub)
{
    int i;
    for (i = 0; i < strlen(s); ++i)
    {
        if (!isdigit(s[i]))
        {
            if(s[i] == '.')
                *doub = true;
            else if(s[i] != '-')
                return false;
        }
    }
    return true;
}
bool cheackwin(int x , int y  ,char matrix[row][column] , bool turn)
{
    char ch = 'O';
    if(turn)
        ch = 'X';
    if(1 + row4(x,y,matrix,ch) >= 4)
        return true;
    if(1 + column4(x,y,matrix,ch) >= 4)
        return true;
    if(1 + diagonalmain4(x,y,matrix,ch) >= 4)
        return true;
    if(1 + diagonalsecond4(x,y,matrix,ch) >= 4)
        return true;
    return false;
}
int row4(int x , int y , char matrix[row][column] , char ch)
{
    int counter = 0;
    for(int i = y+1 ; i < column && matrix[x][i] == ch; i++)
    {
        counter ++;
    }
    for(int i = y-1 ; i >= 0 && matrix[x][i] == ch ; i--)
    {
        counter ++;
    }
    return counter;
}
int column4(int x , int y , char matrix[row][column] , char ch)
{
    int counter = 0;
    for(int i = x-1 ; i >= 0 && matrix[i][y] == ch ; i--)
    {
        counter++;
    }
    for(int i = x+1 ; i < row && matrix[i][y] == ch; i++)
    {
        counter++;
    }
    return counter;
}
int diagonalmain4(int x , int y , char matrix[row][column] , char ch)
{
    int tempy = y-1;
    int counter = 0;
    for(int i = x-1 ; i >= 0 && matrix[i][tempy] == ch && tempy >= 0 ; i--)
    {
        tempy--;
        counter++;
    }
    tempy = y+1;
    for(int i = x+1 ; i < row  && matrix[i][tempy] == ch && tempy >= 0 ; i++)
    {
        tempy++;
        counter++;
    }
    return counter;
}
int diagonalsecond4(int x , int y , char matrix[row][column] , char ch)
{
    int tempy = y+1;
    int counter = 0;
    for(int i = x-1 ; i >= 0 && matrix[i][tempy] == ch && tempy < column ; i--)
    {
        tempy++;
        counter++;
    }
    tempy = y-1;
    for(int i = x+1 ; i < row  && matrix[i][tempy] == ch && tempy < column ; i++)
    {
        tempy--;
        counter++;
    }
    return counter;
}
