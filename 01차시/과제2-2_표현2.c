#include <stdio.h>
#define ROWS 3
#define COLS 3
#define MAX_TERMS 10

typedef struct
{
	int row;
	int col;
	int value;
}element;

typedef struct sparseMatrix
{
	element data[MAX_TERMS];
	int row;
	int cols;
	int terms;

}SparseMatrix;

int FindValue(SparseMatrix M, int r, int c)
{
	int i;
	for (i = 0; i < M.terms; i++)
	{
		if (M.data[i].row == r && M.data[i].col == c)
			return M.data[i].value;
	}
	return 0;
}

SparseMatrix Sparse_matrix_add2(SparseMatrix a, SparseMatrix b)
{
	SparseMatrix c;
	int i, j, k,multi = 0,ca = 0,cb = 0,cc = 0;

	if (a.row != b.row || a.cols != b.cols)
	{
		printf("stderr, 희소행렬 크기 에러\n");
		exit(1);
	}
	c.row = a.row;
	c.cols = b.cols;
	c.terms = 0;
	
	for (i = 0; i < c.row; i++)
	{
		multi = 0;
		for (j = 0; j <c.cols; j++)
		{
			for (k = 0; k < c.row; k++)
				multi += FindValue(a, i, k) * FindValue(b, k, j);
				
			if (multi != 0)
			{
				c.data[cc].row = i;
				c.data[cc].col = j;
				c.data[cc++].value = multi;
			}
		}
	}
	c.terms = cc;

	return c;
}

int main(void)
{
	SparseMatrix m1 = { { { 1,1,5 },{ 2,2,9 } },3,3,2 };
	SparseMatrix m2 = { { { 0,0,5 },{ 2,2,9 } },3,3,2 };
	SparseMatrix m3;
	m3 = Sparse_matrix_add2(m1, m2);
	int i, j;

	printf("행렬원소:");
	for (i = 0; i < m3.terms; i++)
		printf("  %d  ", m3.data[i].value);

	printf("\n");

	printf("행렬위치:");
	for (i = 0; i < m3.terms; i++)
		printf("[%d %d]", m3.data[i].row, m3.data[i].col);

	printf("\n");
	system("pause");
	return 0;
}