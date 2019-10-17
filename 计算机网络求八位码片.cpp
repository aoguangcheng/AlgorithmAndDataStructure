/*
先求出所有的八位二进制，再写出判断函数S*T=0，最后暴力。
*/

#include<stdio.h>

void fun1(int A[128][8])//求所有八位的二进制
{
	int B[8];
	int i = 0;
	for(; i < 128; i++)
	{
		int j = i;
		int k = 0;
		for(; j != 0; k++)
		{
			B[k] = j % 2;
			j = (j - B[k]) / 2;
		}
		k--;
		for(int h = 7; k >= 0; h--, k--)
		{
			A[i][h] = B[k];
		}
	}
}

void fun2(int A[128][8])
{
	for(int i = 0; i < 128; i++)
	{
		for(int j = 0; j < 8; j ++)
		{
			if(A[i][j] == 0)
			{
				A[i][j] = -1;
			}
			printf("%3d ", A[i][j]);
		}
		printf("\n");
	}
}

void fun3(int A[128][8])
{
	
	for(int i = 0; i < 128; i++)
	{
		int B[128];
		int m = 1;
		B[0] = i;
		for(int j = 0; j < 128; j++)
		{
			int sum = 0;
			for(int k = 0; k < 8; k++)
			{
				sum += A[i][k] * A[j][k];
			}
			if(sum == 0)
			{
				B[m] = j;
				m++;
			}
		}
		for(int l = 0; l < m; l++)
		{
			printf("%d ", B[l]);
		}
		printf("\n");
	}
}

int main()
{
	int A[128][8] = {0};
	fun1(A);
	fun2(A);
	fun3(A);
	return 0;
}