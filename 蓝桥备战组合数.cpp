/*
122.����� (15��)
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
 �ҳ�n����Ȼ����1,2������n����ȡr��������ϣ����統n=5��r=3ʱ�������Ϊ
1 2 3 
1 2 4
1 2 5
1 3 4
1 3 5
1 4 5
2 3 4
2 3 5
2 4 5
3 4 5
����ֻ�����������ĸ���
��������
��������������n��r

�������
�����n����Ȼ����ȡr������������ĸ���

��������
5 3
20 18

�������
10
190
*/

#include<iostream>
using namespace std;

int main()
{
	int n;
	int r;
	cin>>n>>r;
	r = r > n - r? n - r : r;
	int A[50];
	int B[50];
	int i;
	int j;
	int k;
	for(j = 0, i = n - r + 1; i <= n; i++, j++)
	{
		A[j] = i;
	}
	int count1 = j;
	for(i = 1, j = 0; i <= r; i++, j++)
	{
		B[j] = i;
	}
	int count2 = j;
	for(i = 0; i < count1; i++)
	{
		for(j = 0; j < count2; j++)
		{
			if(B[j] != 0 && A[i] % B[j] == 0)
			{
				A[i] = A[i] / B[j];
				B[j] = 0;
				break;
			}
		}
	}
	int sum = 1;
	for(i = 0; i < count1; i++)
	{
		sum *= A[i];
	}
	for(i = 0; i < count2; i++)
	{
		if(B[i] != 0)
		{
			sum /= B[i];
		}
	}
	cout<<sum;
	return 0;
}
