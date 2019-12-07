/*
问题描述
　　给定一个序列 a_1, a_2, ..., a_n。其中 a_1 是最大的数，没有其他数与 a_1 相等。
　　对于从第二个数开始的每个数 a_i，请找到位置在 a_i 之前且比 a_i 大的，位置上距离 a_i 最近的数 a_j。称 i-j 为 a_i 的前向距离。
　　对于给定的序列，请求出所有数的前向距离之和。
输入格式
　　输入的第一行包含一个整数 n，表示序列的长度。
　　第二行包含 n 个正整数，为给定的序列。
输出格式
　　输出一个整数，表示序列中所有数的前向距离之和。
样例输入
8
9 1 3 5 2 7 6 3
样例输出
14
*/

#include <iostream>
#include <malloc.h>
using namespace std;

int fun(int a[], int index)
{
	int j;
	for (j = index - 1; j; j--)
	{
		if (a[index] < a[j])
		{
			break;
		}
	}
	return (index - j);
}

int main()
{
	int length;
	long long count = 0;
	cin >> length;
	int *a = (int *)malloc(sizeof(int) * length);
	for (int i = 0; i < length; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i < length; i++)
	{
		count += fun(a, i);
	}
	cout << count;
	return 0;
}
