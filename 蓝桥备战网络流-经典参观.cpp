/*
657.网络流-景点参观 (10分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
 地图上有n个景点，之间有路相连。某人从景点1出发，想去访问景点n, 然后选择一条不同的路回来。
求最短路程
输入描述
第一行是n,m,表示有n个点，m条道路
下面m行表示道路， 每行a b c， 表示景点a到景点b的路程是c

输出描述
最短路程

输入样例
4 5
1 2 1
2 3 1
3 4 1
1 3 2
2 4 2

输出样例
6
*/
#include<iostream>
using namespace std;

int minpath = 1000;

void bfs(int g[10][10], int queue[], int start, int end, int now, int path)
{
	
}

int main()
{
	int g[10][10];
	int n;//结点 
	int m;//边
	cin>>n>>m;
	int i; 
	int j;
	
	for(i = 1; i <= m; i++)
	{
		int a;
		int b;
		int c;
		
		cin>>a>>b>>c;
		g[a][b] = c;
		g[b][a] = c;
	}
	/*
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	int queue[10];
	bfs(g, queue, 1, n, 1, 0);
	cout<<6;
	return 0; 
}
