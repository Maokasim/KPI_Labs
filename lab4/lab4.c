#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

double **createMatrix(int row, int column);
double **transpose(double **matrix, int row, int column);
double **mult_a_b(double **matrixA, int rowA, int columnA, double **matrixB, int rowB, int columnB);
void setMatrixSquare(double **matrix, int row, int column);
void setMatrixLinear(double **matrix, int row, int column);
void printMatrix(double **matrix, int row, int column);
double maxElements(double **matrix, int row, int column);

void swap(int *a, int *b);

int main()
{
    int r = 8, c = 8;

    printf("Before swap: R %d, C %d ", r, c);
    swap(&r, &c);
    printf("After swap: R %d, C %d \n", r, c);

    printf("matrix A\n");
    double **matrixA = createMatrix(r, c);
    setMatrixLinear(matrixA, r, c);
    printMatrix(matrixA, r, c);

    printf("\n");
    printf("transposed A\n");

    printMatrix(transpose(matrixA, r, c), r, c);

    printf("\n");

    printf("matrix B\n");
    double **matrixB = createMatrix(r, c);
    setMatrixSquare(matrixB, r, c);
    printMatrix(matrixB, r, c);

    printf("\n");

    printf("Multiplication\n");
    double **mult = mult_a_b(matrixA, r, c, matrixB, r, c);
    printMatrix(mult, r, c);

    printf("max element A: %lf", maxElements(matrixA, r, c));

    return 0;
}

double **createMatrix(int row, int column)
{
    int i, j;
    double count = 0;

    double **matrix = (double **)malloc(row * sizeof(double *));
    for (i = 0; i < row; i++)
        matrix[i] = (double *)malloc(column * sizeof(double));

    return matrix;
}

void printMatrix(double **matrix, int row, int column)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

double **transpose(double **matrix, int row, int column)
{
    int i, j;

    double **transposedMatrix = (double **)malloc(row * sizeof(double *));
    for (i = 0; i < row; i++)
        transposedMatrix[i] = (double *)malloc(column * sizeof(double));

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            transposedMatrix[i][j] = matrix[j][i];
        }
    }

    return transposedMatrix;
}

double **mult_a_b(double **matrixA, int rowA, int columnA, double **matrixB, int rowB, int columnB)
{

    if (columnA == rowB)
    {
        int i, j;

        double **mult = (double **)calloc(rowA, rowA * sizeof(double *));
        for (i = 0; i < rowA; i++)
            mult[i] = (double *)calloc(columnB, columnB * sizeof(double));

        for (i = 0; i < rowA; i++)
        {
            for (j = 0; j < columnB; j++)
            {
                for (int k = 0; k < rowB; k++)
                {
                    mult[i][j] += matrixA[i][k] * matrixB[k][j];
                }
            }
        }

        return mult;
    }
    else
    {
        printf("wrong input ");
    }
}

void setMatrixSquare(double **matrix, int row, int column)
{
    int i, j;
    double count = 0;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            matrix[i][j] = pow(count, 2) + 10;
            count++;
        }
    }
}

void setMatrixLinear(double **matrix, int row, int column)
{
    int i, j;
    double count = 0;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            matrix[i][j] = count++;
        }
    }
}

double maxElements(double **matrix, int row, int column)
{
    int i = 0, j = 0;

    double maxElement = matrix[i][j];

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            if (maxElement < matrix[i][j])
            {
                maxElement = matrix[i][j];
            }
        }
    }

    return maxElement;
}

void swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}