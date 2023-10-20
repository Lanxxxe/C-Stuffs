#include <stdio.h>

int main(void)
{

    int num;

    printf("Enter 5 man team: ");

    while ((num = getchar()) != '\n' && num != EOF)
    {
        if (num >= '0' && num <= '9')
        {
            putchar(num);
            putchar(' ');
        }
    }
    printf("\n");
}
