#include<stdio.h>
int A[] = {1, 2, 3, 4, 5};
int B[5];

void fun(int i)
{
	if(i == 5)
	{
		int j;
		for(j = 0; j <= 4; j++)
		{
			if(B[j] == 1)
			{
				printf("%d ", A[j]);
			}
		}
		printf("\n");
	}
	else
	{
		B[i] = 1;
		fun(i++);
		B[i] = 0;
		fun(i++);
	}
}

int main()
{
	fun(0);
	return 0;
}