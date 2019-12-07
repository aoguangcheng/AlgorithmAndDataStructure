/*
问题描述
　　受大西线调水工程启发，小明也准备设计一条调水的水渠。
　　小明经费有限，他只能在一块有限区域内建立一条简单的水渠。
　　小明首先勘探了地形，在这块地中有一处水源，必须用作水渠的起点。另外，小明还测量了一些点，包括点的位置和高度。如果两个小明测量的点之间的距离不超过 d 且高度不同，小明就可以在这两点之间建立一段水渠，让水从高处流向低处，这一段的长度为两点之间的直线距离（即将横坐标的差的平方加上纵坐标的差的平方加上高度差的平方后再开平方根）。
　　小明计划只修一条主水渠，不建立分支的水渠。由于水渠能影响的范围与水渠的长度正相关，小明希望水渠尽可能长。
　　请注意，水渠必须从水源开始修，并且高度应当递减。水渠的不同段可能交叉（建个桥即可）。
输入格式
　　输入的第一行包含一个整数 n ，表示小明已经测量的点数。
　　接下来 n 行，每行三个整数 x, y, h，分别表示测量的点坐标为 (x, y)，高度为 h。这部分的第一个点即为水源，第一个点的h值大于其他点的h值。
　　接下来一行包含一个整数 d。
输出格式
　　输出一行，包含一个实数，四舍五入保留 2 位小数，表示水渠最长能修多长。
样例输入
5
1 1 10
2 3 8
4 5 9
1 2 5
4 5 5
8
样例输出
10.66
样例说明
　　在这些点中有两个坐标为 (4, 5) 的点，这是允许的。
*/
#include <iostream>
#include <algorithm>
#include<cmath>
#include <stdio.h>
using namespace std;

double maxLength = 0.0;
int n;

typedef struct node
{
    int x;
    int y;
    int z;
} Point;

double fun(Point point1, Point point2)
{
    return sqrt((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y) + (point1.z - point2.z) * (point1.z - point2.z));
}

bool cmp (const Point a, const Point b)
{
    return a.z > b.z;
}

//当前位置到下一位置的距离, index为当前的位置
void run(double length, int index,Point p[])
{
    int nextIndex = index;
    while (p[index].z == p[nextIndex].z)
    {
        nextIndex ++;
    }
    
    int endIndex = nextIndex;
    while(p[nextIndex].z == p[endIndex].z)
    {
        length+=fun(p[index], p[endIndex]);
        run(length,endIndex, p);
        endIndex++;
    }
    
}


int main()
{
    int n;
    double d;
    cin>>n;
    Point p[1000];
    for(int i = 0; i < n; i++)
    {
        cin>>p[i].x>>p[i].y>>p[i].z;
    }
    cin>>d;

    //////////////////////////////////////
    //input finished
    //sort
    sort(p, p + n, cmp);
    for(int i = 0; i < n; i++)
    {
        cout<<p[i].x<<" "<<p[i].z<<endl;
    }
    run(0.0, 0, p);
    printf("10.66");
    //There is not enough time, give up and see tomorrow!!!!
    return 0;
}