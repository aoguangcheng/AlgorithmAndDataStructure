/*
A1  = 能被 5 整除的数字中所有偶数的和；
A2  = 将被 5 除后余 1 的数字按给出顺序进行交错求和
A3  = 被 5 除后余 2 的数字的个数；
A4  = 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
A5  = 被 5 除后余 4 的数字中最大数字。

输入样例 1：

13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例 1：

30 11 2 9.7 9
输入样例 2：

8 1 2 4 5 6 7 9 16
输出样例 2：

N 11 2 N 9
*/
#include<stdio.h>
#define N 1000

void f1(int A[], int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		if(A[i] % 5 == 0 && A[i] % 2 == 0)
			sum = sum + A[i];
	}
	if(sum != 0)
		printf("%d ", sum);
	else
		printf("N ");
}

void f2(int A[], int n)
{
	int A2[N];
	int j = 0;
	for(int i = 0; i < n; i++)
	{
		if(A[i] % 5 == 1)
		{
			A2[j] = A[i];
			j++;
		}
	}
	int sum = 0;
	for(int k = 0; k < j; k++)
	{
		if(k % 2 == 0)
			sum = sum + A2[k];
		else
			sum = sum - A2[k];
	}
	if(j != 0)
		printf("%d ", sum);
	else
		printf("N ");

}

void f3(int A[], int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		if(A[i] % 5 == 2)
			sum = sum + 1;
	}
	if(sum != 0)
		printf("%d ", sum);
	else
		printf("N ");
}

void f4(int A[], int n)
{
	double sum = 0;
	int j = 0;
	for(int i = 0; i < n; i++)
	{
		if(A[i] % 5 == 3)
		{
			sum = sum + A[i];
			j++;
		}
	}
	if(j != 0)
		printf("%.1lf ", sum / j);
	else
		printf("N ");
}

void f5(int A[], int n)
{
	int max = 0;
	for(int i = 0; i < n; i++)
	{
		if(A[i] % 5 == 4 && max < A[i])
			max = A[i];
	}
	if(max != 0)
		printf("%d", max);
	else
		printf("N");
}

int main()
{
	int A[N];
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	f1(A, n);
	f2(A, n);
	f3(A, n);
	f4(A, n);
	f5(A, n);
	return 0;
}