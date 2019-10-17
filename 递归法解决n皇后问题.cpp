#include<stdio.h>
#include<math.h>
#define N 20
int q[N];

void disp(int n)
{
	static int count = 0;
	int i;
	printf("µÚ%d¸ö½â£º", count++);
	for(i = 1; i <= n; i++)
	{
		printf("{%d,%d} ", i, q[i]);
	}
	printf("\n");
	for(i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(j != q[i])
			{
				printf("-");
			}
			else
			{
				printf("+");
			}
		}
		printf("\n");
	}
	printf("\n");
}

int place(int i, int j)
{
	int k = 1;
	for(; k < i; k++)
	{
		if(q[k] == j || abs(k - i) == abs(q[k] - j))
		{
			return 0;
		}
	}
	return 1;
}

void queen(int k, int n)
{
	int j = 1;
	if(k > n)
	{
		disp(n);
	}
	else
	{
		for(; j <= n; j++)
		{
			if(place(k, j))
			{
				q[k] = j;
				queen(k + 1, n);
			}
		}
	}
}

int main()
{
	int n = 6;
	queen(1, n);
	return 0;
}