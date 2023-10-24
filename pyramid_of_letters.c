#include <stdio.h>

// 1,3,5,7,9
int main()
{
    int size;
    char letters = 'A';
    int counter = 1;

    printf("Enter the size of the pyramid: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        for (int j = size; j > i; j--)
        {
            printf(" ");
        }
        int add = 0;
        for (int alph = 1; alph <= counter; alph++)
        {
            printf("%c", letters+add);
            add++;
        }
        counter += 2;
        printf("\n");
    }

    return 0;
}