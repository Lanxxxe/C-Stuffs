#include <stdio.h>

int main(void)
{
    int arrayOfNumbers[100];
    int numberOfElements, index, minimumValue;

    printf("Enter the desire number  of elements: ");
    scanf("%d", &numberOfElements);

    for (index = 0; index < numberOfElements; index++)
    {
        printf("Index %d: ", index);
        scanf("%d", &arrayOfNumbers[index]);
    }

    minimumValue = arrayOfNumbers[0];

    for (index = 0; index < numberOfElements; index++)
    {
        if (arrayOfNumbers[index] < minimumValue)
        {
            minimumValue = arrayOfNumbers[index];
        }
    }

    printf("\nThe minimum value in the array is: %d", minimumValue);
}