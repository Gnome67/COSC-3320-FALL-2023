#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int count=0;
    int n,k;
    int i,j;

    char board[8][8];
    fscanf(stdin, "%d %d", &n, &k);
    char tmp;
    fscanf(stdin, "%c", &tmp);
    count = 0;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            fscanf(stdin, "%c", &board[i][j]);
        }
        fscanf(stdin, "%c", &tmp);
    }

    /*
    Write your code here.
    The board is stored in the 2D array 'board'.
    The number of rows and columns of the board is stored in 'n'.
    The number of chess pieces is stored in 'k'.
    The result should be stored in 'count'.
    */
    printf("%d\n", count);
    return 0;
}
