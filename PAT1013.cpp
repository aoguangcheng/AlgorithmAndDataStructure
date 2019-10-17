/*
1013 数素数 （20 point(s)）
输出第M到第N之间所有的素数，M<=N<=10000；
输入在一行中给出 M 和 N，其间以空格分隔。
输出格式：
的所有素数，每 10 个数字占 1 行，其间以空格分隔，但行末不得有多余空格。
输入样例：

5 27
输出样例：

11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/

#include<stdio.h>
int fun1(int n)
{
	int k;
	for(k = 2; k < n; k++)
	{
		if(n % k == 0)
			return 0 ;
	}
	if(k >= n)
		return 1;
}
int main()
{
	int M;
	int N;
	int i = 0;
	int j = 2;

	scanf("%d %d", &M, &N);
	while(i <= N)
	{
		if(fun1(j) == 1)
		{
			i++;
			if(i >= M && i <= N)
			{
				printf("%d", j);
				if(i != N)
				{
					if((i - M + 1) % 10 == 0)
						printf("\n");
				    else
						printf(" ");
				}
			}
		}
		j++;
	}
	return 0;
}