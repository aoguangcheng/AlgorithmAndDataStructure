/*
99.Ϳɫ���� (15��)
Cʱ�����ƣ�1 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
 ���ų�һ�еģ�������ú�(Red)����(Pink)����(Green)��ɫͿÿ�����ӣ�ÿ��Ϳһɫ��
 Ҫ���κ����ڵķ�����ͬɫ������β����Ҳ��ͬɫ����ȫ��������Ҫ���Ϳ����
��������
����������n

�������
������

��������
5

�������
30
*/ 
#include<iostream> 
using namespace std;

int sum = 0;

void fun1(int n, int A[], int i, int x, int flag)
{
	A[i] = x;
	if(i == n)
	{
		if(flag != x)
		{
			sum++;
		}
		return;
	}
	i++;
	if(A[i - 1] == 1)
	{
		fun1(n, A, i, 2, flag);
		fun1(n, A, i, 3, flag);
	}
	if(A[i - 1] == 2)
	{
		fun1(n, A, i, 1, flag);
		fun1(n, A, i, 3, flag);
	}
	if(A[i - 1] == 3)
	{
		fun1(n, A, i, 1, flag);
		fun1(n, A, i, 2, flag);
	}
}

int main()
{
	int n;
	cin>>n;
	int A[100];
	fun1(n, A, 1, 1, 1);
	fun1(n, A, 1, 2, 2);
	fun1(n, A, 1, 3, 3);
	cout<<sum;
	return 0;
}
