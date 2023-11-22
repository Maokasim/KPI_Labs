#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>

double func(double x);
double method1(double a, double b, double delta);
double method2(double a, double b, double delta);
double method3(double a, double b, double delta);
double method4(double a, double b, double delta);

int main()
{

    double l_boundary_a, r_boundary_b, delta, integral, l1, l2;
    int variant, Intervals_Number;
    char q = 0;
    bool stop = 0;

    printf("\n\tEnter the left boundary \n X(first) =");
    scanf("%lf", &l_boundary_a);
    printf("\n\tEnter the right boundary \n X(last) =");
    scanf("%lf", &r_boundary_b);
    if ((r_boundary_b - l_boundary_a) <= 0)
    {
        printf("Wrong boundaries value");
        return 0;
    }

    printf("\n\tEnter the number of intervals intervals\n Intervals number =");
    scanf("%d", &Intervals_Number);
    if (Intervals_Number < 0)
    {
        printf("Wrong Interval numbers value");
        return 0;
    }

    while (1)
    {
        l1 = integral;

        delta = (double)((r_boundary_b - l_boundary_a) / Intervals_Number);

        if (!stop) // it`s check weather we continue calculation (if so it`s no need in variant input) or we just reboot program
        {
            printf("Enter variant (1 - 4) = ");
            scanf("%i", &variant);
        }

        switch (variant)
        {
        case 1:
            integral = method1(l_boundary_a, r_boundary_b, delta);
            break;
        case 2:
            integral = method2(l_boundary_a, r_boundary_b, delta);
            break;
        case 3:
            integral = method3(l_boundary_a, r_boundary_b, delta);
            break;
        case 4:
            integral = method4(l_boundary_a, r_boundary_b, delta);
            break;
        default:
            printf("Wrong variant value \n");
        }

        printf("integral value is %lf \n", integral);

        if (!stop) // it`s check weather we continue calculation (if so it`s no need to interrupt calculations until its done)
        {
            printf("Press ANY key to restart program / C to continue calculation / Q to quit ");
            q = getch();
        }

        if (q == 'q')
        {
            return 0;
        }
        else if (q == 'c')
        {
            l2 = integral;
            if (fabs(l1 - l2) >= 0.001)
            {
                Intervals_Number += 2;
                printf("interval numbers  %d \n", Intervals_Number);
                stop = 1;
            }
            else
            {
                stop = 0;
            }
        }
        else
        {
            system("cls");
        }
    }
}

double func(double x)
{
    // double y = x; // changed func for debugging
    // printf("y %lf\n", y); //debag output used for monitoring func value

    // double y = (double)(pow(2, x) + pow(x, 2));
    double y = sqrt(pow((18 / (pow((9 * x + 3), 2))), 2) + 256);

    return y;
}

double method1(double a, double b, double delta) // left rectangle method
{
    double S = 0;
    printf("method 1 (Left rectangle)\n");
    for (double i = a; i < b; i += delta)
    {
        S += func(i);
    }

    double answ = (double)(delta * S);

    return answ;
}

double method2(double a, double b, double delta) // right rectangle method
{
    double S = 0;
    printf("method 2 (Right rectangle method)\n");
    /*differences from LEFT rectangle method are that start sequence: i = a + delta and test expression: <= (NOT just less) right boundary
    it provides us rectangles which are one value "right" */
    for (double i = a + delta; i <= b; i += delta)
    {
        S += func(i);
    }

    double answ = (double)(delta * S);

    return answ;
}

double method3(double a, double b, double delta) // trapezium method
{
    double S = 0;

    printf("method 3 (Trapezium method) \n");

    for (double i = a; i < b; i += delta)
    {
        S += (func(i) + func(i + delta)) / 2;
    }

    double answ = (double)(delta * S);

    return answ;
}

double method4(double a, double b, double delta) // Simpson method
{
    double S = 0;
    int iteration = 0;

    printf("method 4 (Simpson method)\n");

    for (double i = +delta; i < b; i += delta)
    {
        iteration++;
        if (iteration % 2)
            S += 4 * func(i);
        else
        {
            S += 2 * func(i);
        }
    }

    double answ = (double)((func(a) + func(b) + S) * delta / 3);

    return answ;
}

/*
-7 + 4

0000 0100

0000 0111
1111 1000

1111 1001
0000 0100
1111 1101
0000 0010
0000 0011

AB CD EF
1010 1011 1100 1101 1110 1111


*/