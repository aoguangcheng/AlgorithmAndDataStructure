/*
66.������� (15��)
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
����ƽ����ʱ������ϣ���þ������ٵ�������ϳƳ������ܶ��������
���ֻ��5�����룬�����ֱ���1��3��9��27��81��
�����ǿ�����ϳƳ�1��121֮��������������������������������������У���
����ĿҪ����ʵ�֣����û����������(1~121)��
����������Ϸ������üӼ�ʽ��ʾ�����������������Ʒ�̣���
���磺
���룺
5
�����
9-3-1

���룺
19
�����
27-9+1

Ҫ����������������Ǵ�����ǰС���ں�
��������
�û����������(1~121)��

�������
����������Ϸ������üӼ�ʽ��ʾ�����������������Ʒ�̣���

��������
19

�������
27-9+1
*/ 

#include<iostream>//��߷���Ʒ���ұ߷�����
#include<cmath>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	int A[] = {1, 0, -1};
	int B[] = {3, 0, -3};
	int C[] = {9, 0, -9};
	int D[] = {27, 0, -27};
	int E[] = {81, 0, -81};
	int result[5];
	
	int a;
	int b;
	int c;
	int d;
	int e;
	for(a = 0; a < 3; a++)
	{
		for(b = 0; b < 3; b++)
		{
			for(c = 0; c < 3; c++)
			{
				for(d = 0; d < 3; d++)
				{
					for(e = 0; e < 3; e++)
					{
//						cout<<a<<b<<c<<d<<e<<t<<endl;
//						cout<<A[a]<<B[b]<<C[c]<<D[d]<<E[e]<<endl;
						if(A[a] + B[b] + C[c] + D[d] + E[e] == t)
						{
							
							result[0] = A[a];
							result[1] = B[b];
							result[2] = C[c];
							result[3] = D[d];
							result[4] = E[e];
							int i;
							for(i = 4; i >= 0; i--)
							{
								if(result[i] != 0)
								{
									cout<<result[i];
								}
							}
							return 0;
						}
						
					}
				}
			}
		}
	}
	return 0;
}

/*

#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	int B[20];
	int count = 0;
	int i;
	
	int n = t;
	while(n > 0)
	{
		if(n >= 81)
		{
			B[count++] = 81;
			n = n - 81;
			continue;
		}
		else if(n >= 27)
		{
			int m = n / 27;
			for(int l = 0; l < m; l++)
			{
				B[count++] = 27;
			}
			n = n - m * 27;
		}
		else if (n >= 9)
		{
			int m = n / 9;
			for(int l = 0; l < m; l++)
			{
				B[count++] = 9;
			}
			n = n - m * 9;
			continue;
		}
		else if (n >= 3)
		{
			int m = n / 3;
			for(int l = 0; l < m; l++)
			{
				B[count++] = 3;
			}
			n = n - m * 3;
			continue;
		}
		else
		{
			int m = n / 1;
			for(int l = 0; l < m; l++)
			{
				B[count++] = 1;
			}
			n = n - m * 1;
			continue;
		}
	}
	int sum = 0;
	for(i = 0; i < count; i++)
	{
		sum += B[i];
		cout<<B[i]<<endl;
	}
	n = sum - t;
	
	return 0;
 } 
 */ 
