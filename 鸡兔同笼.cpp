#include<stdio.h>
int main()
{
int x, y;

for(x = 1;x<100;x++)
{
	y = 100 - x;
	if(4*x + 2*y == 274)
	printf("����%dֻ������%dֻ", x, y);
}
return 0 ; 
}
