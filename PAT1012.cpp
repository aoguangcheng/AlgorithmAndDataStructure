/*
A1  = �ܱ� 5 ����������������ż���ĺͣ�
A2  = ���� 5 ������ 1 �����ְ�����˳����н������
A3  = �� 5 ������ 2 �����ֵĸ�����
A4  = �� 5 ������ 3 �����ֵ�ƽ��������ȷ��С����� 1 λ��
A5  = �� 5 ������ 4 ��������������֡�

�������� 1��

13 1 2 3 4 5 6 7 8 9 10 20 16 18
������� 1��

30 11 2 9.7 9
�������� 2��

8 1 2 4 5 6 7 9 16
������� 2��

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