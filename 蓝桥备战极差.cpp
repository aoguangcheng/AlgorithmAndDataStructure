/*
125.���� (15��)
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
 �ںڰ���д��N����������ɵ�һ�����У��������²�����ÿ�β�ȥ���е�������a��b��
Ȼ���������м���һ����a*b��1�������ȥֱ���ڰ���ʣ��һ�����������а����ֲ�����ʽ
���õ������У�����Ϊmax����С��Ϊmin��������еļ����ΪM��max��min.�����̣�
���ڸ��������У����㼫��.
��������
�������������Լ�.ÿ�����Լ��ĵ�һ��N��ʾ���������г��ȣ�0����N����50000�������ڶ�����N��������.��NΪ0ʱ����.

�������
ÿ�����һ��.

��������
3
3 5 7

�������
4
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int x[50001],y[50001];
 
bool cmp(int a,int b)
{
	return a>b;
}
 
int m_min(int n)
{
	for(int i=1;i<n;i++)
	{
		x[i]=x[i]*x[i-1]+1;
		x[i-1]=0;
		sort(x,x+n);
	}
	return x[n-1];
}
 
int m_max(int n)
{
	for(int i=1;i<n;i++)
	{
		y[i]=y[i]*y[i-1]+1;
		//cout<<y[i]<<"sss"<<endl;
		y[i-1]=99999;
		sort(y,y+n,cmp);
	}
	return y[n-1];
}
 
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a,b,c,sum;
		int m=n;
		memset(x,0,sizeof(x));
		for(int i=0;i<n;i++)
		{
			cin>>x[i];
			y[i]=x[i];
		}
		sort(x,x+n);
		int min = m_min(n);
		sort(y,y+n,cmp);
		int max = m_max(n);
		cout<<min - max<<endl;
	}
	return 0;
}
