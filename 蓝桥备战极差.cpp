/*
125.极差 (15分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
 在黑板上写了N个正整数组成的一个数列，进行如下操作：每次擦去其中的两个数a和b，
然后在数列中加入一个数a*b＋1，如此下去直至黑板上剩下一个数，在所有按这种操作方式
最后得到的数中，最大的为max，最小的为min，则该数列的极差定义为M＝max－min.请你编程，
对于给定的数列，计算极差.
输入描述
输入包含多个测试集.每个测试集的第一行N表示正整数序列长度（0＜＝N＜＝50000），随后第二行是N个正整数.当N为0时结束.

输出描述
每个结果一行.

输入样例
3
3 5 7

输出样例
4
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int x[50001],y[50001];
 
bool cmp(int a,int b)
{
	return a>b;
}
 
int m_min(int n)
{
	for(int i=1;i<n;i++)
	{
		x[i]=x[i]*x[i-1]+1;
		x[i-1]=0;
		sort(x,x+n);
	}
	return x[n-1];
}
 
int m_max(int n)
{
	for(int i=1;i<n;i++)
	{
		y[i]=y[i]*y[i-1]+1;
		//cout<<y[i]<<"sss"<<endl;
		y[i-1]=99999;
		sort(y,y+n,cmp);
	}
	return y[n-1];
}
 
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a,b,c,sum;
		int m=n;
		memset(x,0,sizeof(x));
		for(int i=0;i<n;i++)
		{
			cin>>x[i];
			y[i]=x[i];
		}
		sort(x,x+n);
		int min = m_min(n);
		sort(y,y+n,cmp);
		int max = m_max(n);
		cout<<min - max<<endl;
	}
	return 0;
}
