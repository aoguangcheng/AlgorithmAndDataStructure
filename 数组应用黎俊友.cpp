/*从键盘输入15个整数到数组中，
求其最大值，最小值，正数的个数及其平均值（保留两位小数）
//黎俊友 2017105934
*/
#include<stdio.h>
#define N 15           //定义数组长度 
int main()
{
	int a[N];          // 定义数组 
	int i;          
	int max;           // 最大值 
	int min;           // 最小值 
	int j = 0;
	int sum = 0;
	double ave = 0;    // 平均数 
	
	printf("请输入十五个整数：\n"); 
	for(i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	
	min = a[0];
	max = a[0];
	for(i = 0; i < N; i++)
	{
		if(a[i] < min)
		min = a[i];
		if(a[i] > max)
		max = a[i];
	}
	printf("最大值为：%d\n", max);     //for循环和if嵌套求最大值 
	printf("最小值为：%d\n", min);     //for循环和if嵌套求最小值 
	
	for(i = 0; i < N; i++)
	{
		if(a[i] > 0)
		{
			j++;
		}
	}
	printf("正数的个数为：%d\n", j);   //for循环和if嵌套求正数个数
	
	for(i = 0; i < N; i++)
	{
		sum = sum + a[i];
	}
	ave = (double)sum / N; 
    printf("平均数为：%.2lf\n", ave);  //for循环求平均值 
	
    return 0 ;
}
