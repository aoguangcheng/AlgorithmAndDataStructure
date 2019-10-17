#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int i;
	int sum = 1;
	for(i = 1; i <= n; i++)
	{
		sum = sum * i;
	}
	printf("%d", sum);
	return 0;
}
