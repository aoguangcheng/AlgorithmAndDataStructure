#include<stdio.h>
int main()
{
	int age;
	char sex;
	
	printf("�������Ա�����䣺"); 
	scanf("%c%d", &sex, &age); 
    if(sex == 'm'||sex == 'M')
    {
      if(age >= 60)
	  printf("���Ѿ�����"); 
	  else
	  printf("�����ڹ���"); 
	}
    else if(sex == 'F' || sex == 'f')
    {
	  if(age >= 55)
      printf("���Ѿ�����"); 
      else
	  printf("�����ڹ���"); 
	} 
else 
printf("������Ա𲻶ԣ�\n");
 return 0 ;
 }
 
 
 
 
 
 
  
