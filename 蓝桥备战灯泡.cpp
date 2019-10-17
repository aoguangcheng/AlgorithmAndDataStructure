/*
65.灯泡 (15分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
一百个灯泡排成一排，第一轮将所有灯泡打开；
第二轮每隔一个灯泡关掉一个。即排在偶数的灯泡被关掉，
第三轮每隔两个灯泡，将开着的灯泡关掉，关掉的灯泡打开。
依次类推，第n轮结束的时候，还有几盏灯泡亮着。
输入描述
程序输入n( 0 < n < 101)

输出描述
输出亮的灯数。

输入样例
2

输出样例
50

*/
#include<iostream>
using namespace std;

void fun1(int A[], int n)
{
	int i;
	for(i = 1; i <= 100; i++)
	{
		if(i % n == 0)
		{
			if(A[i] == 1)
			{
				A[i] = 0;
			}
			else
			{
				A[i] = 1;
			}
//			cout<<"进入"<<i<<" "; 
		}
//		cout<<A[i]<<" ";
	}
//	cout<<endl;
}

int main()
{
	int n;
	int i;
	int sum;
	int A[101];
	for(i = 0; i < 101; i++)
	{
		A[i] = 1;
	}
	
	cin>>n;
	if(n == 1)
	{
		cout<<"100";
		return 0;
	}
	for(i = 2; i <= n; i++)
	{
		fun1(A, i);	
	}
	for(sum = 0, i = 1; i <= 100; i++)
	{
		if(A[i] == 1)
		{
			sum++;
		}
	} 
	cout<<sum;
	return 0;
}
