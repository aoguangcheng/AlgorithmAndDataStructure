/*
输入格式
　　第一行两个数n和m，表示学生数和图画数；
　　接下来是一个n*m的01矩阵A：
　　如果aij=0，表示学生i觉得第j幅画是小朋友画的；
　　如果aij=1，表示学生i觉得第j幅画是梵高画的。
输出格式
　　输出一个数ans：表示有多少对同学的答案完全相反。
样例输入
3 2
1 0
0 1
1 0
样例输出
2
*/ 

#include<stdio.h>
#define N 5000
#define M 20
int main()
{
	int stu;
	int pai;
	int A[N][M];
	int sum = 0;
	scanf("%d %d\n", &stu, &pai);
	int i;
	int j;
	for(i = 1; i <= stu; i++)
	{
		for(j = 1; j <= pai; j++)
		{
			scanf("%d", &A[i][j]);
		}
//		scanf("%d\n", &A[i][j]);
	}
	
	for(i = 1; i < stu; i++)
	{
		int k = i + 1;
		for(k ; k <= stu; k++)
		{
			int flag = 1;
			for(j = 1; j <= pai; j++)
			{
				if(A[i][j] == A[k][j])
				{
					flag = 0;
					break;
				}
			}
			if(flag == 1)
			{
				sum += 1;;
			}
		}
	}
	printf("%d", sum);
	return 0;
}
