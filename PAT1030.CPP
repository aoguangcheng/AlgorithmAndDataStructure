/*
输入样例：
10 8
2 3 20 4 5 1 6 7 8 9
输出样例：
8
*/
#include<stdio.h> 
#define N 200
int A[N];
int B[N];
int n;
int p;

int f2(int A[], int B[])
{
	int min = 100000000;
	int max = 0;
	int m = 0;
	for(int i = 0; i < n; i++)
	{
		if(B[i] == 1)
		{
			m++;
			if(min > A[i])
				min = A[i];
			if(max < A[i])
				max = A[i];
		}
	
	}
	if(p * min >= max)
		return m;
	else
		return 0;
}

void f1(int i, int *MAX)
{
	if(i == n)
	{
		*MAX = *MAX > f2(A, B)? *MAX : f2(A, B);
	}
	else
	{
		B[i] = 0;
		f1(i + 1, MAX);
		B[i] = 1;
		f1(i + 1, MAX);
	}
}


int main()
{
	int MAX = 0;
	scanf("%d\n", &n);
	scanf("%d\n", &p);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	f1(0, &MAX);
	printf("%d", MAX);
	return 0;
}