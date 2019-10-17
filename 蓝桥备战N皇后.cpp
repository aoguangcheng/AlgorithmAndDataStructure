/*
104.N�ʺ� (15��)
Cʱ�����ƣ�1 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
 ���������еĻʺ��������ˮƽ�ߣ���ֱ�ߣ�����б��ǰ�����Ե��������������ӣ�����������а˸��ʺ�����˸��ʺ�����ల���µ�
�����������ϣ�1970����1971�꣬ E.W.Dijkstra��N.Wirth��������������������ʽ���֮���ɡ�
����Ҫ��N�ʺ�ķ��ý�����ж�����
��������
����һ��������N��NС��16��

�������
������

��������
8

�������
92
*/

#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;
const int N = 15;
int count = 0;
int q[N] = {0};

int place(int k)
{
	int i = 1;
	while(i < k)
	{
		if(q[i] == q[k] || abs(i - k) == abs(q[i] - q[k]))
		{
			return 0;
		}
		i++;
	}
	return 1;
}

void fun1(int n)
{
	int k = 1;
	q[k] = 0;
	while(1)
	{
		q[k] += 1;
		while(q[k] <= n && !place(k)) 
		{
			q[k] += 1;
		}
		if(q[k] <= n)
		{
			if(k == n)
			{
				count++;
			}
			else
			{
				k++;
				q[k] = 0;
			}
		}
		else
		{
			if(k == 1)
			{
				cout<<count;
				exit(0);
			}
			k--;
		}
	}
}

int main()
{
	int n;
	
	cin>>n;
	fun1(n);
	return 0;
 } 
