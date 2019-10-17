/*
’€∞Î≤È’“≤‚ ‘
9
1 2 3 4 5 6 7 8 9 
3
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

int BinSearch(int A[], int n, int m)
{
	int low;
	int high;
	int mid;

	low = 1;
	high = n;
	mid = (low + high) / 2;

	while(low <= high && A[mid] != m)
	{
		if(A[mid] > m)
		{
			high = mid;
		}
		else
		{
			low = mid;
		}
		mid = (low + high) / 2;
	}
	return mid;
}

int main()
{
	int n;
	int m;
	int A[MAX];
	cin>>n;
	input(A, n);
	cin>>m;
	cout<<BinSearch(A, n, m);
/*	output(A, n);*/
	return 0;
}