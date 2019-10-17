/*
104.N皇后 (15分)
C时间限制：1 毫秒 |  C内存限制：3000 Kb
题目内容：
 国际象棋中的皇后可以沿着水平线，垂直线，或者斜线前进，吃掉遇到的所有棋子，如果棋盘上有八个皇后，则这八个皇后如何相安无事的
放置在棋盘上，1970年与1971年， E.W.Dijkstra与N.Wirth曾经用这个问题来讲解程式设计之技巧。
该题要求N皇后的放置结果共有多少种
输入描述
输入一个正整数N（N小于16）

输出描述
输出结果

输入样例
8

输出样例
92
*/

#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;
const int N = 15;
int count = 0;
int q[N] = {0};

int place(int k)
{
	int i = 1;
	while(i < k)
	{
		if(q[i] == q[k] || abs(i - k) == abs(q[i] - q[k]))
		{
			return 0;
		}
		i++;
	}
	return 1;
}

void fun1(int n)
{
	int k = 1;
	q[k] = 0;
	while(1)
	{
		q[k] += 1;
		while(q[k] <= n && !place(k)) 
		{
			q[k] += 1;
		}
		if(q[k] <= n)
		{
			if(k == n)
			{
				count++;
			}
			else
			{
				k++;
				q[k] = 0;
			}
		}
		else
		{
			if(k == 1)
			{
				cout<<count;
				exit(0);
			}
			k--;
		}
	}
}

int main()
{
	int n;
	
	cin>>n;
	fun1(n);
	return 0;
 } 
