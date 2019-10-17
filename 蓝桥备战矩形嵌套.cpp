/*
85.����Ƕ�� (15��)
Cʱ�����ƣ�3 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
��n�����Σ�ÿ�����ο�����a,b����������ʾ���Ϳ�����X(a,b)����Ƕ���ھ���Y(c,d)�е��ҽ���a<c,b<d����b<c,a<d����
������תX90�ȣ������磨1,5������Ƕ���ڣ�6,2���ڣ�������Ƕ���ڣ�3,4���С����������ѡ�������ܶ�ľ����ų�һ�У�ʹ
�ó����һ���⣬ÿһ�����ζ�����Ƕ������һ�������ڡ�
��������
��һ����һ��������N(0<N<10)����ʾ��������������ÿ��������ݵĵ�һ����һ��������n����ʾ������������к��о��εĸ�
��(n<=1000)����n�У�ÿ����������a,b(0<a,b<100)����ʾ���εĳ��Ϳ�

�������
ÿ��������ݶ����һ��������ʾ�����������ľ�����Ŀ��ÿ�����ռһ��

��������
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

�������
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
		}//�����������
		
		sort(a, a + n, cmp);//����һ������
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
