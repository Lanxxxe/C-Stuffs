#include <stdio.h>
// #include <string.h>

int main()
{
    char string[100];
    char letter;
    int counter = 0, i = 0;

    printf("Enter the string: ");
    fgets(string, sizeof(string), stdin);

    printf("Enter the letter: ");
    scanf(" %c", &letter);

    // for (int i = 0; string[i] != '\0'; i++)
    // {
    //     if (string[i] == letter)
    //     {
    //         counter++;
    //     }
    // }

    while (string[i] != '\0')
    {
        if (string[i] == letter){
            counter++;
        }
        i++;
    }
    

    printf("Number of times appear: %d", counter);

    return 0;
}