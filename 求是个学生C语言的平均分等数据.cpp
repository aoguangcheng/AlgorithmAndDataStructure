#include<stdio.h>
int main()
{
int a[10], min, max, i, sum = 0;
double ave;

	min = 100;
	max = 0;
for(i = 1; i<+10;i++)
{
	scanf("%d", &a[i]) ;
{
if(a[i]>max)
max = a[i];
if(a[i]<min)
min = a[i];
}
sum = sum + a[i];
}
ave = (double)sum/10;
printf("ƽ����Ϊ��%lf����߷�Ϊ��%d����ͷ�Ϊ��%d\n", ave, max, min);
return 0 ;
}
