/*
117.大数相乘 (20分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
 一个整型变量只能用来存贮较小的n!的值，当 n 较大时，可将阶乘值中的每一个数字放在一个一维数组的一个元素中。使用这方法，打印n!的值；

输入描述
整数n

输出描述
n!的值

输入样例
18

输出样例
6402373705728000
*/ 

#include<stdio.h>
#define N 50 
int main()
{
	int n;
	scanf("%d", &n);
	int A[N] = {0};
	A[N - 1] = 1;
	for(int i = 1; i <= n; i++)
	{	
		int sum = 0;
		for(int j = N - 1; j >=0; j--)
		{
			A[j] = A[j] * i + sum;
			sum = A[j] / 10;
			A[j] = A[j] % 10;
		}
	}
	int i = 0;
	while(A[i] == 0)
	{
		i++;
	}
	for(i; i < N; i++)
	{
		printf("%d", A[i]);
	}
	return 0;
 } 
