#include<stdio.h>
//(a*b)%c=((a%c)*(b%c))%c 
int main()
{
	int n;
	scanf("%d", &n);
	int i;
	int sum = 1;
	for(i = 1; i <= n; i++)
	{
		sum = ((sum % 1000000007) * (i % 1000000007));
	}
	printf("%d", sum % 1000000007);
	return 0;
}
