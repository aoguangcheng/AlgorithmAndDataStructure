/*
110.约瑟夫环 (5分)
C时间限制：1 毫秒 |  C内存限制：3000 Kb
题目内容：
 有n个人围成一圈，顺序排号。从第一个人开始报数（从1到3报数），凡报到3的

人退出圈子，问最后留下的是原来第几号的那位?
输入描述
正整数n

输出描述
直接输出结果

输入样例
10

输出样例
4

*/
//退出后标记为-1，循环遍历时跳过-1 
#include<iostream>
using namespace std;

int main()
{
	int A[100] = {0};
	int n;
	int i;
	int j;
	int k;
	int count;
	
	cin>>n;
	count = n;
	k = 1;
	for(i = 0; i <= n; i++)
	{
		if(i == n)
		{
			i = 0;
		}
		if(k > 3)
		{
			k = 1;
		} 
		if(count == 1)
		{
			for(j = 0; j < n; j++)
			{
				if(A[j] != -1)
				{
					cout<<j + 1;
					break;
				}
			}
			break;
		}
		else
		{
			if(A[i] == -1)
			{
				continue;
			}
			if(k == 3)
			{
				A[i] = -1;
				count--;
				k++;
				continue;
			}
			else
			{
				k++;
			} 
		}
	}
	return 0;

}
