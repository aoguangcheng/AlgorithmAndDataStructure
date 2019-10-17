/*直接插入排序测试
测试数据：
5
3 2 4 1 5
*/
#include<iostream>
using namespace std;
const int MAX = 10;

void input(int A[], int n)
{
	int i;
	for(i = 1; i <= n; i++)
	{
		cin>>A[i];
	}
}

void output(int A[], int n)
{
	int i;
	for(i = 1; i <= n; i ++)
	{
		cout<<A[i]<<" ";
	}
}

void sort(int A[], int n)
{
	int i;
	for(i = 2; i <= n; i++)
	{
		A[0] = A[i];
		int j;
		j = i - 1;
		while(A[j] > A[0])
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = A[0];
	}
}

int main()
{
	int n;
	int A[MAX + 1];
	cin>>n;
	input(A, n);
	sort(A, n);
	output(A, n);
	return 0;
}
