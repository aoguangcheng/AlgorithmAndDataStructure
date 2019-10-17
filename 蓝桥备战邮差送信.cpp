/*
107.�ʲ����� (15��)
Cʱ�����ƣ�1 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
 ��һ���ʵ�ԱҪ��n������֮���������š����еĳ���֮���д�·�������е�û��·��
����Ҫ��һ�����е���һ���������ţ���;����Ҫ�������ٸ������ĳ����أ�
��������
��һ����n,k(1<=n<=10000, 1<=k<=20000)������������k�С���k��ÿ����������a,b(1<=a,b<= n)����ʾ����a��b֮����
��·k���Ժ����������p��q��

�������
����ӳ���p������q֮������Ҫ�����������ĳ��е���Ŀ�����p��q֮�䲻��ͨ�����0

��������
6 6
1 4
1 2
2 3
3 4
5 4
5 6
1 6

�������
2
*/
#include<iostream>
#include<memory.h> 
using namespace std;
const int MAXV = 20;
int visited[MAXV] = {0};


typedef struct 
{
	int no;
}VertexType;

typedef struct
{
	int edges[MAXV][MAXV];
	int n;
	int e;
	VertexType vesx[MAXV];
}MGraph;

void search(MGraph g, int p, int q, int path)
{
	 int queue[MAXV];
	 int front = 0;
	 int rear = 0;
	 rear = (rear + 1) % MAXV;
	 queue[rear] = p;
	 visited[p] = 1;
	 path ++;
	 while(rear != front)
	 {
	 	front = (front + 1) % MAXV;
	 	int w;
	 	w = queue[front];
	 	int i;
	 	for(i = 1; i <= g.n; i++)
	 	{
	 		if(visited[i] == 0 && g.edges[w][i] != 0)
	 		{
	 			rear = (rear + 1) % MAXV;
	 			queue[rear] = i;
	 			visited[i] = 1;
	 			path ++;
	 			if(i == q)
	 			{
	 				cout<<path - 1;
	 				return ;
				 }
			 }
		 }
	 } 
}

int main()
{
	MGraph g;
	int i;
	int j;
	memset(g.edges, 0, sizeof(g.edges));
	
	cin>>g.n;
	cin>>g.e;
	for(i = 1; i <= g.e; i++)
	{
		int x;
		int y;
		cin>>x;
		cin>>y;
		g.edges[x][y] = 1;
		g.edges[y][x] = 1;
	}
	
	for(i = 1; i <= g.n; i++)
	{
		for(j = 1; j <= g.n; j++)
		{
			cout<<g.edges[i][j]<<" ";
		}
		cout<<endl;
	}
	int p;//��ʼ�ص� 
	int q;//Ŀ�ĵص�
	cin>>p;
	cin>>q; 
	int path = 0; 
	search(g, p, q, path);
	return 0; 
}

/* 
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<vector>
#include<stack>
using namespace std;
typedef long ll;

int m[100][100];
int n, k, p, q;
bool vis[100];
int d[100];
int inf = 0x3f3f3f3f;

void solve()
{
	while (true)
	{
		int v = -1;
		for (int i = 1; i <= n; i++)
		if(!vis[i] && (v == -1 || d[i] < d[v])) v = i;

		if (v == -1) break;
		vis[v] = true;
		for (int i = 1; i <= n; i++)
			d[i] = min(d[i], d[v] + m[v][i]);
	}
}

int main()
{
	memset(d, 0x3f, sizeof(d));
	memset(m, 0x3f, sizeof(m));
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		m[a][b] = 1;
		m[b][a] = 1;
	}
	
	cin >> p >> q;
	d[p] = 0;
	solve();
	if (d[q] != inf)
		cout << d[q] - 1;
	else
		cout << "0";

}
*/
