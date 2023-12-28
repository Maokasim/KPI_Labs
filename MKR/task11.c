#include <stdio.h>

int main()
{
    unsigned int x, y, z;

    printf("Enter first side of triangle (x) = ");
    scanf("%u", &x);
    printf("Enter second side of triangle (y) = ");
    scanf("%u", &y);
    printf("Enter third side of triangle (z) = ");
    scanf("%u", &z);

    if ((x + y) > z && (x + z) > y && (y + z) > x)
        printf("1 \n");
    else
        printf("0 \n");

    return 0;
}
