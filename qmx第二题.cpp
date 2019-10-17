#include<stdio.h>
#include<string.h>

int fun1(char ch, char s[])//统计字符s[i]出现的次数
{
	int sum  = 0;
	int i = 0;
	while(s[i] != '\0')
	{
		if(ch == s[i])
		{
			sum ++;
		}
		i++;
	}
	return sum;
}

int fun2(char ch, char s[], int min)//确认字符s[i]是否是出现次数最少的
{
	int sum  = 0;
	int i = 0;
	while(s[i] != '\0')
	{
		if(ch == s[i])
		{
			sum ++;
		}
		i++;
	}
	if(min == sum)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	char s[50];
	int a[50] = {0};
	gets(s);
	int i = 0;
	int min = 10000;
	while(s[i] != '\0')
	{
		int sum = fun1(s[i], s);
		if(min > sum)
		{
			min = sum;
		}
		i++;
	}
	int N = i;//记录字符串数组中的元素个数
	i = 0;
	while(s[i] != '\0')
	{
		if(fun2(s[i], s, min))//若字符s[i]是出现次数最小的，则需要删除，在数组a[]内将该位置置1
		{
			a[i] = 1;
		}
		i++;
	}
	i = 0;
	int flag = 0;
	while(i < N)
	{
		if(a[i] == 1)
		{
			flag ++;
		}
		i++;
	}
	if(flag == N)
	{
		printf("qmx");
		return 0;
	}
	i = 0;
	while(i < N)
	{
		if(a[i] == 0)
		{
			printf("%c", s[i]);
		}
		i++;
	}
	return 0;
}