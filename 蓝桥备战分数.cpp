/*
59.���� (15��)
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
 д��һ�����򣬽���һ����N/D����ʽ����ķ���������NΪ���ӣ�DΪ��ĸ���������С����ʽ��

�����У�0��N��65535��0<D��65535����������С�������ౣ��100λ��
��������
�ֱ�����N D

�������
�������С����ʽ����ѭ������Ҫ����ѭ���������������������磺
1/3= 0.(3)

��������
1 7

�������
0.(142857)
*/

#include<iostream>
using namespace std;

int fun1(int A[], int m, int n)
{
	int i;
	int j;
	int flag = 1;
	
	for(i = m, j = n; i < n; i++, j++)
	{
		if(A[i] != A[j])
		{
			flag = 0;
			return flag;
		}
	}
	return flag;
}

int main()
{
	int n;
	int m;
	int i;
	int j;
	int num1;//��¼�������� 
	int num2;//��¼���� 
	int num3;//��¼�� 
	int count;
	int A[100];
	
	cin>>n>>m;
	num1 = n / m;
	num2 = n - m * num1;
	count = 0;
	cout<<num1<<".";
	while(count < 100 && num2 != 0)
	{
		num2 *= 10;
		num3 = num2 / m;
		A[count] = num3;
		count ++;
		num2 = num2 - num3 * m;
//		cout<<num3; 
	}
	
	for(i = 0; i < 100; i++)
	{
		for(j = i + 1; j < 100; j++)
		{
			if(A[i] == A[j])
			{
				if(fun1(A, i, j) == 1)
				{
					///////////////////
					int k;
					for(k = 0; k < i; k++)
					{
						cout<<A[k];
					}
					cout<<"(";
					for(k = i; k < j; k++)
					{
						cout<<A[k];
					}
					cout<<")";
					return 0;
				}
			}
		}
	}
	if(i == 100)
	{
		for(j = 0; j < 100; j++)
		{
			cout<<A[j];
		}
	}
	return 0;
}
