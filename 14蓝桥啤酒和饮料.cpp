#include<stdio.h>

int main()
{
	int m;
	int n;
	
	for(m = 0; m < 500; m++)
	{
		for(n = 1; n < 500; n++)
		{
			if(23 * m + 19 * n == 823)
			{
				printf("%d %d\n", m, n);
			}
		}
	}
	return 0 ;
 } 
