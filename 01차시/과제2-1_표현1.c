#include <stdio.h>
#define ROWS 3
#define COLS 3

void sparse_matrix_add1(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS])
{
	int i, j;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
			C[i][j] = A[i][j] + B[i][j];
	}
}

int main(void)
{
	int i, j;
	int arr1[ROWS][COLS] = { {2,3,0},{8,9,1},{7,0,5} };
	int arr2[ROWS][COLS] = { {1,0,0},{1,0,0},{1,0,0} };
	int arr3[ROWS][COLS];

	sparse_matrix_add1(arr1, arr2, arr3);
	printf("µ¡»ù °á°ú\n\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			printf("%d  ", arr3[i][j]);
		printf("\n\n");
	}

	system("pause");
	return 0;
}