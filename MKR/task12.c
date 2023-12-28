#include <stdio.h>

double function(double x);

int main()
{
    printf("x  = -10.0 func = %lf \n", function(-10.0));
    printf("x  = 10.0 func = %lf \n", function(10.0));
    printf("x  = 3.0 func = %lf \n", function(3.0));

    return 0;
}

double function(double x)
{
    if (x < -5.0)
        return x / 2;

    if (x > 5.0)
        return x - x / 2;

    else
        return 0;
}