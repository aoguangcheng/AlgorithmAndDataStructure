/*
2.标题：激光样式

x星球的盛大节日为增加气氛，用30台机光器一字排开，向太空中打出光柱。
安装调试的时候才发现，不知什么原因，相邻的两台激光器不能同时打开！
国王很想知道，在目前这种bug存在的情况下，一共能打出多少种激光效果？

显然，如果只有3台机器，一共可以成5种样式，即：
全都关上（sorry,?此时无声胜有声，这也算一种）
开一台，共3种
开两台，只1种

30台就不好算了，国王只好请你帮忙了。

要求提交一个整数，表示30台激光器能形成的样式种数。

注意，只提交一个整数，不要填写任何多余的内容。

思路很简单，暴力搜索，30个灯光从左到右，从左边第一个开始，第一个可以开关，
第二个要根据左边的灯光是否开启来取值，以此类推。。。 答案2178309

*/ 

#include<stdio.h>
#define N 30
int sum = 0;

int fun2(int A[])
{
	int i;
	for(i = 0; i < N - 1; i++)
	{
		if(A[i] == 1 && A[i + 1] == 1)
			return 0;
	}
	return 1;
}

void fun1(int A[], int i)
{
	if(i == N)
	{
		if(fun2(A))
		{
			sum++;
		}
		return ;
	}
	else
	{
		A[i] = 0;
		fun1(A, i + 1);
		A[i] = 1;
		fun1(A, i + 1);
	}
}
int main()
{
	int A[N];
	fun1(A, 0);
	printf("%d", sum);
	return 0;
}
