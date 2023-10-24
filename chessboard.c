#include <stdio.h>

int main(void)
{
    int chessBoardArray[100];
    int sizeOfArray, row, column;

    printf("Enter the size of chessboard: ");
    scanf("%d", &sizeOfArray);

    for (row = 0; row < sizeOfArray; row++)
    {
        for (column = 0; column < sizeOfArray; column++)
        {
            if (row % 2 == 0)
            {
                if (column % 2 == 0)
                {
                    printf("White\t");
                }
                else
                {
                    printf("Black\t");
                }
            }
            else
            {
                if (column % 2 == 0)
                {
                    printf("Black\t");
                }
                else
                {
                    printf("White\t");
                }
            }
        }
        printf("\n");
    }
}