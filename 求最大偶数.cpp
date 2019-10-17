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
 	for(i = 0; i < 100; i++)//循环结束后数组中 一共有i个元素 ，其中最后一个元素是-1 
 	{
 		scanf("%d", &num[i]);
 		if(num[i] == -1)
 		{
 			break;
		 }
	 }
	 for(j; j < i; j++)//这时候遍历数组就不能从0到100，因为i到100的数组元素并没有赋值，运行的时候可能出错，所以这时候只能遍历i个元素
	 {
	 	if(num[j] % 2 == 0 && num[j] > max2)
		 {
		 	max2 = num[j];
		  } 
	 } 
	 printf("%d", max2);
	 return 0;
 }
