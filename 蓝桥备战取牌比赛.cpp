/*
183.取牌比赛 (15分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
 两个人玩轮流取牌游戏，一共有M张牌，每次可以取1,2,或者5张，取到最后一张牌的人为胜利。编程判断先取牌的是否能胜利。
输入描述
牌数M

输出描述
Y或者N

输入样例
2

输出样例
Y
*/
#include<iostream>
using namespace std;

int main()
{
	int i;
	int A[1000];
	int m;
	cin>>m;
	A[1] = 1;
	A[2] = 1;
	A[3] = 0;
	A[4] = 1;
	A[5] = 1;
	
	for(i = 6; i <= m; i++)
	{
		if(!A[i - 1] && !A[i - 2] && !A[i - 5])
		{
			A[i] = 1;
		}
		else
		{
			A[i] = 0;
		}
	}
	if(A[m] == 1)
	{
		cout<<"Y";
	}
	else
	{
		cout<<"N";
	}
	return 0;
}

