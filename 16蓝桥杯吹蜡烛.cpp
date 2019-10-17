#include<stdio.h>

int main()
{
	for(int i = 1; i < 100; i++)
	{
		int sum = 0;
		int j = i;
		int k = i;
		while(sum <237)
		{
			sum += j;
			if(sum == 236)
			{
				printf("%d", k);
			}
			j++;
		}
	}
	return 0;
}