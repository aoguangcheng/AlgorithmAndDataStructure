/*
øÏÀŸ≈≈–Ú≤‚ ‘
9
3 4 5 6 7 2 1 9 8
*/
#include<iostream>
#include<algorithm>
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

bool cmp(const int a, const int b)
{
	return a < b;
}


int Partition(int A[], int a, int b)
{
	int low;
	int high;
	int p;
	int x;
	x = a;
	low = a;
	high = b;
	p = A[a];
	while(low < high)
	{
		while(A[low] < p && high > low)
		{
			low++;
		}
		if(low < high)
		{
			A[x] = A[low];
			x = low;
		}
		while(A[high] > p && high > low)
		{
			high--;
		}
		if(low < high)
		{
			A[x] = A[high];
			x = high;
		}
	}
	A[x] = p;
	return x;
}

void QuickSort(int A[], int low, int high)
{
	if(low < high)
	{
		int p;
		p = Partition(A, low, high);
		QuickSort(A, low, p - 1);
		QuickSort(A, p + 1, high);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int A[MAX];
	input(A, n);
	QuickSort(A, 1, n);
//	sort(A + 1, A + n + 1, cmp);
	output(A, n);
	return 0;
}