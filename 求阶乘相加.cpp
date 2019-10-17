#include<stdio.h>
int main()
{
 int n, i, j;
 long p, sum = 0;
 
 scanf("%d", &n);
 for(i = 1;i<=n;i++)
{
  p = 1;
 for(j = 1;j<=i;j++)
 
 p = p*j;
 sum = sum + p;
 
}
 printf("%d", sum);
 
 return 0 ;
 } 
