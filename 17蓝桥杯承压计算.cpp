#include<stdio.h>

int main()
{
	double A[30][30];
	for(int i = 0; i < 30; i ++)
	{
		for(int j = 0; j <= i; j++)
		{
			scanf("%lf ", &A[i][j]);
		}
	}
	
/*	for(i = 0; i < 30; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			printf("%.1lf ", A[i][j]);
		}
		printf("\n");
	}*/

	A[1][0] =A[1][0]+ A[0][0] / 2;
	A[1][1] =A[1][1]+ A[0][0] / 2;
	for(i = 2; i < 30; i ++)
	{
		A[i][0] = A[i][0] + A[i - 1][0] / 2;
		A[i][i] = A[i][i] + A[i - 1][i - 1]/ 2;
		for(int j = 1; j <= i - 1; j++)
		{
			A[i][j]  = A[i][j] + (A[i - 1][j] + A[i - 1][j - 1]) / 2;
		}
	}

	double max = A[29][0];
	double min = A[29][0];
	for(i = 0; i < 30; i++)
	{
		if(max < A[29][i])
			max = A[29][i];
		if(min > A[29][i])
			min = A[29][i];
	}
	printf("%lf %lf", min, max * (2086458231 / min));
	return 0;
}
