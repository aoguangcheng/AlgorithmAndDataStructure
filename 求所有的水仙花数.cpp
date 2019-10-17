#include<stdio.h>
int main()
{
int i, j, k, m;
for(i = 1;i <= 9;i++)
for(j = 0;j <= 9;j++)
for(k = 0;k <= 9;k++)
{
	m = 100*i + 10*j + k;
	if(m == i*i*i + j*j*j + k*k*k)
	printf("%4d", m);
}

return 0 ;
}
