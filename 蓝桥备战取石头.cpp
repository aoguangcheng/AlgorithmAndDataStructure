/*
67.取石头 (15分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
有一堆石子，A，B两人轮流从中取出石子，每次取出的石子数目只能为1，3，7或8，最后一枚石子谁取到就是输方。
A,B两人都足够聪明，不会做出错误的判断。现给出一定数目的石子，A先取石子，计算A最终是输是赢，赢用1表示，
输用0表示.
输入描述
第一行为一个整数n(0< n <=100),表示玩n局，接下来n行每行有一个整数，表示对应的局提供的石子数（不大于
10000），

输出描述
编程输出A对应的n局是赢是输，赢输出1，输输出0.

输入样例
3
1
3
10

输出样例
0
0
1

*/
#include<stdio.h>

void fun()
{
	int n;
	int A[10000];
	scanf("%d", &n);
	A[1] = 0;
	A[2] = 1;
	A[3] = 0;
	A[4] = 1;
	A[5] = 0;
	A[6] = 1;
	A[7] = 0;
	A[8] = 1;
	int i = 9;
	for(i; i <= n; i++)
	{
		A[i] = !(A[i - 1] && A[i - 3] && A[i - 7] && A[i - 8]);
	}
	printf("%d", A[n]);
}

int main()
{
	int n;
	int i;
	
	scanf("%d", &n);
	i = 0;
	while(i < n)
	{
		fun();
		printf("\n");
		i ++;
	}
} 
/*
#include<stdio.h>

void fun1()
{
	int n;
	int i = 0;
	int j = 1;
	scanf("%d", &n);
	if(n % 2 == 0)
	{
		printf("%d", j);
	}
	else
	{
		printf("%d", i);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	n--;
	while(n--)
	{
		fun1();
		printf("\n");
	}
	fun1();
	return 0;
}
#include<stdio.h>
int fun1(int n)
{
	int i;
	int j;
	int k;
	int l;
	int flag = 0;
	for(i = 0; i <= n; i++)
	{
		for(j = 0; i <= n / 3; j++)
		{
			for(k = 0; k <= n / 7; k++)
			{
				for(l = 0; l <= n / 8; l++)
				{
					if(i + j * 3 + k * 7 + l * 8 == n)
					{
						if((i + j + k + l) % 2 == 0)
						{
							flag = 1;
						}
					}
				}
			}
		}
	}
	return flag;
}

int main()
{
	int n;
	scanf("%d", &n);
	int A[20];
	int i = 1;
	while(i <= n)
	{
		scanf("%d", &A[i]);
		i++;
	}
	i = 1;
	while(i < n)
	{
		printf("%d\n", fun1(A[i]));
		i++;
	}
	printf("%d", fun1(A[i]));
	return 0;
	
}
*/
