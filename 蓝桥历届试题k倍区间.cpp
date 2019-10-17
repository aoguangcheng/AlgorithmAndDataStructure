/*
样例输入
5 2
1
2
3
4
5
样例输出
6
*/
#include<stdio.h>

int main()
{
	int N;
	int k;
	int i;
	int j;
	int A[100000];
	int count = 0;
	
	scanf("%d %d", &N, &k);
	for(i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}
	
	for(i = 0; i < N; i++)
	{
		int sum = 0;
		for(j = i; j < N; j ++)
		{
			sum += A[j];
			if(sum % k == 0)
			{
				count ++;
			}
		}
	}
	printf("%ld", count);
	return 0;
 } 
