#include<stdio.h>
int main()
{
int b;
printf("请输入口令：");
scanf("%d", &b);
while(b != 100)
{
printf("输入口令不正确！\n"); 
printf("请再次输入口令！");
scanf("%d", &b);
}
printf("口令正确！");
return 0 ;
}
