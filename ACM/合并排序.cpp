/*��Ŀ���ݣ�
ʹ�úϲ������㷨��̣��������������� 
 ��������
��һ������Ԫ�ظ������ڶ�������Ҫ���������
 �������
�ź��������
 ��������
7
2 5 4 1 3 7 6
�������
1 2 3 4 5 6 7
*/

#include<iostream>
using namespace std;

void CreatArray(int a[], int n )
{
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
}

void Sort(int a[], int n )
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < n - i - 1; j++)
		{
			if(a[j] > a[j + 1])
			{
				int temp;
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void OutputArray(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
}

int main()
{
	int n;
	cin>>n;
	int a[10];
	CreatArray(a, n);
	Sort(a, n);
	OutputArray(a, n);
	return 0;
}