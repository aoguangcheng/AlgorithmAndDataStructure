/*
66.砝码组合 (15分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
用天平称重时，我们希望用尽可能少的砝码组合称出尽可能多的重量。
如果只有5个砝码，重量分别是1，3，9，27，81。
则它们可以组合称出1到121之间任意整数重量（砝码允许放在左右两个盘中）。
本题目要求编程实现：对用户输入的重量(1~121)，
给出砝码组合方案（用加减式表示，减代表砝码放在物品盘）。
例如：
输入：
5
输出：
9-3-1

输入：
19
输出：
27-9+1

要求程序输出的组合总是大数在前小数在后。
输入描述
用户输入的重量(1~121)，

输出描述
给出砝码组合方案（用加减式表示，减代表砝码放在物品盘）。

输入样例
19

输出样例
27-9+1
*/ 

#include<iostream>//左边放物品，右边放砝码
#include<cmath>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	int A[] = {1, 0, -1};
	int B[] = {3, 0, -3};
	int C[] = {9, 0, -9};
	int D[] = {27, 0, -27};
	int E[] = {81, 0, -81};
	int result[5];
	
	int a;
	int b;
	int c;
	int d;
	int e;
	for(a = 0; a < 3; a++)
	{
		for(b = 0; b < 3; b++)
		{
			for(c = 0; c < 3; c++)
			{
				for(d = 0; d < 3; d++)
				{
					for(e = 0; e < 3; e++)
					{
//						cout<<a<<b<<c<<d<<e<<t<<endl;
//						cout<<A[a]<<B[b]<<C[c]<<D[d]<<E[e]<<endl;
						if(A[a] + B[b] + C[c] + D[d] + E[e] == t)
						{
							
							result[0] = A[a];
							result[1] = B[b];
							result[2] = C[c];
							result[3] = D[d];
							result[4] = E[e];
							int i;
							for(i = 4; i >= 0; i--)
							{
								if(result[i] != 0)
								{
									cout<<result[i];
								}
							}
							return 0;
						}
						
					}
				}
			}
		}
	}
	return 0;
}

/*

#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	int B[20];
	int count = 0;
	int i;
	
	int n = t;
	while(n > 0)
	{
		if(n >= 81)
		{
			B[count++] = 81;
			n = n - 81;
			continue;
		}
		else if(n >= 27)
		{
			int m = n / 27;
			for(int l = 0; l < m; l++)
			{
				B[count++] = 27;
			}
			n = n - m * 27;
		}
		else if (n >= 9)
		{
			int m = n / 9;
			for(int l = 0; l < m; l++)
			{
				B[count++] = 9;
			}
			n = n - m * 9;
			continue;
		}
		else if (n >= 3)
		{
			int m = n / 3;
			for(int l = 0; l < m; l++)
			{
				B[count++] = 3;
			}
			n = n - m * 3;
			continue;
		}
		else
		{
			int m = n / 1;
			for(int l = 0; l < m; l++)
			{
				B[count++] = 1;
			}
			n = n - m * 1;
			continue;
		}
	}
	int sum = 0;
	for(i = 0; i < count; i++)
	{
		sum += B[i];
		cout<<B[i]<<endl;
	}
	n = sum - t;
	
	return 0;
 } 
 */ 
