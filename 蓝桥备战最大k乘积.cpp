/*
68.���k�˻����� (15��)
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
��I��һ��nλʮ��������.�����I����Ϊk��,��ɵõ�k������.��k�������ĳ˻���ΪI��һ��k�˻�.�����һ���㷨,���ڸ���
��I��k ,���I�����k�˻�.
Input
����ĵ�1������2��������n��k.������n�����еĳ���;������k�Ƿָ�Ķ���.��������һ������һ��nλʮ��������.��n<=10��
Output
�������������1���е����Ǽ���������k�˻�.
nλʮ��������.��n<=10��
��������
����ĵ�1������2��������n��k.������n�����еĳ���;������k�Ƿָ�Ķ���.��������һ������һ��

�������
�������������1���е����Ǽ���������k�˻�.

��������
2 1
15

�������
15


#include<iostream>  
using namespace std;  
#define N 20  
int m[N][N];  
char num[N];  
  
int atoi(char arr[],int i,int j)  
{  
	int sum=0;  
	while(i<=j)  
	{  
        sum = sum*10+arr[i]-'0';  //�˴��������˺���pow��Ȼ��wa�ˣ�һֱ�Ҳ������ںδ���  
		i++;		//������ʦ�֣��ŷ���ԭ��pow(double,int)   
	} 			//�Ĳ���double��ʹ�����ƫ��ĵ����ac��  
    return sum;  
}  
  
int main()  
{  
	int n,k,i,j,l,max,flag;  
	while(cin>>n>>k)  
	{  
		for(i=1;i<=n;i++)  
			cin>>num[i];  
		m[1][1]=num[1]-'0';  
		for(i=2;i<=n;i++)  
			m[i][1]=m[i-1][1]*10+(num[i]-'0'); //��ʼ����һ��  
		for(j=2;j<=k;j++)//���н��г�ʼ��  
		{  
			max=-1;  
			for(i=1;i<=n;i++)  
			{  
				if(j>i)  
					m[i][j]=0;  
				else  
				{  
					for(l=j-1;l<=i-1;l++)  
					{  
						flag=m[l][j-1]*atoi(num,l+1,i);  
						if(flag>max)  
						max=flag;  
					}  
					m[i][j]=max;  
				}  
			}  
		}  
		cout<<m[n][k]<<endl;  
	}  
	return 0;  
}
*/

#include<iostream>
#include<stdio.h>
using namespace std;

int fun1(char A[], int i, int j)//��������A[]�д� i �� j ����ʾ����ֵ��С��int�� ���� i <= j 
{
	int sum;
	sum = A[i] - 48;
	i++;
	while(i <= j)
	{
		sum = sum * 10 + A[i] - 48;
		i++;
	}
	return sum;
}

int main()
{
	int n;
	int k;
	int i;
	int j;
	char A[10];
	int B[11][11] = {0};
	
	cin>>n>>k;
	for(i = 1; i <= n; i++)
	{
		cin>>A[i];
	}
	for(i = 1; i <= n; i++)
	{
		B[i][1] = fun1(A, 1, i);
	 } 
	 
	for(j = 2; j <= k; j++)
	{
		for(i = 2; i <= n; i++)
		{
			if(j > i)
			{
				B[i][j] = 0;
			}
			else
			{
				int k = 1;
				int flag;
				int max = 0;
				for(k; k < i; k++)
				{
					flag = B[k][j - 1] * (A[i] - 48);
					if(max < flag)
					{
						max = flag;
					}
				}
			}
		}
	}
/*	 
	 for(i = 1; i <= n; i++)
	 {
	 	for(j = 1; j <= k; j++)
	 	{
	 		cout<<B[i][j]<<" ";
		 }
		 cout<<endl;
	 }
*/	 
	cout<<B[n][k];
	return 0;
}

