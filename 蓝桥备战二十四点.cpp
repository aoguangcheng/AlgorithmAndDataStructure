/*
101.��ʮ�ĵ� (15��)
Cʱ�����ƣ�1 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
 ��������������N������ͨ�� �ӡ������ˡ������㿴�ܷ�õ� ��� 2N��ÿ����ֻ��һ�Ρ�
��������
�����ĸ�������

�������
��ͨ��ĳ�ַ�ʽ�õ�2N�����1�����������0

��������
6 6 6 6

�������
1

*/
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 4;
int flag = 0;

void fun2(int A[])
{
	int i;
	int j;
	int k;
	for(i = 0; i < 4; i++)
	{
		if(flag == 1)
		{
			break;
		}
		for(j = 0; j < 4; j++)
		{
			if(flag == 1)
			{
				break;
			}
			for(k = 0; k < 4; k++)
			{
				double sum = A[0];
				switch(i)
				{
					case 0 : sum = sum + A[1] ; break;
					case 1 : sum = sum - A[1] ; break;
					case 2 : sum = sum * A[1] ; break;
					case 3 : sum = sum / A[1] ; break;
				}
				switch(j)
				{
					case 0 : sum = sum + A[2] ; break;
					case 1 : sum = sum - A[2] ; break;
					case 2 : sum = sum * A[2] ; break;
					case 3 : sum = sum / A[2] ; break;
				}
				switch(k)
				{
					case 0 : sum = sum + A[3] ; break;
					case 1 : sum = sum - A[3] ; break;
					case 2 : sum = sum * A[3] ; break;
					case 3 : sum = sum / A[3] ; break;
				}
				if(sum == 24)
				{
					flag = 1;
					break;
				}
			}
		}
	}
}

void fun1(int A[], int k)
{
	int i;
	int temp;
	if(k == N - 1)
	{
		fun2(A);
	}
	else
	{
		for(i = k; i < N - 1; i ++)
		{
			temp = A[k];
			A[k] = A[i];
			A[i] = temp;
			fun1(A, k + 1);
		}
	}
}

int main()
{
	int A[N];
	int i;
	
	for(i = 0; i < N; i++)
	{
		cin>>A[i];
	}
	sort(A, A + 4);
	fun1(A, 0);
//	fun2(A);
	cout<<flag;
	return 0;
 } 
