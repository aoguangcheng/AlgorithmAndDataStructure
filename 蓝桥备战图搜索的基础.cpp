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


typedef struct ANode
{
	int adjvex;
	int weight;
	struct ANode * nextarc;
}ArcNode;//边节点 

typedef struct {
	int information;
	ArcNode * firstarc;
}AVNode;//邻接表头根节点

typedef struct {
	ANode Adjlist[N + 1];
	int n;
	int e;
}ALGraph;

void GraphtoALGraph(Graph *g, ALGraph *h)
{
	int i;
	int j;
	for(i = 1; i <= N; i++)
	{
		ArcNode *p;
		ArcNode *q;
		for(j = 1; j <= N; j++)
		{
			ArcNode *p;
			p->weight = g->edges[i][j];
			p->adjvex = j;
			q->firstarc
		}
	}
}

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
	ALGraph h;
	create(&g);
	GraphtoALGraph(&g, &h);
//	display(g);
//	bfs(g, 1);
//	cout<<endl;
//	dfs(g, 1);
	return 0;
 } 
