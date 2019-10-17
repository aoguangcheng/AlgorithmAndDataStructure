#include<stdio.h>
#include<string.h>
#define MAX 100
#define max(a, b) a > b? a : b
int A[MAX][MAX];

int funcation(int b, int c, char B[], char C[])
{
	int i;
	int j;
	for(i = 0; i <= b; i++)
		A[0][i] = 0;
	for(i = 0; i <= c; i++)
		A[i][0] = 0;
	for(i = 1; i <= b; i++)
		for(j = 1; j <= c; j++)
		{
			if(B[i - 1] == C[i - 1])
				A[i][j] = A[i - 1][j - 1] + 1;
			else
				A[i][j] = max(A[i][j - 1], A[i - 1][j]);
		}
		return 1;
}
int main()
{
	int b;
	int c;
	int i;
	int j;
	char B[] = {'a', 'b', 'c', 'b', 'c'};
	char C[] = {'a', 'c', 'c', 'b', 'a'};
	b = strlen(B);
	c = strlen(C);
	funcation(b, c, B, C);
	for(i = 0; i <= b; i++)
		for(j = 0; j <= c; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	return 0;
}
