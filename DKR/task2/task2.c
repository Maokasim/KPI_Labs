#include <stdio.h>

#define siz 10

void setArray(int *array, int size);
void printArray(int *array, int size);

int main()
{
    int arr[siz]={4, 0, -9, -2, 8, 12, -15, 3, 0, 7};

    printArray(arr, siz);
    setArray(arr, siz);
    printArray(arr, siz);

    return 0;
}

void setArray(int *array, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (array[i] < 0){
            array[i] = -1;
        }
        if (array[i] > 0){
            array[i] = 1;
        }

    }
}

void printArray(int *matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", matrix[i]);
    }
    printf("\n");
}