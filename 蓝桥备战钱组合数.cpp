/*
87.钱组合数 (15分)
C时间限制：3 毫秒 |  C内存限制：3000 Kb
题目内容：
给你足够多的1，2，5面值的钱币，输入一个钱数n，设计一个程序使能够计算出所有的组合！
输入描述
钱数N

输出描述
所有的组合数的个数

输入样例
20

输出样例
29

*/ 
/*
#include<stdio.h>

int main()
{
	int A[100];
	A[0] = 0;
	A[1] = 1;
	A[2] = 2;
	A[3] = 2;
	A[4] = 3;
	A[5] = 4;
	int n;
	
	scanf("%d", &n);
	if(n <= 5)
	{
		printf("%d", A[n]);
		return 0;
	}
	int i = 6;
	while(i <= n)
	{
		A[i] = A[i - 1] + A[i - 2] + A[i - 5];
//		printf("%d\n", A[i]);
		i++;
	}
	printf("%d", A[n]);
	return 0;
}
*/
#include<stdio.h>

int main()
{
	int i;
	int j;
	int k;
	
	int n;
	int sum = 0;
	scanf("%d", &n);
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= n / 2; j++)
		{
			for(k = 0; k <= n / 5; k++)
			{
				if(i + j * 2 + k * 5 == n)
				{
					sum ++;
				}
			}
		}
	}
	printf("%d", sum);
	return 0;
}
