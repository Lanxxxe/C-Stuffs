#include <stdio.h>

int main(void)
{
    int arrayLength, index;
    int arrayOfNumbers[100];
    int reverseArray[100];

    printf("Enter the desire length of array: ");
    scanf("%d", &arrayLength);

    for (index = 0; index < arrayLength; index++)
    {
        printf("Value of Index[%d]: ", index);
        scanf("%d", &arrayOfNumbers[index]);
    }

    for (index = 0; index < arrayLength; index++)
    {
        reverseArray[index] = arrayOfNumbers[arrayLength - index - 1];
    }

    printf("Reverse Array: ");
    for (index = 0; index < arrayLength; index++)
    {
        printf("%d ", reverseArray[index]);
    }
}