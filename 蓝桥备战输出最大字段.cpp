/*
120.����Ӷκ� (20��)
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
 ʵ������a[1],a[2],...a[n], һ���Ӷ�ָһ��������������a[i],a[i+1],...a[j], ����1<=i<=j<=n. Ҫ�����������
��͵��ӶΡ�Ҫ���㷨ʱ�临����Ϊo(n)��
��������
��һ������һ������n,��ʾԭ���й���n�����ݣ�
�ڶ�������n��ʵ�����ÿո������

�������
���͵��ӶΣ�ÿ������Ҳ�ÿո������
������Ĳ��������ܱ�֤���͵���һ���Ӷ���Ψһ�ģ�

��������
7
-1 3 -2 4 -1 6 -5

�������
3 -2 4 -1 6

*/

#include<iostream>
using namespace std;

int main()
{
	int n;
	int A[30];
	int B[30];
	int C[30];
	int i;
	int j;
	int count;
	
	cin>>n;
	for(i = 0; i < n; i++)
	{
		cin>>A[i];
	}
	if(A[0] > 0)
	{
		B[0] = A[0];
	}
	else
	{
		B[0] = 0;
	}
	for(i = 1, j = 1; i < n; i++, j++)
	{
		if(A[i] > 0)
		{
			B[j] = A[i] + B[j - 1];
		}
		else
		{
			if(B[j - 1] + A[i] > 0)
			{
				B[j] = A[i] + B[j - 1]; 
			}
			else
			{
				B[j] = 0;
			}
		}
	} 
	int max = 0;
	for(i = 0; i < n; i++)
	{
		if(max < B[i])
		{
			max = B[i];
			j = i;
		}
	}
	count = 0;
	while(max - A[j] > 0)
	{
		max = max - A[j];
		C[count] = A[j];
		count++;
		j--;
	}
	C[count] = A[j];
	count++;
	for(i = count - 1; i >= 0; i--)
	{
		cout<<C[i]<<" ";
	}
//	cout<<max;
	return 0;
}
