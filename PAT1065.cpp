/*
1065 单身狗 （25 point(s)）

“单身狗”是中文对于单身人士的一种爱称。本题请你从上万人的大型派对中找出落单的客人，以便给予特殊关爱。
输入格式：

输入第一行给出一个正整数 N（≤ 50 000），是已知夫妻/伴侣的对数；随后 N 行，每行给出一对夫妻/伴侣——为方便起见，每人对应一个 ID 号，为 5 位数字（从 00000 到 99999），ID 间以空格分隔；之后给出一个正整数 M（≤ 10 000），为参加派对的总人数；随后一行给出这 M 位客人的 ID，以空格分隔。题目保证无人重婚或脚踩两条船。
输出格式：

首先第一行输出落单客人的总人数；随后第二行按 ID 递增顺序列出落单的客人。ID 间用 1 个空格分隔，行的首尾不得有多余空格。
输入样例：

3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
输出样例：

5
10000 23333 44444 55555 88888
*/

#include<stdio.h>
#include<string.h>
#define MAX 5000
int fun1(char S[])
{
	int i = strlen(S) - 1;
	int a = 1;
	int sum = 0;
	while(i >= 0)
	{
		sum = sum + (S[i] - 48) * a;
		a = a * 10;
		i--;
	}
	return sum;
}
int main()
{
	char S[5];
	int n;
	int A[MAX];
	int B[MAX];
	int C[MAX];
	int i;
	int m;
	int j;
	int k = 1;;
	scanf("%d", &n);
	for(i = 1; i <= 2 * n; i++)
	{
		scanf("%s", &S);
		A[i] = fun1(S);
	}
	scanf("%d", &m);
	for(i = 1; i <= m; i++)
	{
		scanf("%s", &S);
		B[i] = fun1(S);
	}
//	for(i  = 1; i <= 2 * n; i++)
//		printf("%d ", A[i]);

	for(i = 1;i <= m; i++)
	{
		for(j = 1;j <= 2 * n; j++)
		{
			if(B[i] == A[j])
			{
				if(j % 2 == 0)
				{
					for(k = 1; k <= m; k++)
					{
						if(A[j - 1] == B[k])
						{
							B[k] = 0;
						    B[i] = 0;
						}
					}
				}
				else
				{
					for(k = 1; k <= m; k++)
					{
						if(A[j + 1] == B[k])
						{
							B[k] = 0;
						    B[i] = 0;
						}
					}
				}
			}
		}
	}
	k = 1;
	for(i = 1; i <= m; i++)
	{
		if(B[i] != 0)
		{
			C[k] = B[i];
			k++;
		}
	}

	for(i = 1; i < k - 1; i++)
	{
		for(j = 1; j <= k - i - 1; j++)
		{
			if(C[j] > C[j + 1])
			{
				int temp = C[j];
				C[j] = C[j + 1];
				C[j + 1] = temp;
			}
		}
	}
	printf("%d\n", k - 1);
	for(i = 1; i < k - 1; i++)
		printf("%05d ", C[i]);
	printf("%05d", C[i]);
	return 0;
}