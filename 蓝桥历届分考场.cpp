/*
问题描述
　　n个人参加某项特殊考试。
　　为了公平，要求任何两个认识的人不能分在同一个考场。
　　求是少需要分几个考场才能满足条件。
输入格式
　　第一行，一个整数n(1<n<100)，表示参加考试的人数。
　　第二行，一个整数m，表示接下来有m行数据
　　以下m行每行的格式为：两个整数a，b，用空格分开 (1<=a,b<=n) 表示第a个人与第b个人认识。
输出格式
　　一行一个整数，表示最少分几个考场。
样例输入
5
8
1 2
1 3
1 4
2 3
2 4
2 5
3 4
4 5
样例输出
4
样例输入
5
10
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
4 5
样例输出
5
*/ 

#include<stdio.h>

int fun1(int m, int i, int j, int B[1000][100], int A[1000][2])
{
	int a;
	int b;
	for(a = 0; a < m; a++)
	{
		if(A[a][0] == i)
		{
			for(b = 1; b <= B[j][0]; b++)
			{
				if(B[j][b] == A[a][1])
				{
					return 0;
				}
			}
		}
		if(A[a][1] == i)
		{
			for(b = 1; b <= B[j][0]; b++)
			{
				if(B[j][b] == A[a][0])
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

int fun2(int B[1000][100])
{
	int i;
	int sum = 0;
	for(i = 0; B[i][0] != 0; i++)
	{	
		sum ++;
	}
	return sum;
}

int main()
{
	int n;
	int m;
	int i;
	int j;
	int A[1000][2];
	int B[1000][100] = {0};
	
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++)
	{
		scanf("%d %d", & A[i][0], &A[i][1]);
	}
	
	for(i = 1; i <= n;i++)
	{
		for(j = 0; ;j++)
		{
			if(fun1(m, i, j, B, A) == 1)
			{
				B[j][0] ++;
				B[j][B[j][0]] = i;
				break;
			}
		}
	}
	printf("%d", fun2(B));
	return 0;
}
