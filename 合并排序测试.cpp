/*
∫œ≤¢≈≈–Ú≤‚ ‘
9
3 4 5 6 7 2 1 9 8
*/
#include<iostream>
#include<malloc.h>
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

void Merge(int A[], int low, int mid, int high)
{
	int *temp;
	int i;
	int j; 
	int k;
	i = low;
	j = mid + 1;
	k = 1;
	temp = (int *)malloc((high - low + 2) * sizeof(int));
	while(i <= mid && j <= high)
	{
		if(A[i] < A[j])
		{
 			temp[k] = A[i];
			i++;
			k++;
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
		k++;
		j++;
	}

	for(k = 1, i = low; i <= high; k++, i++)
	{
		A[i] = temp[k];
	}
	free(temp);
}

void MergeSort(int A[], int low, int high)
{
	if(low < high)
	{
		int mid;
		mid = (high + low) / 2;
		MergeSort(A, low, mid);
		MergeSort(A, mid + 1, high);
		Merge(A, low, mid, high);
	}
}

int main()
{
	int n;
	int A[MAX];
	scanf("%d", &n);
	input(A, n);
	MergeSort(A, 1, n);
	output(A, n);
	return 0;
}