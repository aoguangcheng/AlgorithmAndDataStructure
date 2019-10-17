/*
99.涂色问题 (15分)
C时间限制：1 毫秒 |  C内存限制：3000 Kb
题目内容：
 有排成一行的ｎ个方格，用红(Red)、粉(Pink)、绿(Green)三色涂每个格子，每格涂一色，
 要求任何相邻的方格不能同色，且首尾两格也不同色．求全部的满足要求的涂法。
输入描述
输入正整数n

输出描述
输出结果

输入样例
5

输出样例
30
*/ 
#include<iostream> 
using namespace std;

int sum = 0;

void fun1(int n, int A[], int i, int x, int flag)
{
	A[i] = x;
	if(i == n)
	{
		if(flag != x)
		{
			sum++;
		}
		return;
	}
	i++;
	if(A[i - 1] == 1)
	{
		fun1(n, A, i, 2, flag);
		fun1(n, A, i, 3, flag);
	}
	if(A[i - 1] == 2)
	{
		fun1(n, A, i, 1, flag);
		fun1(n, A, i, 3, flag);
	}
	if(A[i - 1] == 3)
	{
		fun1(n, A, i, 1, flag);
		fun1(n, A, i, 2, flag);
	}
}

int main()
{
	int n;
	cin>>n;
	int A[100];
	fun1(n, A, 1, 1, 1);
	fun1(n, A, 1, 2, 2);
	fun1(n, A, 1, 3, 3);
	cout<<sum;
	return 0;
}
