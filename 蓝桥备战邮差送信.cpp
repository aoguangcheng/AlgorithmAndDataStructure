/*
107.邮差送信 (15分)
C时间限制：1 毫秒 |  C内存限制：3000 Kb
题目内容：
 有一个邮递员要在n个城市之间来回送信。但有的城市之间有大路相连而有的没有路。
现在要由一个城市到另一个城市送信，中途最少要经过多少个其它的城市呢？
输入描述
第一行是n,k(1<=n<=10000, 1<=k<=20000)，接下来就是k行。这k行每行有两个数a,b(1<=a,b<= n)，表示城市a和b之间有
大路k行以后就是两个数p和q。

输出描述
输出从城市p到城市q之间最少要经过的其它的城市的数目。如果p和q之间不连通则输出0

输入样例
6 6
1 4
1 2
2 3
3 4
5 4
5 6
1 6

输出样例
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
	int p;//起始地点 
	int q;//目的地点
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
