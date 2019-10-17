#include<stdio.h>
	
int B[10] = {11};
int sum = 0;

void fun1(int m, int n, int k)//在长度为n的数组的下标为m的位置插入k
{
	int i;
	for(i = n; i >= m; i--)
	{
		B[i + 1] = B[i];
	}
	B[m] = k;
}

void fun3(int m, int n)//在长度为n的数组中删除下标为m的数
{
	for(int i = m; i < n; i++)
	{
		B[i] = B[i + 1];
	}
}

void fun2(int a[], int k)
{
	if(k > 9)
	{
		/*for(int h = 0; h <= 9; h++)
		{
			printf("%d ", B[h]);
		}
		printf("\n");*/
		sum ++;
		return ;
	}
	else
	{
		for(int j = 0; j <= k; j++)
		{
			fun1(j, k, a[k]);
			fun2(a, k + 1);
			fun3(j, k);
		}
		return ;
	}
}

int main()
{
	int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	fun2(A, 0);
	printf("%d", sum);
	return 0;
}