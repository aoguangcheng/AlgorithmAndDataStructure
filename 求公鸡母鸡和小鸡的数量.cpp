#include<stdio.h>
int main ()
{
int a, b, c;

for(a = 0; a <= 19; a++)
for(b = 0; b <= 33; b++)
{
c = 100 - a - b;
if(5*a + 3*b + c/3 == 100 && c%3 == 0)
printf("¹«¼¦£º%d£¬ Ä¸¼¦£º%d£¬ Ð¡¼¦£º%d\n", a, b, c);\
}
return 0 ;
 } 
