/*
1526.2019春校赛--求索溪边的树枝 (10分)
C时间限制：3000 毫秒 |  C内存限制：32768 Kb
题目内容：
求索溪边散落一些树枝。 给你n根树枝，这些树枝能拼接出m根长度一样的大树枝，求能拼接的最小长度。
输入描述
每组输入包含2行。
第一行为树枝数量n(n <= 45)。
第二行包含由空格分隔的每一根树枝的长度。
n输入为0时表示结束。

输出描述
每组输出最小的拼接长度。

输入样例
4
1 2 3 4
9
15 4 3 1 2 8 11 8 8
0

*/

#include<iostream>
using namespace std;

void fun3(int B, int data, int j, int count)
{
}

void fun2(int A[], int B[], int i, int count) //把A[i] 插进数组B中，数组B有count个数据 
{
	int j;
	for(j = 0; j <= count; j++)
	{
		fun3(B, A[i], j, count);//把A[i]插进数组B下标为j的位置 
	} 
}

void fun1()
{
	int n;
	int A[45];
	int B[45];
	int i;
	int count;
	
	cin>>n;
	for(i = 0; i < n; i++)
	{
		cin>>A[i];
	}
	for(i = 0; i < n; i++) 
	{
		fun2(A, B, i, count);
	}
}

int main()
{
	int t;
	cin>>t;
	while(t != 0)
	{
		fun1();
		cin>>t;
	}
	return 0;
}
