/*
85.矩形嵌套 (15分)
C时间限制：3 毫秒 |  C内存限制：3000 Kb
题目内容：
有n个矩形，每个矩形可以用a,b来描述，表示长和宽。矩形X(a,b)可以嵌套在矩形Y(c,d)中当且仅当a<c,b<d或者b<c,a<d（相
当于旋转X90度）。例如（1,5）可以嵌套在（6,2）内，但不能嵌套在（3,4）中。你的任务是选出尽可能多的矩形排成一行，使
得除最后一个外，每一个矩形都可以嵌套在下一个矩形内。
输入描述
第一行是一个正正数N(0<N<10)，表示测试数据组数，每组测试数据的第一行是一个正正数n，表示该组测试数据中含有矩形的个
数(n<=1000)随后的n行，每行有两个数a,b(0<a,b<100)，表示矩形的长和宽

输出描述
每组测试数据都输出一个数，表示最多符合条件的矩形数目，每组输出占一行

输入样例
1
10
1 2
2 4
5 8
6 10
7 9
3 1
5 8
12 10
9 7
2 2

输出样例
5
*/ 
#include<string.h> 
#include<iostream>
#include<algorithm>
using namespace std;

struct ans
{
	int x;
	int y;
};

bool cmp(ans a, ans b)
{
	if(a.x <= b.x)
	{
		return 1;
	}
	else if(a.x == b.x && a.y < b.y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool max(ans a, ans b)
{
	if(a.x > b.x && a.y > b.y)
	{
		return 1;
	} 
	else
	{
		return 0;
	}
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		int dp[1000];
		ans a[1000];
		int i;
		int j;
		
		for(i = 0; i < n; i++)
		{
			cin>>a[i].x>>a[i].y;
			if(a[i].x > a[i].y)
			{
				int temp = a[i].x;
				a[i].x = a[i].y;
				a[i].y = temp;
			}
		}//完成数据输入
		
		sort(a, a + n, cmp);//进行一次排序
		memset(dp, 0, sizeof(dp));
		
		dp[0] = 1;
		for(i = 1; i < n; i++)
		{
			int k = 0;
			for(j = 0; j < i; j++)
			{
				if(max(a[i], a[j])&& k < dp[j])
				{
					k = dp[j];
				}
			}
			dp[i] = k + 1;	
		} 
		int Max = 0;
		for(i = 0; i < n; i++)
		{
			if(Max < dp[i])
			{
				Max = dp[i];
			}
		}
		cout<<Max<<endl;
	}
}

/*
#include <stdio.h>
#include <string.h>
#include <algorithm>
 
using namespace std;
 
struct ans{
	int x;
	int y;
};
struct ans a[1001];
int dp[1001];
 
bool cmp(struct ans a,struct ans b)
{
	if(a.x <= b.x) return 1;
	else if(a.x == b.x && a.y < b.y)
	return 1;
	else return 0;
}
 
bool max(struct ans m,struct ans n)
{
	if(m.x < n.x && m.y < n.y) return 1;
	else return 0;
}
 
int main()
{
	int n,m,i,j,k;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		for(i = 0; i < m; i++)
		{
			scanf("%d%d",&a[i].x,&a[i].y);
			if(a[i].x > a[i].y)
			{
				int tmp = a[i].x;
				a[i].x = a[i].y;
				a[i].y = tmp;
			}
		}
		sort(a,a+m,cmp);
		memset(dp,0,sizeof(dp));
		for(i = 1; i < m; i++)
		{
			for(j = 0; j <= i; j++)
			{
				if(max(a[j],a[i])&&dp[i] < dp[j] + 1)
				{
					dp[i] = dp[j] + 1;
				}
			}
		}
		int max = dp[0];
		for(i = 0; i < m; i++)
		{
			if(max < dp[i])
			max = dp[i];
		}
		printf("%d\n",max+1);
	}
	return 0;
}

*/ 
