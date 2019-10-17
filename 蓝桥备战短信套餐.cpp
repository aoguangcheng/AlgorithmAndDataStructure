/*
95.短信套餐 (10分)
C时间限制：1 毫秒 |  C内存限制：65535 Kb
题目内容：
 某通信公司为推广手机短信，提出了短信套餐优惠政策。
用户必须选择一种短信套餐，且只能选择一种。每种套餐的形式为：每月交p元，可以发送免费短信f条。如果超过了f条，则超过的部分按每条a元收费。
现在你已经预知下个月需要发送m条短信，现在，这家公司的短信套餐种类太多了，请您编个程序告诉他选择最省钱的短信套餐需要交多少钱。
输入描述
输入有多组数据。每组数据第一行为整数n和m，用一个空格隔开，分别是套餐的种类数和下月短信条数。1<=n<=1000，0<=m<=10000
下一行有一个实数a，表示超过的部分按每条a元收费。（0<a<=2）
以下的n行，每行有实数p和整数f，用一个空格隔开，表示这种短信套餐为p元可以发送短信f条。（0<=p<=100,1<=f<=10000）。

输出描述
对每组输入数据，输出采用最省钱的短信套餐需交的费用。保留小数点后两位数。

输入样例
5 222
0.1
10 120
15 200
20 300
30 500
50 1000

输出样例
17.20

*/
#include<iostream>
#include<malloc.h>
#include<stdio.h>
using namespace std;

int main()
{
	int m;
	int n;
	double price;
	cin>>m>>n>>price;
	double *cost = (double *)malloc(sizeof(double) * m);
	int count = 0;
	int x;
	int y;
	while(m--)
	{
		cin>>x>>y;
		if(n > y)
		{
			double spend;
			spend = x + (n - y) * price;
			cost[count] = spend;
			count++;
		}
	}
	
	double min = 10000;
	int i;
	
	for(i = 0; i < count; i ++)
	{
		if(min > cost[i])
		{
			min = cost[i];
		}
	}
	printf("%.0lf", min);
	return 0;
 } 
