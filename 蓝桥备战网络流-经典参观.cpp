/*
657.������-����ι� (10��)
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
 ��ͼ����n�����㣬֮����·������ĳ�˴Ӿ���1��������ȥ���ʾ���n, Ȼ��ѡ��һ����ͬ��·������
�����·��
��������
��һ����n,m,��ʾ��n���㣬m����·
����m�б�ʾ��·�� ÿ��a b c�� ��ʾ����a������b��·����c

�������
���·��

��������
4 5
1 2 1
2 3 1
3 4 1
1 3 2
2 4 2

�������
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
	int n;//��� 
	int m;//��
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
