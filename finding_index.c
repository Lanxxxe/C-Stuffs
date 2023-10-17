#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)

{
    srand(time(NULL));
    int numArr[20];
    int count = 0;
    int num_found = 0;
    int input_num, match;

    while (count <= 20)
    {
        numArr[count] = 1 + rand() / ((RAND_MAX + 1u) / 50);
        count++;
    }

    // Printing the Arr
    for (int y = 0; y < sizeof(numArr) / sizeof(numArr[0]); y++)
    {
        printf("Index[%d]: %d\n", y, numArr[y]);
    }

    printf("\nNumber: ");
    scanf("%d", &input_num);

    // Check if the number is found
    for (int x = 0; x < sizeof(numArr) / sizeof(numArr[0]); x++)
    {
        if (numArr[x] == input_num)
        {
            printf("\nNumber Match: Index[%d]", x);
            match = x;
        }
    }
    // Kun ano an pinakalast na mag mamatch, amo it last index
    printf("\n\nLast Occurrence: Index[%d]\n", match);

    //  Check how many numbers are found
    for (int j = 0; j < sizeof(numArr) / sizeof(numArr[0]); j++)
    {
        if (numArr[j] == input_num)
        {
            num_found++;
        }
    }

    printf("Number of times matches: %d", num_found);
}