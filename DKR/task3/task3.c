/*
This is task 3 of DKR the point is to search 4 most common digits in input file
The point of usage of such function and code construction is to provide flexibility of searched objective
It can be easily switched to search any character, and with slight changes even can search and count strings
*/

#include <stdio.h>
#include <stdlib.h>

void SortNumbers(int number_of_digits[][2], int amount_of_digits);

int main()
{
    int number_of_digits[10][2] = {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0}};
    FILE *inputFile = fopen("input.txt", "r");

    int character;

    if (inputFile == NULL)
    {
        printf("could not open input file");
        return 0;
    }

    while ((character = fgetc(inputFile)) != EOF)
    {
        switch ((char)character)
        {
        case '0':
            number_of_digits[0][1] += 1;
            break;
        case '1':
            number_of_digits[1][1] += 1;
            break;
        case '2':
            number_of_digits[2][1] += 1;
            break;
        case '3':
            number_of_digits[3][1] += 1;
            break;
        case '4':
            number_of_digits[4][1] += 1;
            break;
        case '5':
            number_of_digits[5][1] += 1;
            break;
        case '6':
            number_of_digits[6][1] += 1;
            break;
        case '7':
            number_of_digits[7][1] += 1;
            break;
        case '8':
            number_of_digits[8][1] += 1;
            break;
        case '9':
            number_of_digits[9][1] += 1;
            break;

        default:
            break;
        }
    }

    SortNumbers(number_of_digits, 10);

    printf("Top 4 most common digits in input file \n");
    printf("digit|number of digits \n");
    for (int i = 9; i >= 6; i--)
    {
        printf("%d found %d times \n", number_of_digits[i][0], number_of_digits[i][1]);
    }

    fclose(inputFile);

    return 0;
}

void SortNumbers(int number_of_digits[][2], int amount_of_digits)
{
    int i = 0, j = 0;

    int maxElement = number_of_digits[j][1];
    int maxElement_digit = number_of_digits[j][0];

    int minElement = number_of_digits[j][1];
    int minElement_digit = number_of_digits[j][0];

    int lostElement;

    for (i = amount_of_digits - 1; i > +0; i--)
    {

        for (j = 0; j < i; j++)
        {
            if (maxElement < number_of_digits[j][1])
            {
                maxElement = number_of_digits[j][1];
                maxElement_digit = number_of_digits[j][0];
                lostElement = j;
            }
            if (minElement > number_of_digits[j][1])
            {
                minElement = number_of_digits[j][1];
                minElement_digit = number_of_digits[j][0];
            }
        }
        number_of_digits[lostElement][1] = number_of_digits[i][1];
        number_of_digits[lostElement][0] = number_of_digits[i][0];
        number_of_digits[i][1] = maxElement;
        number_of_digits[i][0] = maxElement_digit;
        maxElement = minElement;
        maxElement_digit = i;
    }
}