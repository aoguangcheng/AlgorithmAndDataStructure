#include<stdio.h>
double jiecheng(int n)
{
	int i;
	double s = 1;
	for(i = 1; i <= n; i++)
	{
		s = s * i;
	}
	return s;
}
int main()
{
	int m, n;
	double a;
	
	scanf("%d%d", &m, &n);
	a = jiecheng(m)/(jiecheng(n) * jiecheng(m - n));
	printf("%.0lf", a);
}
