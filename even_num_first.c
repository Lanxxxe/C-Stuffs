#include <stdio.h>
#include <string.h>

int main()
{
    int num;
    int numArr[100];
    int oddNum[100], evenNum[100];
    int counter = 0;

    printf("Enter the number of arr:");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        printf("Element #%d: ", i);
        scanf("%d", &numArr[i]);
    }

    for (int j = 0; j < num; j++)
    {
        if (numArr[j] % 2 == 0)
        {
            printf("\nElement %d: %d", counter, numArr[j]);   
            counter++;
        }
    }
    for (int j = 0; j < num; j++)
    {
        if (numArr[j] % 2 != 0)
        {
            printf("\nElement %d: %d", counter, numArr[j]);   
            counter++;
        }
    }
    return 0;
}