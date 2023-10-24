#include <stdio.h>

int main()
{

    int arr[100][100];
    int user_input, counter = 1;

    printf("Enter the size of the matrix: ");
    scanf("%d", &user_input);

    printf("Enter the elements of the matrix: \n");
    for (int row = 0; row < user_input; row++)
    {
        for (int col = 0; col < user_input; col++)
        {
            scanf("%d", &arr[row][col]);
            if (row == col)
            {
                counter *= arr[row][col];
            }
        }
    }
    printf("The diagonal sum of the matrix is: %d", counter);

    return 0;
}