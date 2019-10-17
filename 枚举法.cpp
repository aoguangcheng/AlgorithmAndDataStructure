#include<stdio.h>

void fun (int *A, int *B, int i)
{
	if(i == 5)
	{
		printf("{");
		for(int j = 0; j < 5; j++)
		{
			if(B[j] == 1)
			{
				printf("%d ", A[j]);
			}
			else
			{
				printf("  ");
			}
		}
		printf("}\n");
		return ;
	}
	B[i] = 1;
	fun(A, B, i+1);
	B[i] = 0;
	fun(A, B, i+1);
}
int main()
{
	int A[5] = {1, 2, 3, 4, 5};
	int B[5];
	fun (A, B, 0);
	return 0;
}