#include <stdio.h>

int generate_pascal(int num)
{

    for (int col = 1; col <= num; col++)
    {
        for (int space = 1; space <= num - col; space++)
        {
            printf(" ");
        }

        int n = 1;
        for (int x = 1; x <= col; x++)
        {
            printf("%3d ", n);
            n = n * (col - x) / x;
        }
        printf("\n");
    }
}

int printDiamond(int numOfRows)
{
    int row, space, columns;

    for (row = 1; row <= numOfRows; row++)
    {
        for (space = 0; space <= numOfRows - row; space++)
        {
            printf(" ");
        }

        for (columns = 1; columns <= row; columns++)
        {
            printf("* ");
        }
        printf("\n");
    }
    for (row = numOfRows; row >= 1; row--)
    {
        for (space = (numOfRows + 1) - row; space >= 1; space--)
        {
            printf(" ");
        }
        for (columns = row - 1; columns >= 1; columns--)
        {
            printf("* ");
        }
        printf("\n");
    }
}

int main(void)
{
    int n;
    printf("Enter the number of lines: ");
    scanf("%d", &n);

    printDiamond(n);
}
