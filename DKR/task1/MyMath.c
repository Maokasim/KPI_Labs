#include "MyMath.h"

double mypow(double base_number, int power)
{
    double result;

    if (power == 0 && base_number != 0)
    {
        result = 1;
    }
    else if (power != 0 && base_number == 0)
    {
        result = 0;
    }
    else if (power > 0 && base_number != 0)
    {
        result = base_number; // taking number to 1-st power

        for (int i = 0; i < power - 1; i++) // i<power-1 becouse we alreeady get to first power
        {
            result *= base_number;
        }
    }
    else if (power < 0 && base_number != 0)
    {
        result = 1 / base_number; // taking number to -1-st power

        for (int i = 0; i > power + 1; i--) // i<power+1 becouse we alreeady get to minus first power
        {
            result *= 1 / base_number;
        }
    }

    return result;
}

long int myfactorial(int number)
{
    long int result = number;
    if (number == 0)
    {
        result = 1;
    }

    else if (number > 0)
    {
        for (long int iteration_number = number - 1; iteration_number > 0; iteration_number--)
        {
            result *= iteration_number;
        }
    }
    else
    {
        result = 0;
    }

    return result;
}