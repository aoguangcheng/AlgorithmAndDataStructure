/*
101.二十四点 (15分)
C时间限制：1 毫秒 |  C内存限制：3000 Kb
题目内容：
 问题描述：输入N个数，通过 加、减、乘、除运算看能否得到 结果 2N，每个数只用一次。
输入描述
输入四个正整数

输出描述
能通过某种方式得到2N则输出1，不能则输出0

输入样例
6 6 6 6

输出样例
1

*/
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 4;
int flag = 0;

void fun2(int A[])
{
	int i;
	int j;
	int k;
	for(i = 0; i < 4; i++)
	{
		if(flag == 1)
		{
			break;
		}
		for(j = 0; j < 4; j++)
		{
			if(flag == 1)
			{
				break;
			}
			for(k = 0; k < 4; k++)
			{
				double sum = A[0];
				switch(i)
				{
					case 0 : sum = sum + A[1] ; break;
					case 1 : sum = sum - A[1] ; break;
					case 2 : sum = sum * A[1] ; break;
					case 3 : sum = sum / A[1] ; break;
				}
				switch(j)
				{
					case 0 : sum = sum + A[2] ; break;
					case 1 : sum = sum - A[2] ; break;
					case 2 : sum = sum * A[2] ; break;
					case 3 : sum = sum / A[2] ; break;
				}
				switch(k)
				{
					case 0 : sum = sum + A[3] ; break;
					case 1 : sum = sum - A[3] ; break;
					case 2 : sum = sum * A[3] ; break;
					case 3 : sum = sum / A[3] ; break;
				}
				if(sum == 24)
				{
					flag = 1;
					break;
				}
			}
		}
	}
}

void fun1(int A[], int k)
{
	int i;
	int temp;
	if(k == N - 1)
	{
		fun2(A);
	}
	else
	{
		for(i = k; i < N - 1; i ++)
		{
			temp = A[k];
			A[k] = A[i];
			A[i] = temp;
			fun1(A, k + 1);
		}
	}
}

int main()
{
	int A[N];
	int i;
	
	for(i = 0; i < N; i++)
	{
		cin>>A[i];
	}
	sort(A, A + 4);
	fun1(A, 0);
//	fun2(A);
	cout<<flag;
	return 0;
 } 
