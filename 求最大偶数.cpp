/*#include<stdio.h>

int main()
{
	int x;
	int max = 0;
	scanf("%d", &x);
	while(x != -1)
	{
		if(x % 2 == 0 && x > max)
		{
			max = x;
		}
		scanf("%d", &x);
	}
	printf("%d", max); 
	return 0;
 } 
 */ 
 
 #include<stdio.h>
 
 int main()
 {
 	int x;
 	int max2 = 0;
 	int num[100];
 	int j = 0;
 	int i = 0;
 	for(i = 0; i < 100; i++)//ѭ�������������� һ����i��Ԫ�� ���������һ��Ԫ����-1 
 	{
 		scanf("%d", &num[i]);
 		if(num[i] == -1)
 		{
 			break;
		 }
	 }
	 for(j; j < i; j++)//��ʱ���������Ͳ��ܴ�0��100����Ϊi��100������Ԫ�ز�û�и�ֵ�����е�ʱ����ܳ���������ʱ��ֻ�ܱ���i��Ԫ��
	 {
	 	if(num[j] % 2 == 0 && num[j] > max2)
		 {
		 	max2 = num[j];
		  } 
	 } 
	 printf("%d", max2);
	 return 0;
 }
