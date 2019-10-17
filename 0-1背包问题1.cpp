#include<stdio.h>
#define MAX  100
#define MAXN 1000
#define n1 5
#define c1 14
int A[MAX][MAXN];
#define max(a , b)  a > b ? a : b
int funcation(int n, int c, int W[], int V[])
{
	int i;
	int j;

	for(i = 0, j = 0; j <= c; j++)
	{
		A[i][j] = 0;
	}
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= c; j++)
		{
			if(j < W[i])
				A[i][j] = A[i - 1][j];
			else
				A[i][j] = max(A[i - 1][j], A[i - 1][j - W[i]] + V[i]);
		}
	}
	return 1;
}

int main()
{
//	scanf("%d\n", &n);
//	scanf("%d\n", &c);
	int W[n1+1] = {5, 3, 2, 5, 2, 1};
	int V[n1+1] = {6, 5, 4, 3, 2, 1};
	int i;
	int j;

/*
	for(i = 1; i <= n; i++)
	{
		scanf("%d ", W[i]);
	}
	scanf("\n");
	for(i = 1; i <= n; i++)
	{
		scanf("%d ", &V[i]);
	}*/
//	printf("\n");
	funcation(n1, c1, W, V);
	for(i = 0; i <= n1; i++)
	{
		for(j = 0; i <= c1; j++)
		{
			printf("%-3d", A[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	printf("%d", A[n1][c1]);
	return 0;
}