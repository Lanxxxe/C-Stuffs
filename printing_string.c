#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char string[100];
    int row, col, block;

    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);

    int stringSize = strlen(string);

    for (block = 0; block < stringSize; block++)
    {
        for (row = block; row < stringSize; row++)
        {
            for (col = 0 + block; col < row; col++)
            {
                printf("%c ", string[col]);
            }
            printf("\n");
        }
    }
    return 0;
}