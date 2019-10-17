/*
97.寻找第K大值 (15分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
 在一个整数数组中，寻找第k大值所在位置。假设每个数值都不一样。要求算法时间复杂性通常情况下为线性。
输入描述
包括一个数组长度n,一个k, 以及紧接着的n个整数值。整数之间用空格隔开。

输出描述
第k大值所在位置编号。规定数组的第一个位置编号为0.

输入样例
7 3
1 4 3 9 8 7 2

输出样例
5

*/
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	int k;
	int i;
	
	cin>>n>>k;
	int A[100]; 
	for(i = 0; i < n; i++)
	{
		cin>>A[i];
	}
	int B[100];
	for(i = 0; i < n; i++)
	{
		B[i] = A[i];
	}	
	sort(A, A + n);
	int h = A[n - k];
	for(int j = 0; j < n; j++)
	{
		if(B[j] == h)
		{
			cout<<j;
			break;
		}
	}
	return 0;
}
