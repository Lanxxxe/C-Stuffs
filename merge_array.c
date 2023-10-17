#include <stdio.h>
#include <string.h>

void for_arr1(int count1, int count3, char array1[][100], char array3[][100])
{
    strcpy(array3[count3], array1[count1]);
}

void for_arr2(int count2, int count3, char array2[][100], char array3[][100])
{
    strcpy(array3[count3], array2[count2]);
}

void merge(char array1[100][100], char array2[100][100], char array3[100][100], int array1_size, int array2_size)
{
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;

    while (count1 < array1_size && count2 < array2_size)
    {
        if (strcmp(array1[count1], array2[count2]) < 0)
        {
            for_arr1(count1, count3, array1, array3);
            count1++;
        }
        else
        {
            for_arr2(count2, count3, array2, array3);
            count2++;
        }
        count3++;
    }

    while (count1 < array1_size)
    {
        for_arr1(count1, count3, array1, array3);
        count1++;
        count3++;
    }

    while (count2 < array2_size)
    {
        for_arr2(count2, count3, array2, array3);
        count2++;
        count3++;
    }
}

void sorting_array(char array[100][100], int size)
{
    char temp[100];
    int counter1 = 0;
    while (counter1 < size - 1)
    {
        int counter2 = counter1 + 1;
        while (counter2 < size)
        {
            if (strcmp(array[counter1], array[counter2]) > 0)
            {
                strcpy(temp, array[counter1]);
                strcpy(array[counter1], array[counter2]);
                strcpy(array[counter2], temp);
            }
            counter2++;
        }
        counter1++;
    }
}

int main(void)
{
    char first_array[100][100];
    char second_array[100][100];
    char third_array[100][100];
    int n1, n2;

    // Getting User Input
    printf("Enter the number of strings for the first array: ");
    scanf("%d", &n1);

    for (int i = 0; i < n1; i++)
    {
        printf("Array1 Index[%d]: ", i);
        scanf("%s", first_array[i]);
    }

    printf("\nEnter the number of strings for the second array: ");
    scanf("%d", &n2);

    for (int j = 0; j < n2; j++)
    {
        printf("Array2 Index[%d]: ", j);
        scanf("%s", second_array[j]);
    }

    // Merge the arrays
    merge(first_array, second_array, third_array, n1, n2);

    // Print the result
    sorting_array(third_array, n1 + n2);
    printf("\nResult: ");
    for (int k = 0; k < n1 + n2; k++)
    {
        printf("%s ", third_array[k]);
    }
    return 0;
}
