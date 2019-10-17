/*
����
----
��һ�а���һ������N��(1 <= N <= 100)
����N��ÿ�а���һ������Ai��(1 <= Ai <= 100)  

���
----
һ����������𰸡�����ղ�������Ŀ�����޶�������INF��

���磬
���룺
2  
4  
5   

����Ӧ�������
6  

�����磬
���룺
2  
4  
6    

����Ӧ�������
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
