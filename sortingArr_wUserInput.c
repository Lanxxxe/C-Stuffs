#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_element 100
#define max_char 100

void Sort_Arr(char Arr1[][max_char], int size)
{
    char temp[100];
    int Ctr1 = 0;
    while (Ctr1 < size - 1)
    {
        int Ctr2 = Ctr1 + 1;
        while (Ctr2 < size)
        {
            if (strcmp(Arr1[Ctr1], Arr1[Ctr2]) > 0)
            {

                strcpy(temp, Arr1[Ctr1]);
                strcpy(Arr1[Ctr1], Arr1[Ctr2]);
                strcpy(Arr1[Ctr2], temp);
            }
            Ctr2++;
        }
        Ctr1++;
    }
}

void display(char arr[][max_char], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s", arr[i]);
        if (i < size - 1)
        {
            printf(" ");
        }
    }
}

int main()
{
    int num_arr;
    char array_list[max_element][max_char];

    printf("---------------------------------------------------------------------------------------------------------------------------------\n");
    printf("NOTE. Please enter a minimum of 3 names or characters to be sorted.The program will not acquire less than 3 names or characters.\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------\n\n");

    do
    {
        printf("Input number of Elements: ");
        scanf("%d", &num_arr);

        if (num_arr < 3)
        {
            printf("Please input minium of 3 elements.\n");
        }
    } while (num_arr < 3);

    for (int x = 0; x < num_arr; x++)
    {
        printf("Element [%d] = ", x);
        scanf("%s", &array_list[x]);
    }

    printf("OUTPUT");
    printf("\n\n");
    printf("Original Array ==> ");
    display(array_list, num_arr);

    printf("\n\nSorted Array ==> ");
    Sort_Arr(array_list, num_arr);
    display(array_list, num_arr);
    printf("\n\n");
    return 0;
}
