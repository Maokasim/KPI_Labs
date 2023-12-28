#include <stdio.h>
#include "MyMath.h"

int main()
{
    int N;
    long double sum_of_series = 0;
    printf("input the max number of series ");
    scanf("%d", &N);

    if (N > 20)
    {
        printf("factorial numbers are too big to calculate \n"); // it can be fixed with division wished number into two variables mantissa and exponent,
        return 0;                                                // but I consider that achieved numbers are enough for this task
    }
    if (N < 0)
    {
        printf("can not take a factorial of negative number \n");
        return 0;
    }
    for (int n = 0; n <= N; n++)
    {
        sum_of_series += (long double)(mypow(2, n) / myfactorial(n));
    }
    printf("the sum of the series = %Lf \n", sum_of_series);

    return 0;
}