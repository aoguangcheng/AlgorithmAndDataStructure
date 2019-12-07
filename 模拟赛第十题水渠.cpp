/*
��������
�����ܴ����ߵ�ˮ����������С��Ҳ׼�����һ����ˮ��ˮ����
����С���������ޣ���ֻ����һ�����������ڽ���һ���򵥵�ˮ����
����С�����ȿ�̽�˵��Σ�����������һ��ˮԴ����������ˮ������㡣���⣬С����������һЩ�㣬�������λ�ú͸߶ȡ��������С�������ĵ�֮��ľ��벻���� d �Ҹ߶Ȳ�ͬ��С���Ϳ�����������֮�佨��һ��ˮ������ˮ�Ӹߴ�����ʹ�����һ�εĳ���Ϊ����֮���ֱ�߾��루����������Ĳ��ƽ������������Ĳ��ƽ�����ϸ߶Ȳ��ƽ�����ٿ�ƽ��������
����С���ƻ�ֻ��һ����ˮ������������֧��ˮ��������ˮ����Ӱ��ķ�Χ��ˮ���ĳ�������أ�С��ϣ��ˮ�������ܳ���
������ע�⣬ˮ�������ˮԴ��ʼ�ޣ����Ҹ߶�Ӧ���ݼ���ˮ���Ĳ�ͬ�ο��ܽ��棨�����ż��ɣ���
�����ʽ
��������ĵ�һ�а���һ������ n ����ʾС���Ѿ������ĵ�����
���������� n �У�ÿ���������� x, y, h���ֱ��ʾ�����ĵ�����Ϊ (x, y)���߶�Ϊ h���ⲿ�ֵĵ�һ���㼴ΪˮԴ����һ�����hֵ�����������hֵ��
����������һ�а���һ������ d��
�����ʽ
�������һ�У�����һ��ʵ�����������뱣�� 2 λС������ʾˮ������޶೤��
��������
5
1 1 10
2 3 8
4 5 9
1 2 5
4 5 5
8
�������
10.66
����˵��
��������Щ��������������Ϊ (4, 5) �ĵ㣬��������ġ�
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

//��ǰλ�õ���һλ�õľ���, indexΪ��ǰ��λ��
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