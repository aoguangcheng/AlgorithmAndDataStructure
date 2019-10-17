/*
181.判断拐弯 (15分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
 小张用手机传来他开车先后经过的三个地点A, B, C的坐标,请你编程判断小张在B点是左拐弯，还是右拐弯
输入描述
A, B, C的坐标

输出描述
left  或者 right

输入样例
0,0
1,1
2,1

输出样例
right

*/

#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	double ax;
	double ay;
	double bx;
	double by;
	double cx;
	double cy;
	double k;
	double b;
	
	scanf("%d,%d%d,%d%d,%d", &ax, &ay, &bx, &by, &cx, &cy);
	k = (ay - by) / (ax - bx);
	b = ay - k * ax;
	if(bx > ax)
	{
		if(cy > k * cx + b)
		{
			cout<<"left";
		}
		else
		{
			cout<<"right";
		}
	}
	else
	{
		if(cy < k * cx + b)
		{
			cout<<"left";
		}
		else
		{
			cout<<"right";
		}
	}
	return 0;
 } 
