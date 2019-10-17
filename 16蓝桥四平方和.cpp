/*
例如，输入：
5
则程序应该输出：
0 0 1 2

再例如，输入：
12
则程序应该输出：
0 2 2 2

再例如，输入：
773535
则程序应该输出：
1 1 267 838
*/

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	int A[2240];
	int B[4];
	int C[4];
	int i;
	double n;
	
	scanf("%lf", &n);
	double m = sqrt(n) + 1;
	for(i = 0; i < m; i++)
	{
		A[i] = i * i;
	}
	
	for(B[0] = 0;B[0] < m; B[0]++)
	{
		for(B[1] = 0; B[1] < m; B[1]++)
		{
			for(B[2] = 0; B[2] < m; B[2]++)
			{
				for(B[3] = 0; B[3] < m; B[3]++)
				{
					if(A[B[0]] + A[B[1]] + A[B[2]] + A[B[3]] == n)
					{
						for(i = 0; i < 4; i++)
						{
							C[i] = B[i];
						}
						sort(C, C + 4);
						printf("%d %d %d %d\n", C[0], C[1], C[2], C[3]);
					}
				}
			}
		}
	}
	return 0;
}
