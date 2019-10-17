/*73.合并排序 (10分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
 使用合并排序算法，对输入的n个数据进行按升序排序。
输入描述
分两行，第一行是整数n,第二行是n个整数，每个整数之间用空格间隔。

输出描述
按升序排序的n个整数

输入样例
8
9 8 7 6 5 4 3 2

输出样例
2 3 4 5 6 7 8 9
//先进行一次划分，再进行合并 
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



