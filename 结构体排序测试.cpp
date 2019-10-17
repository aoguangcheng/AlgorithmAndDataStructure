/*
结构体排序测试

测试数据
5
3 Tom 333333
2 John 222222
4 Serah 444444
1 Amy 111111
5 Jick 555555

测试结果
1 Amy 111111
2 John 222222
3 Tom 333333
4 Serah 444444
5 Jick 555555
*/

#include <stdio.h>
#include<algorithm>
using namespace std;

#define MAX 10
typedef struct node
{
	int index;
	char name[10];
	char s[10];
}Greedy;

void input(Greedy greedy[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%d %s %s", &greedy[i].index, &greedy[i].name, &greedy[i].s);
	}
}

void print(Greedy greedy[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%d %s %s\n", greedy[i].index, greedy[i].name, greedy[i].s);
	}
}

bool cmp(const Greedy a, const Greedy b)
{
	return a.index < b.index;
}

int main()
{
	int n;
	scanf("%d", &n);
	Greedy greedy[MAX];
	input(greedy, n);
	sort(greedy, greedy + n, cmp);
	print(greedy, n);
	return 0;
}

