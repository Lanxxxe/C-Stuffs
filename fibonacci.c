#include <stdio.h>

int fibonacci(int input)
{
    int numArray[100];

    printf("Array: ");
    for (int counter = 1; counter <= input; counter++)
    {
        printf("%d ", counter);
    }

    for (int index = 1; index <= input; index++)
    {
        if (index == 1)
        {
            numArray[index - 1] = index;
        }
        else if (index == 2)
        {
            numArray[index - 1] = index - 1;
        }
        else
        {
            numArray[index - 1] = numArray[index - 3] + numArray[index - 2];
        }
    }

    printf("Fibonacci: ");
    for (int counter = 0; counter < input; counter++)
    {
        printf("%d ", numArray[counter]);
    }
}

int main()
{

    int userInput;

    printf("Enter the length of fibonacci: ");
    scanf("%d", &userInput);

    fibonacci(userInput);

    return 0;
}