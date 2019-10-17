/*
¿âº¯ÊıÅÅĞò²âÊÔ
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
	return a > b;
}

int main()
{
	int n;
	int A[MAX];
	scanf("%d", &n);
	input(A, n);
	sort(A + 1, A + n + 1, cmp);
	output(A, n);
	return 0;
}
