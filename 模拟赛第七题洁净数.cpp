/*
问题描述
　　小明非常不喜欢数字 2，包括那些数位上包含数字 2 的数。如果一个数的数位不包含数字 2，小明将它称为洁净数。
　　请问在整数 1 至 n 中，洁净数有多少个？
输入格式
　　输入的第一行包含一个整数 n。
输出格式
　　输出一行包含一个整数，表示答案。
样例输入
30
样例输出
18
评测用例规模与约定
　　对于 40% 的评测用例，1 <= n <= 10000。
　　对于 80% 的评测用例，1 <= n <= 100000。
　　对于所有评测用例，1 <= n <= 1000000。
*/
#include <stdio.h>
#include<math.h>
//#include<time.h>
int main()
{
	int sum = 0;
	int input = 0;
	scanf("%d", &input);
	int result;
	//int start = clock();
	for(int i = 1; i <= input; i++)
	{
		int j = i;
		while(j)
		{
			result=j%10;
			j/=10;
			if(result == 2)
			{
				//printf("%d\n", i);
				sum ++;
				break;
			}
		}
//		printf("%d", sum);
	 }
	//int end = clock();
	printf("%d", input - sum);
	//printf("%d\n", end - start);
	return 0;
}
