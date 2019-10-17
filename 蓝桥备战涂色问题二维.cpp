/*
99.涂色问题 (15分)
C时间限制：1 毫秒 |  C内存限制：3000 Kb
题目内容：
 有n*n的方格纸，用红(Red)、粉(Pink)、绿(Green)三色涂每个格子，每格涂一色，
 要求任何相邻的方格不能同色．求全部的满足要求的涂法。
输入描述
输入正整数n

输出描述
输出结果

输入样例
2

输出样例
18
*/ 
//从A[1][1]开始遍历二维数组，遍历过后改为1,2,3，意味RGB，边界为-1 
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
