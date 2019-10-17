/*10 8
2 3 20 4 5 1 6 7 8 9*/
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int p;

int f1(int i, int A[])
{
	int a = A[i] * p;
	int j;
	for(j = n - 1; j >= i; j--)
	{
		if(A[j] <= a)
			break;
	}
	return j - i + 1;
}

int main()
{
	int max = 0;
	int A[100000];
	scanf("%d %d\n", &n, &p);
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	sort(A, A + n);
/*	for(int i = 0; i < n; i++)
	{
		printf("%d", A[i]);
	}*/
	for(int k = 0; k < n; k++)
	{
		max = max > f1(k, A) ? max : f1(k, A);
	}
	printf("%d", max);
	return 0;
}