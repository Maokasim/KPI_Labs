#include <stdio.h>
#include <stdlib.h>

char star[] = "**************************************************************\n";
char teg[] = "##############################################################\n";

void printTable(FILE *outputFile, double startX, double endX, double dotCount, double deltaX);
void writeBinary(FILE *outputFile, double startX, double endX, double dotCount, double deltaX);
void readFile(FILE *inputFile);
double calcFunction(double xf);

int main()
{
    double startX, endX, dotCount, deltaX;
    char Group[5];
    char Name[50];
    char Surname[50];

    FILE *inputFile;
    FILE *outputFileTable;
    FILE *outputFileBinary;
    FILE *input1;

    inputFile = fopen("input", "r");
    outputFileTable = fopen("output.txt", "w");
    outputFileBinary = fopen("outputBinary.bin", "wb");

    fscanf(inputFile, "%lf %lf %lf %lf %s %s %s", &startX, &endX, &dotCount, &deltaX, Group, Name, Name);

    printf("%lf, %lf, %lf, %lf, %s, %s, %s", startX, endX, dotCount, deltaX, Group, Name, Surname);
    printTable(outputFileTable, startX, endX, dotCount, deltaX);
    fprintf(outputFileTable, "%s \n", Group);

    writeBinary(outputFileBinary, startX, endX, dotCount, deltaX);

    fclose(outputFileBinary);
    outputFileBinary = fopen("outputBinary.bin", "rb");

    readFile(outputFileBinary);

    fclose(inputFile);
    fclose(outputFileTable);
    fclose(outputFileBinary);

    return 0;
}

void printTable(FILE *outputFile, double startX, double endX, double dotCount, double deltaX)
{
    double x, Fx;
    int dot = 1;

    fprintf(outputFile, "Start X = %lf, End X = %lf, delta = %lf\n", startX, endX, deltaX);
    fprintf(outputFile, star);
    fprintf(outputFile, "*    N    *            X            *          F(x)          *\n");
    fprintf(outputFile, star);

    for (x = startX; x <= endX; x = x + deltaX)
    {
        Fx = calcFunction(x);

        fprintf(outputFile, "#    %i    #        %lf        #       %lf       #\n", dot++, x, Fx);
        fprintf(outputFile, teg);
    }
}
void writeBinary(FILE *outputFile, double startX, double endX, double dotCount, double deltaX)
{

    double x, Fx;
    int dots = (int)((endX - startX) / deltaX) * 2 + 1;
    int dotNumber = 1;
    double answARR[dots];

    answARR[0] = dots;

    for (x = startX; x <= endX; x = x + deltaX)
    {
        Fx = calcFunction(x);
        answARR[dotNumber] = x;
        answARR[dotNumber + 1] = Fx;
        dotNumber += 2;
    }

    fwrite(answARR, sizeof(double), dots, outputFile);
}

void readFile(FILE *inputFile)
{
    int countint;
    double dotCount;

    fread(&dotCount, sizeof(double), 1, inputFile);
    countint = (int)dotCount - 2;

    double read[countint];

    printf("\n dots is %lf stop\n", dotCount);

    fread(read, sizeof(double), countint, inputFile);
    for (int i = 0; i <= countint; i++)
    {
        printf("%lf \n", read[i]);
    }
}

double calcFunction(double xf)
{
    double yf = 2 * xf * xf - 3 * xf * xf * xf + 1500 * xf - 12000;

    return yf;
}