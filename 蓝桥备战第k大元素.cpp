/*
97.Ѱ�ҵ�K��ֵ (15��)
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
 ��һ�����������У�Ѱ�ҵ�k��ֵ����λ�á�����ÿ����ֵ����һ����Ҫ���㷨ʱ�临����ͨ�������Ϊ���ԡ�
��������
����һ�����鳤��n,һ��k, �Լ������ŵ�n������ֵ������֮���ÿո������

�������
��k��ֵ����λ�ñ�š��涨����ĵ�һ��λ�ñ��Ϊ0.

��������
7 3
1 4 3 9 8 7 2

�������
5

*/
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	int k;
	int i;
	
	cin>>n>>k;
	int A[100]; 
	for(i = 0; i < n; i++)
	{
		cin>>A[i];
	}
	int B[100];
	for(i = 0; i < n; i++)
	{
		B[i] = A[i];
	}	
	sort(A, A + n);
	int h = A[n - k];
	for(int j = 0; j < n; j++)
	{
		if(B[j] == h)
		{
			cout<<j;
			break;
		}
	}
	return 0;
}
