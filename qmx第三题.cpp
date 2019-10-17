#include<stdio.h>

int fun1(double a)
{
	a += 0.5;
	return a;
}

int main ()
{
	double A[7] = {0.0013, 0.0228, 0.1587, 0.5, 0.8413, 0.9772, 0.9987};
	int n;
	int t;
	int u;
	int o;
	double p[100];
	scanf("%d %d %d %d\n", &n, &t, &u, &o);
	int i = 0;
	for(; i < t; i++)
	{
		int a;
		int b;
		scanf("%d %d", &a, &b);
		p[i] = (A[(int)(((b - u) / o) + 3)] - A[(int)(((a - u) / o) + 3)]) * n;
//		printf("%d %d\n", (int)(((b - u) / o) + 3) , (int)(((a - u) / o) + 3));
	}
	for(i = 0; i < t; i++)
	{

		printf("%d\n", fun1(p[i]));
	}
	return 0;
}