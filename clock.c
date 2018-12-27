#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	int score[10] = { 1,2,3,4,5,6,7,8,10 };
	int i, tmp;
	clock_t start, finish;
	double duration;
	start = clock();
	
	tmp = score[0];

	for (i = 1; i<9; i++)
	{
		if (score[i]> tmp)
			tmp = score[i];
	}
	finish = clock();
	duration = (double)(finish - start);
	CLOCKS_PER_SEC;
	printf("%f초입니다.\n", duration);

	return 0;
}
