/*
给定N个不同的整数，要求对着N个整数按如下规则排序并输出：
规则一：所有的偶数排在奇数前面
规则二：在规则一的前提下按照从大到小的顺序排序
输入样例：
5
1 2 3 4 5
输出样例：
4 2 5 3 1

输入样例：
10 
1 2 3 4 5 6 7 8 9 10
输出样例：
10 8 6 4 2 9 7 5 3 1
*/

#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 20

void input(int n, int A[])
{
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
}

void output(int n, int H[])
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", H[i]);
	}
}

bool cmp(int a, int b)
{
	if(a > b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void apart(int n, int A[])
{
	int p = 0;
	int q = 0;
	int B[N];
	int C[N];
	for(int i = 0; i < n; i++)
	{
		if(A[i] % 2 == 0)
		{
			B[p] = A[i];
			p++;
		}
		else
		{
			C[q] = A[i];
			q++;
		}
	}

	sort(B, B + p, cmp);
	output(p, B);
	sort(C, C + q, cmp);
	output(q, C);
}

int main()
{
	int A[N];
	int n;
	scanf("%d", &n);
	input(n, A);
	apart(n, A);
	return 0;
}