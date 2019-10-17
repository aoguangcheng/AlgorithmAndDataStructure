#include<stdio.h>
int main()
{
	int month, day;
	printf("请输入月份（1-12）：");
	scanf("%d", &month);
	switch(month)
	{
	case 4:
	case 6:
	case 9:
	case 11:day = 30;break;
	case 2: day = 28;break;
	default :day = 31;
	}
	printf("%d月的天数是%d\n", month, day);
     
}
