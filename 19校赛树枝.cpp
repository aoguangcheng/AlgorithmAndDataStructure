/*
1526.2019��У��--����Ϫ�ߵ���֦ (10��)
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�32768 Kb
��Ŀ���ݣ�
����Ϫ��ɢ��һЩ��֦�� ����n����֦����Щ��֦��ƴ�ӳ�m������һ���Ĵ���֦������ƴ�ӵ���С���ȡ�
��������
ÿ���������2�С�
��һ��Ϊ��֦����n(n <= 45)��
�ڶ��а����ɿո�ָ���ÿһ����֦�ĳ��ȡ�
n����Ϊ0ʱ��ʾ������

�������
ÿ�������С��ƴ�ӳ��ȡ�

��������
4
1 2 3 4
9
15 4 3 1 2 8 11 8 8
0

*/

#include<iostream>
using namespace std;

void fun3(int B, int data, int j, int count)
{
}

void fun2(int A[], int B[], int i, int count) //��A[i] �������B�У�����B��count������ 
{
	int j;
	for(j = 0; j <= count; j++)
	{
		fun3(B, A[i], j, count);//��A[i]�������B�±�Ϊj��λ�� 
	} 
}

void fun1()
{
	int n;
	int A[45];
	int B[45];
	int i;
	int count;
	
	cin>>n;
	for(i = 0; i < n; i++)
	{
		cin>>A[i];
	}
	for(i = 0; i < n; i++) 
	{
		fun2(A, B, i, count);
	}
}

int main()
{
	int t;
	cin>>t;
	while(t != 0)
	{
		fun1();
		cin>>t;
	}
	return 0;
}
