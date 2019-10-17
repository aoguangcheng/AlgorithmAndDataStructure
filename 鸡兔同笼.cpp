#include<stdio.h>
int main()
{
int x, y;

for(x = 1;x<100;x++)
{
	y = 100 - x;
	if(4*x + 2*y == 274)
	printf("兔有%d只，鸡有%d只", x, y);
}
return 0 ; 
}
