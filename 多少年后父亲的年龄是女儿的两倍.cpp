#include<stdio.h>
int main()
{
int x = 12, y = 30, n = 0;
while (2*x != y)
{
	x++;
	y++;
	n++;
}
printf("%d", n);

return 0 ;
}
