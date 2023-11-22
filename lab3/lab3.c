#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "time.h"

#define TEST 0

double y(double xf);
double chord(double a, double b, int max_iteration, double delta, int test);
double halfdel(double a, double b, int max_iteration, double delta, int test);

int main()
{

    unsigned int variant;
    int max_iteration;

    double startx, delta, endx, x, Fx, answ;

    clock_t begin = clock();

    printf("Enter variant (1 or 2)\n");
    scanf("%i", &variant);

    if (variant == 1)
    {
        printf("**********var 1**********\n");

        printf("input start x\n");
        scanf("%lf", &startx);

        printf("input end x\n");
        scanf("%lf", &endx);

        printf("input max number of iteration\n");
        scanf("%i", &max_iteration);

        printf("input accuracy\n");
        scanf("%lf", &delta);

        answ = chord(startx, endx, max_iteration, delta, TEST);
    }

    else if (variant == 2)
    {
        printf("***********var 2**********\n");

        printf("input start x\n");
        scanf("%lf", &startx);

        printf("input end x\n");
        scanf("%lf", &endx);

        printf("input max number of iteration\n");
        scanf("%i", &max_iteration);

        printf("input accuracy\n");
        scanf("%lf", &delta);

        answ = halfdel(startx, endx, max_iteration, delta, TEST);
    }
    else
    {
        printf("Variant not valid\n");
        return 0;
    }

    printf("Y %lf X %lf \n", y(answ), answ);

    clock_t end = clock();
    double time_spent = (double)(end) / CLOCKS_PER_SEC;
    printf("time spent %lf", &time_spent);

    return 0;
}

double y(double xf)
{
    double yf = 2 * xf * xf - 3 * xf * xf * xf + 1500 * xf - 12000;

    return yf;
}

double chord(double a, double b, int max_iteration, double delta, int test)
{
    int iteration = 0;
    double x;
    double x_prev;
    double x_2prev;
    if (y(a) > 0)
    {
        x_2prev = a;
        x_prev = b;
        while (max_iteration > iteration)
        {
            x = x_prev - (y(x_prev) * (x_prev - x_2prev)) / (y(x_prev) - y(x_2prev));
            x_2prev = x_prev;
            x_prev = x;
            if (fabs(x_prev - x_2prev) < delta)
            {
                break;
            }
            if (test)
            {
                printf(" x value  %lf\n", x);
            }

            iteration++;
        }
    }

    if (y(a) < 0)
    {
        x_2prev = b;
        x_prev = a;
        while (max_iteration > iteration)
        {
            x = x_prev - (y(x_prev) * (x_prev - x_2prev)) / (y(x_prev) - y(x_2prev));
            x_2prev = x_prev;
            x_prev = x;
            if (fabs(x_prev - x_2prev) < delta)
            {
                break;
            }
            if (test)
            {
                printf(" x value  %lf\n", x);
            }

            iteration++;
        }
    }
    return x;
}

double halfdel(double a, double b, int max_iteration, double delta, int test)
{

    int iteration = 0;
    double x;
    double x_prev;
    double x_2prev;
    x_2prev = b;
    x_prev = a;

    while (max_iteration > iteration)
    {
        x = (x_prev + x_2prev) / 2;
        x_2prev = x_prev;
        x_prev = x;
        if (fabs(x_prev - x_2prev) < delta)
        {
            break;
        }
        if (test)
        {
            printf(" x value  %lf\n", x);
        }

        iteration++;
    }
}
