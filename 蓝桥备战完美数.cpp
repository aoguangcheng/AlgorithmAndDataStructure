/*
77.完美数 (15分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
如果有一正整数n，其真因数的总和等于n，则称之为完美数。
例如以下几个数都是完美数：
6=1+2+3
28=1+2+4+7+14
496=1+2+4+8+16+31+62+124+248
求小于n的所有完美数.
 
输入描述
输入一个正整数n

输出描述
输出小于n的完美数，按升序输出，每个数据占一行

输入样例
10

输出样例
6

*/

#include<iostream>
using namespace std;

int main()
{
	int n;
	int i;
	
	cin>>n; 
	for(i = 2; i < n; i++)
	{
		int j;
		int sum = 1;
		for(j = 2; j < i - 1; j ++)
		{
			if(i % j == 0)
			{
				sum = sum + j;
			}
		}
		if(sum == i)
		{
			cout<<i<<endl;
		}	
	} 
	return 0;
}
