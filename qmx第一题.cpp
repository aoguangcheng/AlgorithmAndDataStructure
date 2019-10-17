#include<stdio.h>

int main()
{
	int m; 
	int n;
	int k;
	int sum = 0;
	scanf("%d %d %d\n", &m, &n, &k);
	int count = m * n;
	for(int i = 0; i < count; i++)
	{
		char ch;
		scanf("%c ", &ch);
		if(ch == 'X')
		{
			sum++;
		}
	}
	printf("%d", k - sum);
	return 0;
}