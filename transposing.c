#include <stdio.h>
#include <stdlib.h>
#define row_size 4
#define col_size 3

int main(void)
{
    int transposedArray[10][10];
    int arrayOfNumbers[10][10] = {
        {2, 4, 5},
        {5, 7, 9},
        {10, 11, 2},
        {3, 8, 9}};

    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            printf("%4d", arrayOfNumbers[i][j]);
            transposedArray[j][i] = arrayOfNumbers[i][j];
        }
        printf("\n");
    }

    printf("\n\n");

    for (int x = 0; x < col_size; x++)
    {
        for (int y = 0; y < row_size; y++)
        {
            printf("%4d", transposedArray[x][y]);
        }
        printf("\n");
    }
}