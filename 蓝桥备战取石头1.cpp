/*
115.取石头 (10分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
有甲乙两个人玩取石子游戏,共有n个石子(1<=n<=30000)两个人轮流取,甲先取.每次最多取m个(1<=m<=30000)最少取一个,
当轮到谁取的时候没有石子了,谁就赢.比如4个石子,每次最多取3个,那末先取的人(甲)一定赢
(例如，甲拿走3个,乙只能拿走1个,下面轮到甲没有石子了,甲赢了．）
现在要求你写一个程序，输入n(总的石子个数），最多可以取的石子个数m，输出甲（先取的人）是否会赢，会赢的话输出YES,
否则输出LOSE.
我们这里假设甲乙两个人都采取最好的策略，也就是甲乙都非常想赢而且足够聪明．
比如输入11 4　输出"LOSE"
输入描述
整数n m, 空格隔开

输出描述
YES或者LOSE

输入样例
11 4

输出样例
LOSE
*/
#include<iostream>
using namespace std;

bool fun1(int A[], int m, int j)
{
	bool flag = true;
	int i;
	for(i = j - m; i < j - 1; i++)
	{
		if(A[i] == 1)
		{
			flag = false;
		}
	}
	return flag;
}

int main()
{
	int n;
	int m;
	int i;
	int j;
	int A[30000];
	
	cin>>n>>m;
	A[1] = 0;
//	cout<<A[1]<<" ";
	for(i = 2; i <= m + 1; i++)
	{
		A[i] = 1;
//		cout<<A[i]<<" ";
	}
	for(i; i <= n; i++)
	{
		if(fun1(A, m, i) == true)
		{
			A[i] = 1;
		}
	}
//		cout<<A[i]<<" ";
	if(A[n] == 1)
	{
		cout<<"YES";
	 } 
	else
	{
		cout<<"LOSE";
	}
	return 0;
 } 

