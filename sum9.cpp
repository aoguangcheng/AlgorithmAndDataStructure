#include<stdio.h>
int main()
{
int n, i, sum = 0;
scanf("%d", &n);
for(i = 1;i<=n;i++)
   {
   if(i%3 == 2 && i%5 == 3)
sum = sum + i;
}
printf("%d", sum );
return 0 ;
}
