#include <stdio.h>
#include<math.h>
int main()
{
	int sum = 0;
	int input = 1;
	int result;
	for(int i = 1; i <= input; i++)
	{
		int j = i;
		while(j)
		{
			result=j%10;
			j/=10;
			if(result == 9)
			{
				printf("%d\n", i);
				sum ++;
				break;
			}
		}
//		printf("%d", sum);
	 }
	printf("\n%d\n", sum);
	double a = 2018;
	printf("%lf\n", sqrt(a));
	return 0;
}
