/*
68.最大k乘积问题 (15分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
设I是一个n位十进制整数.如果将I划分为k段,则可得到k个整数.这k个整数的乘积称为I的一个k乘积.试设计一个算法,对于给定
的I和k ,求出I的最大k乘积.
Input
输入的第1行中有2个正整数n和k.正整数n是序列的长度;正整数k是分割的段数.接下来的一行中是一个n位十进制整数.（n<=10）
Output
输出计算结果，第1行中的数是计算出的最大k乘积.
n位十进制整数.（n<=10）
输入描述
输入的第1行中有2个正整数n和k.正整数n是序列的长度;正整数k是分割的段数.接下来的一行中是一个

输出描述
输出计算结果，第1行中的数是计算出的最大k乘积.

输入样例
2 1
15

输出样例
15


#include<iostream>  
using namespace std;  
#define N 20  
int m[N][N];  
char num[N];  
  
int atoi(char arr[],int i,int j)  
{  
	int sum=0;  
	while(i<=j)  
	{  
        sum = sum*10+arr[i]-'0';  //此处本来用了函数pow，然后wa了，一直找不到错在何处，  
		i++;		//后来问师兄，才发现原来pow(double,int)   
	} 			//的参数double会使结果又偏差，改掉后就ac了  
    return sum;  
}  
  
int main()  
{  
	int n,k,i,j,l,max,flag;  
	while(cin>>n>>k)  
	{  
		for(i=1;i<=n;i++)  
			cin>>num[i];  
		m[1][1]=num[1]-'0';  
		for(i=2;i<=n;i++)  
			m[i][1]=m[i-1][1]*10+(num[i]-'0'); //初始化第一列  
		for(j=2;j<=k;j++)//按列进行初始化  
		{  
			max=-1;  
			for(i=1;i<=n;i++)  
			{  
				if(j>i)  
					m[i][j]=0;  
				else  
				{  
					for(l=j-1;l<=i-1;l++)  
					{  
						flag=m[l][j-1]*atoi(num,l+1,i);  
						if(flag>max)  
						max=flag;  
					}  
					m[i][j]=max;  
				}  
			}  
		}  
		cout<<m[n][k]<<endl;  
	}  
	return 0;  
}
*/

#include<iostream>
#include<stdio.h>
using namespace std;

int fun1(char A[], int i, int j)//返回数组A[]中从 i 到 j 所表示的数值大小，int， 其中 i <= j 
{
	int sum;
	sum = A[i] - 48;
	i++;
	while(i <= j)
	{
		sum = sum * 10 + A[i] - 48;
		i++;
	}
	return sum;
}

int main()
{
	int n;
	int k;
	int i;
	int j;
	char A[10];
	int B[11][11] = {0};
	
	cin>>n>>k;
	for(i = 1; i <= n; i++)
	{
		cin>>A[i];
	}
	for(i = 1; i <= n; i++)
	{
		B[i][1] = fun1(A, 1, i);
	 } 
	 
	for(j = 2; j <= k; j++)
	{
		for(i = 2; i <= n; i++)
		{
			if(j > i)
			{
				B[i][j] = 0;
			}
			else
			{
				int k = 1;
				int flag;
				int max = 0;
				for(k; k < i; k++)
				{
					flag = B[k][j - 1] * (A[i] - 48);
					if(max < flag)
					{
						max = flag;
					}
				}
			}
		}
	}
/*	 
	 for(i = 1; i <= n; i++)
	 {
	 	for(j = 1; j <= k; j++)
	 	{
	 		cout<<B[i][j]<<" ";
		 }
		 cout<<endl;
	 }
*/	 
	cout<<B[n][k];
	return 0;
}

