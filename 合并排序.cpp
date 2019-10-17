#include<iostream>
using namespace std;

void CreatArray(int A[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cin>>A[i];
	}
}

void Merge(int A[], int n);
int MergeSort(int A[], int n)
{
	if(n <= 1)
		return 1;
	else
	{
		MergeSort(A, n / 2);
		MergeSort(A + n / 2, n - n / 2);
		Merge(A, n);
	}
}

void Merge(int A[], int n)
{
	int B[100];
	int i = 0;
	int j = n / 2;
	int k = 0;
	while(i < n / 2 && j < n)
	{
		if(A[i] <= A[j])
		{
			B[k] = A[i];
		    i++;
			k++;
		}
		else
		{
			B[k] = A[j];
		    j++;
			k++;
		}
	}
	if(i < n / 2)
	{
		for(i; i < n / 2; i++)
			B[k] = A[i];
		    k++;
	}
	else
	{
		for(j; j < n; j++)
			B[k] = A[j];
		    k++;
	}

	for(i = 0; i < n; i++)
	{
		A[i] =B[i];
	}
}

void OutputArray(int A[], int n)
{
	for(int i = 0; i < n; i++)
		cout<<A[i]<<" ";
}
int main()
{
	int A[100];
	int n;
	cin>>n;
	CreatArray(A, n);
	MergeSort(A, n);
	OutputArray(A, n);
	return 0;
}
