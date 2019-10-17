/*题目内容：
使用合并排序算法编程，对整数数组排序 
 输入描述
第一行输入元素个数，第二行输入要排序的数组
 输出描述
排好序的数组
 输入样例
7
2 5 4 1 3 7 6
输出样例
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