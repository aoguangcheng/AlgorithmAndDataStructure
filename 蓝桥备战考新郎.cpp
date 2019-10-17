/*
100.考新郎 (10分)
C时间限制：1 毫秒 |  C内存限制：3000 Kb
题目内容：
 国庆期间,省城HZ刚刚举行了一场盛大的集体婚礼,为了使婚礼进行的丰富一些,司仪临时想出了有一个有意思的节目,叫做"考新
郎",具体的操作是这样的:首先,给每位新娘打扮得几乎一模一样,并盖上大大的红盖头随机坐成一排;然后,让各位新郎寻找自己的
新娘.每人只准找一个,并且不允许多人找一个.最后,揭开盖头,如果找错了对象就要当众跪搓衣板..
  假设一共有N对新婚夫妇,其中有M个新郎找错了新娘,求发生这种情况一共有多少种可能.
输入描述
N M

输出描述
可能的种数

输入样例
3 2

输出样例
3

#include<iostream>
using namespace std;

long fun2(long n, long m)
{
	long i;
	long sum = 1;
	for(i = 1; i <= m; i++, n--)
	{
		sum *= n;		
	}
	return sum;
}

int main()
{
	long n;
	long m;
	cin>>n>>m;
	cout<<fun2(n, m) / fun2(m, m) * (fun2(m, m) - 1);
	return 0;
}

*/


#include<stdio.h>
int main()
{
	int n,i,m;
	long long a[25],c[25];
	a[0]=1,a[1]=0,a[2]=1;
	c[0]=1,c[1]=1,c[2]=2;
	for(i=3;i<=20;i++)
	{
		a[i]=(i-1)*(a[i-1]+a[i-2]);
		c[i]=c[i-1]*i;
	}
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		printf("%lld\n",c[n]/c[n-m]/c[m]*a[m]);
	}
 }/**/ 
