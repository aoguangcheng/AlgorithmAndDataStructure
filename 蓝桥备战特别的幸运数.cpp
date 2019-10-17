/*
81.特别的幸运数 (15分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
YF不爱名利，所以他既不喜欢6，也不喜欢8。他的幸运数字是4和7。如果一个数字中只包含4和7，他就认为这个数字是他的幸运数。
现在给你两个正整数a,b，要求返回a,b之间的幸运数的个数，包括a,b本身。
输入描述
第一行输入数目n,表示后面有n组ab
第2行开始，每行一组a b, 空格隔开。

输出描述
每行输出一个数，即a,b之间的幸运数的个数。

输入样例
3
11 20
4 7
1 10

输出样例
0
2
2

*/ 
#include<iostream>
using namespace std;

int A[100];
int count = 0;

int fun2(int n)
{
	int i = 1;
	int j;
	while(n / i != 0)
	{
		j = n / i % 10;
		if(j != 4 && j != 7)
		{
			return 0;
		}
		i *= 10;
	}
	return 1;
}

void fun1()
{
	int a;
	int b;
	cin>>a>>b;
	int sum = 0;
	int i;
	for(i = a; i <= b; i++)
	{
		if(fun2(i) == 1)
		{
			sum ++;
		}
	}
	A[count] = sum;
	count ++;
}

int main()
{
	int t;
	cin>>t;
	while(t > 0)
	{
		fun1();
		t--;
	}
	for(t = 0; t < count; t++)
	{
		cout<<A[t]<<endl;
	}
	return 0;
}

