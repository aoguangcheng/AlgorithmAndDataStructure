/*
99.Ϳɫ���� (15��)
Cʱ�����ƣ�1 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
 ��n*n�ķ���ֽ���ú�(Red)����(Pink)����(Green)��ɫͿÿ�����ӣ�ÿ��Ϳһɫ��
 Ҫ���κ����ڵķ�����ͬɫ����ȫ��������Ҫ���Ϳ����
��������
����������n

�������
������

��������
2

�������
18
*/ 
//��A[1][1]��ʼ������ά���飬���������Ϊ1,2,3����ζRGB���߽�Ϊ-1 
#include<iostream>
using namespace std;

int sum = 0;

void fun1(int n, int A[100][100], int i, int j, int x)
{
	A[i][j] = x;
	if(i == n && j == n)
	{
		sum++;
		return;
	}
	j++;
	if(j > n)
	{
		i++;
		j = 1;
	}
	if(A[i - 1][j] == -1 || A[i][j - 1] == -1)
	{
		if(A[i - 1][j] == 1 || A[i][j - 1] == 1)
		{
			fun1(n, A, i, j, 2);
			fun1(n, A, i, j, 3);
		}
		if(A[i - 1][j] == 2 || A[i][j - 1] == 2)
		{
			fun1(n, A, i, j, 1);
			fun1(n, A, i, j, 3);
		}
		if(A[i - 1][j] == 3 || A[i][j - 1] == 3)
		{
			fun1(n, A, i, j, 2);
			fun1(n, A, i, j, 1);
		}
	}
	else
	{
		if(A[i - 1][j] == A[i][j - 1])
		{
			if(A[i - 1][j] == 1)
			{
				fun1(n, A, i, j, 2);
				fun1(n, A, i, j, 3);
			}
			if(A[i - 1][j] == 2)
			{
				fun1(n, A, i, j, 1);
				fun1(n, A, i, j, 3);
			}
			if(A[i - 1][j] == 3)
			{
				fun1(n, A, i, j, 1);
				fun1(n, A, i, j, 2);
			}
		}
		else
		{
			if(A[i - 1][j] == 1 && A[i][j - 1] == 2)
			{
				fun1(n, A, i, j, 3);
			}
			if(A[i - 1][j] == 1 && A[i][j - 1] == 3)
			{
				fun1(n, A, i, j, 2);
			}
			if(A[i - 1][j] == 3 && A[i][j - 1] == 2)
			{
				fun1(n, A, i, j, 1);
			}
		////////////////////////
			if(A[i - 1][j] == 2 && A[i][j - 1] == 1)
			{
				fun1(n, A, i, j, 3);
			}
			if(A[i - 1][j] == 3 && A[i][j - 1] == 1)
			{
				fun1(n, A, i, j, 2);
			}
			if(A[i - 1][j] == 2 && A[i][j - 1] == 3)
			{
				fun1(n, A, i, j, 1);
			}
		}
	}
	/*
	if(i != 1)
		{
			if(A[i - 1][j] == 1 && A[i][j] == 2)
		{
			fun1(n, A, i, j + 1, 3);
		}
		if(A[i - 1][j] == 1 && A[i][j] == 3)
		{
			fun1(n, A, i, j + 1, 2);
		}
		if(A[i - 1][j] == 3 && A[i][j] == 2)
		{
			fun1(n, A, i, j + 1, 1);
		}
		////////////////////////
		if(A[i - 1][j] == 2 && A[i][j] == 1)
		{
			fun1(n, A, i, j + 1, 3);
		}
		if(A[i - 1][j] == 3 && A[i][j] == 1)
		{
			fun1(n, A, i, j + 1, 2);
		}
		if(A[i - 1][j] == 2 && A[i][j] == 3)
		{
			fun1(n, A, i, j + 1, 1);
		}
		///////////////////
		if(A[i - 1][j] == 1 && A[i][j] == 1)
		{
			fun1(n, A, i, j + 1, 2);
			fun1(n, A, i, j + 1, 3);
		}
		if(A[i - 1][j] == 3 && A[i][j] == 3)
		{
			fun1(n, A, i, j + 1, 2);
			fun1(n, A, i, j + 1, 1);
		}
		if(A[i - 1][j] == 2 && A[i][j] == 2)
		{
			fun1(n, A, i, j + 1, 1);
			fun1(n, A, i, j + 1, 3);
		}
	}
	else
	{
		if(A[i][j] == 1)
		{
			fun1(n, A, i, j + 1, 2);
			fun1(n, A, i, j + 1, 3);
		}
		if(A[i][j] == 2)
		{
			fun1(n, A, i, j + 1, 1);
			fun1(n, A, i, j + 1, 3);
		}
		if(A[i][j] == 3)
		{
			fun1(n, A, i, j + 1, 2);
			fun1(n, A, i, j + 1, 1);
		}
	}
	*/
}

int main()
{
	int A[100][100];
	int n;
	cin>>n;
	int i;
	int j;
	
	for(i = 0; i <= n + 1; i++)
	{
		A[i][0] = -1;
	}
	for(j = 0; j <= n + 1; j++)
	{
		A[0][j] = -1;
	}
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			A[i][j] = 0;
		}
	}
	fun1(n, A, 1, 1, 1);
	fun1(n, A, 1, 1, 2);
	fun1(n, A, 1, 1, 3);
	cout<<sum;
	return 0;
}
