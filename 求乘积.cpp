#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	int S = 0;
	scanf("%d", &n);
	int A[5][5];
	for(int i = 1; i < n; i++)
	{
		scanf("%d", &A[0][i]);
	}
	for(int j = 1; j < n; j++)
	{
		scanf("%d", &A[0][j]);
	}

	for(i = 1; i < n; i++)
	{
		for(j = 1; j < n; j++)
		{
			A[i][j] = A[0][j] * A[i][0];
		}
	}

	for(i = 1; i < n; i++)
	{
		for(j = 1; j < n; j++)
		{
			S = S + A[i][j] * pow(10, i + j);
		}
	}

	printf("%d", S);
	return 0;
}