#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void single_digit(int number, char ones_array[100][100])
{
    printf("%s", ones_array[number]);
}

void two_digit(int number, char ones_array[100][100], char tenths_array[100][100], char secondary_array[100][100])
{
    int tenths_digit, ones_digit;

    tenths_digit = ((number / 10) % 10);

    ones_digit = (number % 10);

    if ((number % 10) == 0)
    {
        printf("%s", secondary_array[tenths_digit - 1]);
    }
    else if (tenths_digit == 1)
    {
        printf("%s", tenths_array[ones_digit - 1]);
    }
    else if ((tenths_digit >= 2) && (tenths_digit <= 9))
    {
        printf("%s %s ", secondary_array[tenths_digit - 1], ones_array[ones_digit]);
    }
}

void three_digit(int num, char ones_array[100][100], char tenths_array[100][100], char secondary_array[100][100], char tertiary_array[100][100])
{
    int hundreths_digit, tenths_digit, ones_digit;

    hundreths_digit = ((num / 100) % 100);
    tenths_digit = ((num / 10) % 10);
    ones_digit = (num % 10);

    if ((tenths_digit == 0) && (ones_digit == 0))
    {
        printf("%s %s", ones_array[hundreths_digit], tertiary_array[0]);
    }
    else if ((tenths_digit == 1) && (ones_digit >= 1) && (ones_digit <= 9))
    {
        printf("%s %s %s", ones_array[hundreths_digit], tertiary_array[0], tenths_array[ones_digit - 1]);
    }

    else if ((tenths_digit >= 1) && (tenths_digit <= 9) && (ones_digit == 0))
    {
        printf("%s %s %s", ones_array[hundreths_digit], tertiary_array[0], secondary_array[tenths_digit - 1]);
    }
    else if ((tenths_digit >= 2) && (tenths_digit <= 9) && (ones_digit <= 9))
    {
        printf("%s %s %s %s", ones_array[hundreths_digit], tertiary_array[0], secondary_array[tenths_digit - 1], ones_array[ones_digit]);
    }
}

void four_digit(int num, char ones_array[100][100], char tenths_array[100][100], char secondary_array[100][100], char tertiary_array[100][100])
{
    int thousandths_digit, hundreths_digit, tenths_digit, ones_digit;

    thousandths_digit = ((num / 1000) % 1000);
    hundreths_digit = ((num / 100) % 10);
    tenths_digit = ((num / 10) % 10);
    ones_digit = (num % 10);

    // 1000 - 9000
    if ((hundreths_digit == 0) && (tenths_digit == 0) && (ones_digit == 0))
    {
        printf("%s %s", ones_array[thousandths_digit], tertiary_array[1]);
    }
    // 1100 - 1900
    else if ((hundreths_digit >= 1) && (hundreths_digit <= 9) && (tenths_digit == 0) && (ones_digit == 0))
    {
        printf("%s %s %s %s", ones_array[thousandths_digit], tertiary_array[1], ones_array[hundreths_digit], tertiary_array[0]);
    }
    // 10 - 90 by 10
    else if ((hundreths_digit >= 1) && (hundreths_digit <= 9) && (tenths_digit >= 1) && (tenths_digit <= 9) && (ones_digit == 0))
    {
        printf("%s %s %s %s %s", ones_array[thousandths_digit], tertiary_array[1], ones_array[hundreths_digit], tertiary_array[0], secondary_array[tenths_digit - 1]);
    }
    // 11 - 19
    else if ((hundreths_digit >= 1) && (hundreths_digit <= 9) && (tenths_digit == 1) && (ones_digit >= 1) && (ones_digit <= 9))
    {
        printf("%s %s %s %s %s", ones_array[thousandths_digit], tertiary_array[1], ones_array[hundreths_digit], tertiary_array[0], tenths_array[ones_digit - 1]);
    }
    // 21 - 99
    else if ((hundreths_digit >= 1) && (hundreths_digit <= 9) && (tenths_digit >= 2) && (tenths_digit <= 9) && (ones_digit >= 1) && (ones_digit <= 9))
    {
        printf("%s %s %s %s %s %s", ones_array[thousandths_digit], tertiary_array[1], ones_array[hundreths_digit], tertiary_array[0], secondary_array[tenths_digit - 1], ones_array[ones_digit]);
    }
}

int main(void)
{

    char get_char[100];
    int rem_zero, len;

    // Array of words numbers
    char ones[100][100] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    char tenths[100][100] = {"Eleven", "Twelve", "Thirteen", "Forteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    char secondary[100][100] = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    char tertiary[100][100] = {"Hundred", "Thousand"};

    // Get user Input
    printf("Enter a number: ");
    fgets(get_char, sizeof(get_char), stdin);
    int input_len = strlen(get_char) - 1;

    // ginchecheck kung may zero ha front
    int j = 0;
    if (input_len == 1)
    {
        if (atoi(get_char) == 0)
        {
            rem_zero = atoi(get_char);
            len = input_len;
        }
        else
        {
            rem_zero = atoi(get_char);
            len = input_len;
        }
    }
    else
    {
        while (get_char[j] == '0')
        {
            j++;
        }
        rem_zero = atoi(get_char + j);
        len = input_len - j;
    }

    // Conditions
    if (len == 1)
    {
        single_digit(rem_zero, ones);
    }

    else if (len == 2)
    {
        two_digit(rem_zero, ones, tenths, secondary);
    }
    else if (len == 3)
    {
        three_digit(rem_zero, ones, tenths, secondary, tertiary);
    }
    else if (len == 4)
    {
        four_digit(rem_zero, ones, tenths, secondary, tertiary);
    }
}