/*
84.寻找最大数 (15分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
请在整数 n 中删除m个数字, 使得余下的数字按原次序组成的新数最大，
比如当n=92081346718538，m=10时，则新的最大数是9888
输入描述
第一行输入一个正整数T，表示有T组测试数据每组测试数据占一行，每行有两个数n,m（n可能是一个很大的整数，但其位数不超
过100位，并且保证数据首位非0，m小于整数n的位数）

输出描述
每组测试数据的输出占一行，输出剩余的数字按原次序组成的最大新数

输入样例
2
92081346718538 10
1008908 5

输出样例
9888
98
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char S[100];
		int m;
		int i;
		int j;
		
		cin>>S;
		cin>>m;
		m = strlen(S) - m;
		int flag = 0;
		for(i = 0, j = 0; i < m; i++)
		{	
			int k;
			char max = S[flag];
			for(k = flag + 1; k <= strlen(S) - m + j; k++)
			{
				if(max < S[k])
				{
					max = S[k];
					flag = k;
				}
			}
			flag++;
			cout<<max;
			j++;
		}
		cout<<endl;
	}
	return 0;
}
