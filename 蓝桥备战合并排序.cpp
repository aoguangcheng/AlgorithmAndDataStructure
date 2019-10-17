/*73.�ϲ����� (10��)
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
 ʹ�úϲ������㷨���������n�����ݽ��а���������
��������
�����У���һ��������n,�ڶ�����n��������ÿ������֮���ÿո�����

�������
�����������n������

��������
8
9 8 7 6 5 4 3 2

�������
2 3 4 5 6 7 8 9
//�Ƚ���һ�λ��֣��ٽ��кϲ� 
*/
#include<iostream>
#include<malloc.h>
using namespace std;

void combine(int A[], int min, int mid, int high)
{
	int *temp = (int *)malloc((high - min + 1) * sizeof(int));
	int i = min;
	int j = mid + 1;
	int k = 0;
	while(i <= mid && j <= high)
	{
		if(A[i] < A[j])
		{
			temp[k] = A[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = A[j];
			j++;
			k++;
		}
	}
	while(i <= mid)
	{
		temp[k] = A[i];
		i++;
		k++;
	}
	while(j <= high)
	{
		temp[k] = A[j];
		j++;
		k++;
	}
	for(k = 0, i = min; i <= high; i++, k++)
	{
		A[i] = temp[k];
	}
	free(temp); 
}

void sort(int A[], int min, int high)
{
	int mid;
	if(min < high)
	{
		mid = (high + min) / 2;
		sort(A, min, mid);
		sort(A, mid + 1, high);
		combine(A, min, mid, high);
	}
}

void disp(int A[], int n)
{
	int i;
	for(i = 1; i <= n; i++)
	{
		cout<<A[i]<<" ";
	}
}

int main()
{
	int A[100];
	int n;
	int i;
	
	cin>>n;
	for(i = 1; i <= n; i++)
	{
		cin>>A[i];
	}
	sort(A, 1, n);
	disp(A, n);
	return 0;
} 



