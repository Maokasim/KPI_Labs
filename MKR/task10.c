#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num_of_elements = 0;
	double output = 0;

	printf("Enter number of elements = ");
	scanf("%d", &num_of_elements);

	double *array = (double *)malloc(num_of_elements * sizeof(double));

	if (array == NULL)
	{
		printf("Failed to allocate memory for array \n");
		return 0;
	}

	for (int i = 0; i < num_of_elements; i++)
	{
		double test;
		printf("\n Enter %d element of array ", i);
		scanf("%lf", &array[i]);
	}

	output = array[0] + array[num_of_elements - 1];
	printf("Sum of first and last element of array = %lf  \n", output);

	free(array);

	return 0;
}
