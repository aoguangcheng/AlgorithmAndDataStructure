/*
181.�жϹ��� (15��)
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
 С�����ֻ������������Ⱥ󾭹��������ص�A, B, C������,�������ж�С����B��������䣬�����ҹ���
��������
A, B, C������

�������
left  ���� right

��������
0,0
1,1
2,1

�������
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
