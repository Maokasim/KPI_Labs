#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


double y(double xf);

char star[] = "**************************************************************\n";
char teg[] = "##############################################################\n";

int main()
{

    unsigned int variant;
    int N;
    int dot = 1;

    double startx, delta, endx, x, Fx;

    char q;


    printf("Enter variant (1 or 2)\n");
    scanf("%i", &variant);

    if (variant == 1)
    {
        printf("**********input var 1**********\n");

        printf("input start x\n");
        scanf("%lf", &startx);

        printf("input end x\n");
        scanf("%lf", &endx);

        printf("input number of dots in table\n");
        scanf("%i", &N);

        delta = ((endx - startx) / N);
    }

    else if (variant == 2)
    {
        printf("***********input var 2**********\n");

        printf("input start x\n");
        scanf("%lf", &startx);

        printf("input end x\n");
        scanf("%lf", &endx);

        printf("input delta between dots\n");
        scanf("%lf", &delta);

        N = (int)(endx - startx) / delta;
    }
    else if(variant==3)
    {
        printf ("test3");
    }
    else
    {
        printf("Variant not valid\n");
        return 0;
    }

    while (1)
    {
        printf("Start X = %lf, End X = %lf, delta = %lf\n", startx, endx, delta);
        printf(star);
        printf("*    N    *            X            *          F(x)          *\n");
        printf(star);

        for (x = startx; x <= endx; x = x + delta)
        {
            Fx = y(x);

            printf("#    %i    #        %lf        #       %lf       #\n", dot++, x, Fx);
            printf(teg);
        }

        printf("Press any key to continue or q to quit");
        q = getch();
        if (q == 'q')
        {
            return 0;
        }
        dot = 1;
        endx = endx * 5;
        system("cls");
    }

    return 0;
}

double y(double xf)
{
    double yf = 2 * xf * xf - 3 * xf * xf * xf + 1500 * xf - 12000;

    return yf;
}