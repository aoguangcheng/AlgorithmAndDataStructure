/*
119.最短路径 (15分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
 有5个城市(A,B,C,D,E),其中每个城市到其他城市的直达距离已知，两个城市之间只有一条公路。计算从城市A到其他任意城市
的最短路径距离。
输入描述
4行数据， 第一行是A到(B,C,D,E)的直达距离，第二行是B到（C,D,E）的直达距离，。。。，第4行是D到E的直达距离。

输出描述
A城市到(B,C,D,E)的最短距离。

输入样例
2 3 4 5  
3 4 2 
4 3   
3

输出样例
2 3 4 4

#include<iostream>
#include<memory.h>
using namespace std;
const int N = 5;
int visited[N + 1] = {0};

typedef struct 
{
	int no;
	char information;
}VNode;

typedef struct
{
	int edges[N + 1][N + 1];
	int n;
	int e;
	VNode vexs[N + 1];
}Graph;

void bfs(Graph g, int v)
{
	int visited[N + 1];
	int queue[N + 1];
	int rear = 0;
	int front = 0;
	int i;
	for(i = 0; i <= N; i++)//全部初始化为零 
	{
		visited[i] = 0;
	}
	cout<<v;
	rear = (rear + 1) % (N + 1);//队尾加1 
	visited[v] = 1;//访问过得节点赋值为1； 
	queue[rear] = v;//访问过得节点入队 
	while(front != rear)
	{
		int w;
		front = (front + 1) % (N + 1);
		w = queue[front];
		for(i = 1; i <= N; i++)
		{
			if(g.edges[w][i] != 0 && visited[i] == 0)
			{
				rear = (rear + 1) % (N + 1);
				queue[rear] = i;
				cout<<i;
				visited[i] = 1;
			}
		}
	}
}

void dfs(Graph g, int v)
{
	visited[v] = 1;
	cout<<v;
	int i;
	
	for(i = 1; i <= N; i++)
	{
		if(g.edges[v][i] != 0 && visited[i] == 0)
		{
			dfs(g, i);
		}
	}
}

void create(Graph *g)
{
	int i;
	int j;
	memset(g->edges, 0, sizeof(g->edges));
	for(i = 1; i <= N - 1; i++)
	{
		for(j = i + 1; j <= N; j++)
		{
			int data;
			cin>>data;
			g->edges[i][j] = data;
			g->edges[j][i] = data; 
		}
	}
	
}

void display(Graph g)
{
	int i;
	int j;
	for(i = 1; i <= N; i++)
	{
		for(j = 1; j <= N; j++)
		{
			cout<<g.edges[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	Graph g;
	create(&g);
	display(g);
	bfs(g, 1);
	cout<<endl;
	dfs(g, 1);
	return 0;
 } 

*/ 
#include <iostream>
#define INFINITE 0x7fffffff
using namespace std;
 
int main() {
 
	int dis[5] = { 0 };
	bool inM[5] = { 0 };//表示是否已进入M集合
	int cost[5][5] = { 0 };
	for(int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			if (i < j)
				cin >> cost[i][j];
			cost[j][i] = cost[i][j];
		}//输入
 
	for (int i = 0; i < 5; i++)
		dis[i] = cost[0][i];//第1步的dis[]
 
	inM[0] = 1;//第一个城市A自然是进入了M集合
 
	for (int i = 1; i <= 4; i++)
	{
		int min = INFINITE;
		int minpos = 0;
		for(int j = 0; j < 5; j++)
			if (inM[j] == 0 && dis[j] < min) {
				//没有进入M集合的并且路径最短
				min = dis[j];
				minpos = j;
			}
		inM[minpos] = 1;
		for(int j = 0; j < 5; j++)
			if (inM[j] == 0 && dis[j] > dis[minpos] + cost[minpos][j])
				dis[j] = dis[minpos] + cost[minpos][j];
			//是否经过这个minpos，更新dis[]
	}
	for (int i = 1; i < 5; i++)
		cout << dis[i] << " ";//输出
	return 0;
}
