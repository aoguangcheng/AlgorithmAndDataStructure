/*
1233321是一个非常特殊的数字，他从左边网友和从右往左毒是一样的，
输入一个正整数n，编程求这样的五位数和六位十进制数，满足各位数之和等于n，
输入格式：
一个正整数n
输出格式：输出满足条件的整数，每个整数占有一行
样例输入：
52；
样例输出：
899998
989989
998899 
*/

#include<stdio.h>

int main()
{
	int n;
	int i;
	int j;
	int k;
	
	scanf("%d", &n);
	for(i = 1; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			for(k = 0; k < 10; k++)
			{
				if((i + j + k) * 2 ==  n)
				{
					printf("%d\n", i + j * 10 + k * 100 + k * 1000 + j *10000 + i * 100000);
				}
				if(i * 2 + j * 2 + k == n)
				{
					printf("%d\n", i + j * 10 + k * 100 + j * 1000 + i * 10000);
				}
			}
		}
	}
	return 0;
}
