/*
119.���·�� (15��)
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
 ��5������(A,B,C,D,E),����ÿ�����е��������е�ֱ�������֪����������֮��ֻ��һ����·������ӳ���A�������������
�����·�����롣
��������
4�����ݣ� ��һ����A��(B,C,D,E)��ֱ����룬�ڶ�����B����C,D,E����ֱ����룬����������4����D��E��ֱ����롣

�������
A���е�(B,C,D,E)����̾��롣

��������
2 3 4 5  
3 4 2 
4 3   
3

�������
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
	for(i = 0; i <= N; i++)//ȫ����ʼ��Ϊ�� 
	{
		visited[i] = 0;
	}
	cout<<v;
	rear = (rear + 1) % (N + 1);//��β��1 
	visited[v] = 1;//���ʹ��ýڵ㸳ֵΪ1�� 
	queue[rear] = v;//���ʹ��ýڵ���� 
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
	bool inM[5] = { 0 };//��ʾ�Ƿ��ѽ���M����
	int cost[5][5] = { 0 };
	for(int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			if (i < j)
				cin >> cost[i][j];
			cost[j][i] = cost[i][j];
		}//����
 
	for (int i = 0; i < 5; i++)
		dis[i] = cost[0][i];//��1����dis[]
 
	inM[0] = 1;//��һ������A��Ȼ�ǽ�����M����
 
	for (int i = 1; i <= 4; i++)
	{
		int min = INFINITE;
		int minpos = 0;
		for(int j = 0; j < 5; j++)
			if (inM[j] == 0 && dis[j] < min) {
				//û�н���M���ϵĲ���·�����
				min = dis[j];
				minpos = j;
			}
		inM[minpos] = 1;
		for(int j = 0; j < 5; j++)
			if (inM[j] == 0 && dis[j] > dis[minpos] + cost[minpos][j])
				dis[j] = dis[minpos] + cost[minpos][j];
			//�Ƿ񾭹����minpos������dis[]
	}
	for (int i = 1; i < 5; i++)
		cout << dis[i] << " ";//���
	return 0;
}
