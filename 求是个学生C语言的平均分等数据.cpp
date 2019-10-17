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
printf("平均分为：%lf，最高分为：%d，最低分为：%d\n", ave, max, min);
return 0 ;
}
