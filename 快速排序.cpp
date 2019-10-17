#include<stdio.h>
#define MAX 100
int A[MAX];
int Partition(int A[], int n)
{
	
	int index = 0;
	int x = A[0];
	int i = 0;
	int j = n - 1;
	while(i < j)
	{
		while(i < j && A[j] > x)
		{
			j--;
		}
		if(i < j)
		{
			A[index] = A[j];
			index = j;
		}
		while(i < j && A[i] < x)
		{
			i++;
		}
		if(i < j)
		{
			A[index] = A[i];
			index = i;
		}
	}
	A[index] = x;
	return index;
}

int QuickSort(int A[], int n)
{
	int index;
	if(n <= 1)
		return 1;
	else
	{
		index = Partition(A, n);
		QuickSort(A, index);
		QuickSort(A + index +1, n - index -1);
		return 1;
	}
}
int main ()
{
	int n;
	int i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &A[i]);
	QuickSort(A, n);
	for(i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	return 0;
}