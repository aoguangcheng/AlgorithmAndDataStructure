/*
110.Լɪ�� (5��)
Cʱ�����ƣ�1 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
 ��n����Χ��һȦ��˳���źš��ӵ�һ���˿�ʼ��������1��3��������������3��

���˳�Ȧ�ӣ���������µ���ԭ���ڼ��ŵ���λ?
��������
������n

�������
ֱ��������

��������
10

�������
4

*/
//�˳�����Ϊ-1��ѭ������ʱ����-1 
#include<iostream>
using namespace std;

int main()
{
	int A[100] = {0};
	int n;
	int i;
	int j;
	int k;
	int count;
	
	cin>>n;
	count = n;
	k = 1;
	for(i = 0; i <= n; i++)
	{
		if(i == n)
		{
			i = 0;
		}
		if(k > 3)
		{
			k = 1;
		} 
		if(count == 1)
		{
			for(j = 0; j < n; j++)
			{
				if(A[j] != -1)
				{
					cout<<j + 1;
					break;
				}
			}
			break;
		}
		else
		{
			if(A[i] == -1)
			{
				continue;
			}
			if(k == 3)
			{
				A[i] = -1;
				count--;
				k++;
				continue;
			}
			else
			{
				k++;
			} 
		}
	}
	return 0;

}
