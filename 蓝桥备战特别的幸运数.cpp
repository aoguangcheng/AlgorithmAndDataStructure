/*
81.�ر�������� (15��)
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
YF�����������������Ȳ�ϲ��6��Ҳ��ϲ��8����������������4��7�����һ��������ֻ����4��7��������Ϊ���������������������
���ڸ�������������a,b��Ҫ�󷵻�a,b֮����������ĸ���������a,b����
��������
��һ��������Ŀn,��ʾ������n��ab
��2�п�ʼ��ÿ��һ��a b, �ո������

�������
ÿ�����һ��������a,b֮����������ĸ�����

��������
3
11 20
4 7
1 10

�������
0
2
2

*/ 
#include<iostream>
using namespace std;

int A[100];
int count = 0;

int fun2(int n)
{
	int i = 1;
	int j;
	while(n / i != 0)
	{
		j = n / i % 10;
		if(j != 4 && j != 7)
		{
			return 0;
		}
		i *= 10;
	}
	return 1;
}

void fun1()
{
	int a;
	int b;
	cin>>a>>b;
	int sum = 0;
	int i;
	for(i = a; i <= b; i++)
	{
		if(fun2(i) == 1)
		{
			sum ++;
		}
	}
	A[count] = sum;
	count ++;
}

int main()
{
	int t;
	cin>>t;
	while(t > 0)
	{
		fun1();
		t--;
	}
	for(t = 0; t < count; t++)
	{
		cout<<A[t]<<endl;
	}
	return 0;
}

