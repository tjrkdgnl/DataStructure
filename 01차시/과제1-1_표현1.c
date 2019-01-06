#include <stdio.h>

#define MAX(a,b) ((a)>(b) ? (a):(b))
#define Max_DEGREE 101

typedef struct
{
	int degree;
	int coef[Max_DEGREE];
	int deg[Max_DEGREE];
}polynomial;

polynomial poly_add1(polynomial A, polynomial B)
{
	polynomial C;
	int Apos = 0, Bpos = 0, Cpos = 0;
	int degree_a = A.degree;
	int degree_b = B.degree;
	
	C.degree = MAX(A.degree, B.degree);

	while (Apos <= A.degree && Bpos <= B.degree)
	{
		if (degree_a > degree_b)
		{
			C.coef[Cpos] = A.coef[Apos++];
			C.deg[Cpos] = degree_a;
			degree_a--,Cpos++;;
			
		}
		else if (degree_a == degree_b)
		{
			C.coef[Cpos] = A.coef[Apos++] - B.coef[Bpos++];
			C.deg[Cpos] = degree_a;
			degree_a--, degree_b--;
			Cpos++;
		}
		else
		{
			C.coef[Cpos] = B.coef[Bpos++];
			C.deg[Cpos] = degree_b;
			degree_b--;
			Cpos++;
		}
	}
	return C;
}

int main(void)
{
	int i;
	polynomial a = { 5,{3,6,0,0,0,10}};
	polynomial b = { 4,{7,0,5,0,1}};
	polynomial c;

	c = poly_add1(a, b);

	printf("다항식 계수:");
	for (i = 0; i < 6; i++)
	{
		if (c.coef[i] == 0)
			continue;
		printf("%d ", c.coef[i]);
	}
		printf("\n");

		printf("다항식 차수:");
		for (i = 0; i < 6; i++)
		{
			if (c.coef[i] == 0)
				continue;
			printf("%d ", c.deg[i]);
		}
	system("pause");
	return 0;
}