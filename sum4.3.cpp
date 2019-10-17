#include<stdio.h>
int main()
{
int a;

do{

printf("请输入口令：");
scanf("%d", &a); 
printf("口令不正确！\n 请再次输入口令：");
}
while(a != 100);
{printf("口令正确！");}
return 0 ;
}
