/*
112.年月日 (5分)
C时间限制：1 毫秒 |  C内存限制：3000 Kb
题目内容：
 输入某年某月某日，判断这一天是这一年的第几天？
输入描述
依次输入年月日，中间用空格隔开，如
2012 6 10

输出描述
2012-6-10是这年的第162天

输入样例
2012 6 10

输出样例
162
*/
#include<stdio.h>

bool fun1(int a)
{
	if((a % 400 == 0) || (a % 100 != 0 && a % 4 == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int a;
	int b;
	int c;
	int sum = 0;
	scanf("%d %d %d", &a, &b, &c);
	int A[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(fun1(a))
	{
		A[2] = 29;
	}
	for(int i = 1; i < b; i++)
	{
		sum = sum + A[i];
	}
	sum = sum + c;
	printf("%d", sum);
	return 0;
}
