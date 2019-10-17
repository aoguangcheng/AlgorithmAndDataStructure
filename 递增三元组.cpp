/*
���⣺������Ԫ��

����������������

A = [A1, A2, �� AN],

B = [B1, B2, �� BN],

C = [C1, C2, �� CN]��

����ͳ���ж��ٸ���Ԫ��(i, j, k) ���㣺

1. 1 <= i, j, k <= N
2. Ai < Bj < Ck

�������ʽ�� 
��һ�а���һ������N��
�ڶ��а���N������A1, A2, ... AN��
�����а���N������B1, B2, ... BN��
�����а���N������C1, C2, ... CN��

����30%�����ݣ�1 <= N <= 100  
����60%�����ݣ�1 <= N <= 1000 
����100%�����ݣ�1 <= N <= 100000 0 <= Ai, Bi, Ci <= 100000 

�������ʽ��
һ��������ʾ��

���������롿
3
1 1 1
2 2 2
3 3 3

�����������
27 

*/

#include<stdio.h>
#define N 100


void sort(int n, int *A)
{
	int i;
	int j;
	for(i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n - i -1; j++)
		{
			if(A[j] > A[j + 1])
			{
				int temp;
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}
}

int searchA(int n, int flag, int A[])
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(A[i] >= flag)
			break;
	}
	return i;
}

int searchC(int n, int flag, int A[])
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(A[i] > flag)
			break;
	}
	return (n - i);
}

int main()
{
	int n;
	scanf("%d\n", &n);
	int A[N];
	int B[N];
	int C[N];
	int i;
	int sum = 0;

	for(i = 0; i < n; i++)
	{
		scanf("%d" , &A[i]);
	}
	for(i = 0; i < n; i++)
	{
		scanf("%d", &B[i]);
	}
	for(i = 0; i < n; i++)
	{
		scanf("%d", &C[i]);
	}
	sort(n, A);
	sort(n, C);
	for(i = 0; i < n; i++)
	{
		sum = sum + searchA(n, B[i], A) * searchC(n, B[i], C);
	}
	printf("%d", sum);
	return 0;
}