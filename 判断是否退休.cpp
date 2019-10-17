#include<stdio.h>
int main()
{
	int age;
	char sex;
	
	printf("请输入性别和年龄："); 
	scanf("%c%d", &sex, &age); 
    if(sex == 'm'||sex == 'M')
    {
      if(age >= 60)
	  printf("他已经退休"); 
	  else
	  printf("他还在工作"); 
	}
    else if(sex == 'F' || sex == 'f')
    {
	  if(age >= 55)
      printf("她已经退休"); 
      else
	  printf("她还在工作"); 
	} 
else 
printf("输入的性别不对！\n");
 return 0 ;
 }
 
 
 
 
 
 
  
