/*
输入
----
第一行包含一个整数N。(1 <= N <= 100)
以下N行每行包含一个整数Ai。(1 <= Ai <= 100)  

输出
----
一个整数代表答案。如果凑不出的数目有无限多个，输出INF。

例如，
输入：
2  
4  
5   

程序应该输出：
6  

再例如，
输入：
2  
4  
6    

程序应该输出：
INF

*/

#include<stdio.h>

int main()
{
	int n;
	int A[11000];
	int B[11000];
	int i;
	int j;
	int sum = 0;
	int min = 100;
	int ch = 0;
	
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
		min = min > A[i] ? A[i] : min;
		if(A[i] % 2 == 1)
		{
			ch = 1;
		}
	}
	if(ch == 0)
	{
		printf("INF");
		return 0;
	}
	A[n] = 0;
	for(i = 1; i < min; i++)
	{
		B[i] = 0;
		sum ++;
//		printf("%d\n", i);
	}
	for(i = 0; i < n; i++)
	{
		B[A[i]] = 1;
	}
	for(i = min + 1; i < 11000; i++)
	{
		int flag = 0;
		for(j = 0; j <= n; j++)
		{
			if(i - A[j] > 0 && B[i - A[j]] == 1)
			{
				flag = 1;
			}
		}
		if(flag == 0)
		{
			B[i] = 0;
			sum++;
//			printf("%d\n", i);
		}
		else
		{
			B[i] = 1;
		}
	}
	printf("%d", sum);
	return 0; 
 } 
