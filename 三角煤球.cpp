#include<stdio.h>

int main()
{
	int A[100];
	int sum = 0;
	A[0] = 1;
	for(int i = 1; i < 100; i++)
	{
		A[i] = A[i - 1] + i + 1;
	}
	for(i = 0; i < 100; i++)
	{
		printf("%d \n", A[i]);
		sum += A[i];
	}
	printf("%d", sum);
	return 0;
}