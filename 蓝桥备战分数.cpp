/*
59.分数 (15分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
 写出一个程序，接受一个以N/D的形式输入的分数，其中N为分子，D为分母，输出它的小数形式。

本题中，0≤N≤65535，0<D≤65535，设运算结果小数点后最多保留100位。
输入描述
分别输入N D

输出描述
如果它的小数形式存在循环，则要将其循环节用括号括起来。例如：
1/3= 0.(3)

输入样例
1 7

输出样例
0.(142857)
*/

#include<iostream>
using namespace std;

int fun1(int A[], int m, int n)
{
	int i;
	int j;
	int flag = 1;
	
	for(i = m, j = n; i < n; i++, j++)
	{
		if(A[i] != A[j])
		{
			flag = 0;
			return flag;
		}
	}
	return flag;
}

int main()
{
	int n;
	int m;
	int i;
	int j;
	int num1;//记录整数部分 
	int num2;//记录余数 
	int num3;//记录商 
	int count;
	int A[100];
	
	cin>>n>>m;
	num1 = n / m;
	num2 = n - m * num1;
	count = 0;
	cout<<num1<<".";
	while(count < 100 && num2 != 0)
	{
		num2 *= 10;
		num3 = num2 / m;
		A[count] = num3;
		count ++;
		num2 = num2 - num3 * m;
//		cout<<num3; 
	}
	
	for(i = 0; i < 100; i++)
	{
		for(j = i + 1; j < 100; j++)
		{
			if(A[i] == A[j])
			{
				if(fun1(A, i, j) == 1)
				{
					///////////////////
					int k;
					for(k = 0; k < i; k++)
					{
						cout<<A[k];
					}
					cout<<"(";
					for(k = i; k < j; k++)
					{
						cout<<A[k];
					}
					cout<<")";
					return 0;
				}
			}
		}
	}
	if(i == 100)
	{
		for(j = 0; j < 100; j++)
		{
			cout<<A[j];
		}
	}
	return 0;
}
