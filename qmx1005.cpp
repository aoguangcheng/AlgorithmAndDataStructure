#include<stdio.h>

int main()
{
	int n;
	int A[10];
	int i;
	
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	for(i = 0; i < n; i++)
	{
		if(A[i] % 2 == 0 && A[i] > 3)
		{
			printf("yes");
		}
		else
		{
			printf("no");
		}
		if(i < n - 1)
		{
			printf("\n");
		}
	}
	return 0;
 } 
