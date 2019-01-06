#include <stdio.h>

typedef struct _node
{
	int coef;
	int expon;
}terms;

// 0 2 3 5
void add1(terms *arr, int As, int Ae, int Bs, int Be, int *Cs, int *Ce)
{
	int Start = 6;
	*Cs = Start;
	int i;
	//0~5
	for (i = As; i < Be; i++)
	{
		if (arr[As].expon > arr[Bs].expon)
			arr[Start++] = arr[As++];

		else if (arr[As].expon == arr[Bs].expon)
		{
			arr[Start].coef = arr[As].coef - arr[Bs].coef;
			arr[Start].expon = arr[As].expon;
			Start++, As++, Bs++;
		}
		else
			arr[Start++] = arr[Bs++];

	}
	*Ce = Start;
}

int main(void)
{
	int Cs, Ce;
	terms arr[20] = { { 8,3 },{ 7,1 },{ 1,0 },{ 10,3 },{ 3,2 },{ 1,0 },0 };
	int i;

	add1(arr, 0, 2, 3, 5, &Cs, &Ce);

	printf("다항식 계수: ");
	for (i = Cs; i < Ce - 1; i++)
	{
		printf("%d ", arr[i].coef);
	}

	printf("\n");

	printf("다항식 차수: ");
	for (i = Cs; i < Ce - 1; i++)
	{
		printf("%d ", arr[i].expon);
	}

	printf("\n");
	system("pause");
	return 0;
}