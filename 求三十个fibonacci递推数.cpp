#include<stdio.h>
int main ()
{
int  i;
long  a[30];
a[0] = 0;
a[1] = 1;
for(i = 2;i<=29;i++)
{
	a[i] = a[i-1] + a[i-2];
    }
	for(i = 0 ;i <= 29; i++) 
	{
     if(i%6 == 0)
     printf("\n");
    printf("%10d", a[i]);
	}


}
