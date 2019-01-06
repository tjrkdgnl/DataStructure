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

SparseMatrix Sparse_matrix_add2(SparseMatrix a, SparseMatrix b)
{
	SparseMatrix c;
	int ca = 0, cb = 0, cc = 0;

	if (a.row != b.row || a.cols != b.cols)
	{
		printf("stderr, 희소행렬 크기 에러\n");
		exit(1);
	}
	c.row = a.row;
	c.cols = a.cols;
	c.terms = 0;

	while (ca < a.terms && cb < b.terms)
	{
		int inda = a.data[ca].row *a.cols + a.data[ca].col;
		int indb = b.data[cb].row *b.cols + b.data[cb].col;

		if (inda < indb)
			c.data[cc++] = a.data[ca++];

		else if (inda == indb)
		{
			if ((a.data[ca].value + b.data[cb].value) != 0)
			{
				c.data[cc].row = a.data[ca].row;
				c.data[cc].col = a.data[ca].col;
				c.data[cc++].value = a.data[ca++].value + b.data[ca++].value;
			}
			else
				ca++;  cb++;
		}

		else
			c.data[cc++] = b.data[cb++];
	}
	for (; ca < a.terms;)
		c.data[cc++] = a.data[ca++];

	for (; cb < b.terms;)
		c.data[cc++] = b.data[cb++];
	c.terms = cc;

	return c;
}

int main(void)
{
	SparseMatrix m1 = { {{1,1,5},{2,2,9}},3,3,2 };
	SparseMatrix m2 = { {{ 0,0,5 },{ 2,2,9 }},3,3,2 };
	SparseMatrix m3;
	m3 = Sparse_matrix_add2(m1, m2);
	int i, j;
	
	printf("행렬원소:");
	for (i = 0; i < m3.terms; i++)
		printf("  %d  ", m3.data[i].value);

	printf("\n");
	printf("행렬위치:");
	for (i = 0; i < m3.terms; i++)
		printf("[%d %d]", m3.data[i].row , m3.data[i].col);

	printf("\n");
	system("pause");
	return 0;
}