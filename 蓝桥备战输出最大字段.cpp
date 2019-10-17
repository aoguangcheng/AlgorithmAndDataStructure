/*
120.最大子段和 (20分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
 实数序列a[1],a[2],...a[n], 一个子段指一段连续的子序列a[i],a[i+1],...a[j], 其中1<=i<=j<=n. 要求给出具有最
大和的子段。要求算法时间复杂性为o(n)。
输入描述
第一行输入一个整数n,表示原序列共有n个数据；
第二行输入n个实数，用空格隔开。

输出描述
最大和的子段，每个数据也用空格隔开。
（本题的测试数据能保证最大和的那一个子段是唯一的）

输入样例
7
-1 3 -2 4 -1 6 -5

输出样例
3 -2 4 -1 6

*/

#include<iostream>
using namespace std;

int main()
{
	int n;
	int A[30];
	int B[30];
	int C[30];
	int i;
	int j;
	int count;
	
	cin>>n;
	for(i = 0; i < n; i++)
	{
		cin>>A[i];
	}
	if(A[0] > 0)
	{
		B[0] = A[0];
	}
	else
	{
		B[0] = 0;
	}
	for(i = 1, j = 1; i < n; i++, j++)
	{
		if(A[i] > 0)
		{
			B[j] = A[i] + B[j - 1];
		}
		else
		{
			if(B[j - 1] + A[i] > 0)
			{
				B[j] = A[i] + B[j - 1]; 
			}
			else
			{
				B[j] = 0;
			}
		}
	} 
	int max = 0;
	for(i = 0; i < n; i++)
	{
		if(max < B[i])
		{
			max = B[i];
			j = i;
		}
	}
	count = 0;
	while(max - A[j] > 0)
	{
		max = max - A[j];
		C[count] = A[j];
		count++;
		j--;
	}
	C[count] = A[j];
	count++;
	for(i = count - 1; i >= 0; i--)
	{
		cout<<C[i]<<" ";
	}
//	cout<<max;
	return 0;
}
