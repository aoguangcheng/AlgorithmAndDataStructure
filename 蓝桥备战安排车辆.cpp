/*
182.安排车辆 (15分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
 有一家出租车公司，通过网络预约安排出租。现收到M个预约单，希望用车时间区间是（s1,f1）,(s2,f2),...,(sM,fM).
问最少需要准备几辆车才能完成出租。提示：车辆归还后，下一个客户才可以使用。
输入描述
第一行是M，随后M行是预约的时间区间

输出描述
最少需要的车的台数

输入样例
4
1,5
2,7
3,6
8,10

输出样例
3
*/
#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int A[100] = {0};
	int n;
	cin>>n;
	while(n--)
	{
		int m;
		int n;
		scanf("%d,%d", &m, &n);
		for(m; m <= n; m++)
		{
			A[m]++;
		}
	}
	int max = 0;
	int i;
	for(i = 0; i < 100; i++)
	{
		max = max < A[i] ? A[i] : max;
	}
	cout<<max;
	return 0;
}

