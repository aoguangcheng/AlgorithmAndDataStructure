/*
64.分苹果 (15分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？M, N为自然数。说明：如有7个苹
果，3个盘子，则(5, 1, 1)和(1, 5, 1)和(1, 1, 5)都是同一种分法。
输入描述
第一行一个整数表示数据的组数（多组数据），对于每组数据第一行是苹果个数M (1 ≤ m ≤ 100) ，第二行是盘子个数N(1 ≤ 
n ≤ 100)。

输出描述
每组数据输出一行,放苹果的方法个数。

输入样例
1 
3 
2

输出样例
2

*/
#include<iostream>
using namespace std;

int B[100];
int count = 0;
void fun1()
{
	int m;
	int n;
	cin>>m;
	cin>>n;
	int i;
	int j;
	
	int A[100][100] = {0};
	A[1][1] = 1;
	for(i = 1; i <= m; i++)
	{
		for(j = 1; j <= n; j++)
		{
			if(i < j)
			{
				A[i][j] = A[i][i];
			}
			else if(i == j)
			{
				A[i][j] = A[i][j - 1] + 1;
			}
			else
			{
				A[i][j] = A[i][j - 1] + A[i - j][j];
			}
		}
	} 
	B[count] = A[m][n];
	count++;
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
		cout<<B[t]<<endl;
	}
	return 0;	
}
