/*
84.Ѱ������� (15��)
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
�������� n ��ɾ��m������, ʹ�����µ����ְ�ԭ������ɵ��������
���統n=92081346718538��m=10ʱ�����µ��������9888
��������
��һ������һ��������T����ʾ��T���������ÿ���������ռһ�У�ÿ����������n,m��n������һ���ܴ������������λ������
��100λ�����ұ�֤������λ��0��mС������n��λ����

�������
ÿ��������ݵ����ռһ�У����ʣ������ְ�ԭ������ɵ��������

��������
2
92081346718538 10
1008908 5

�������
9888
98
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char S[100];
		int m;
		int i;
		int j;
		
		cin>>S;
		cin>>m;
		m = strlen(S) - m;
		int flag = 0;
		for(i = 0, j = 0; i < m; i++)
		{	
			int k;
			char max = S[flag];
			for(k = flag + 1; k <= strlen(S) - m + j; k++)
			{
				if(max < S[k])
				{
					max = S[k];
					flag = k;
				}
			}
			flag++;
			cout<<max;
			j++;
		}
		cout<<endl;
	}
	return 0;
}
