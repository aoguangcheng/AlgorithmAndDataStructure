/*
75.��Խ���� (15��)
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
 ������һ�� m * n ���������������дһ����������һ�������Ҵ��������·������ʹ��·���ķ�����С��·���Ӿ���
�����ĵ�һ�е����ⵥԪ��ʼ���𲽴������󵽴����Ҳ��һ�е����ⵥԪ��ÿһ����ָ��ĳ��Ԫ�������һ�е����ڵ�Ԫ
������ͼ�������Ǻ����б�򣩡�����ĵ�һ�к����һ��ʵ�������ڵģ��������������ǰ�����һ����ŵ�Բ�������棨������Ҫ���� 
·���Ļ�����ָ����·������Խ�����е�Ԫ���е�����֮�͡�
��������
�������һϵ�о���������ÿ�����������ĵ�һ���� m �� n���������������������֮��� m �У�ÿ�а��� n ���Կո�ֿ���
���������ǵ�ǰ�����ֵ��ע������ֵδ���������� 
��������� m ������ n �ķ�Χ�ǣ�1 <=m<=10�� 1<=n<=100������·���ķ���ֵ�������� 30bit ��������ʾ��

�������
���ÿһ�������ҳ�������С��·���������������ÿ�����������������У���һ����·�����������ÿһ�����ڵ��У���
�������Ǹ�·���ķ��á� 
�������ͬһ�������ж�����ͬ�ķ�����С·�������������кŽ�С��һ����

��������
5 6
3 4 1 2 8 6
6 1 8 2 7 4
5 9 3 9 9 5
8 4 1 3 2 6
3 7 2 1 2 3

�������
1 2 1 5 4 5
11
*/

/*
#include<iostream>
#include<malloc.h>
#include<string.h>
using namespace std;
int g[10][100];
int m;
int n;
int minpath = 10000;
int minroute[10000];

void cross(int row, int column, int path, int route[])
{
	if(column == n)
	{
		if(minpath > path)
		{
			minpath = path;
			int k;
			for(k = 0; k < n; k++)
			{
				minroute[k] = route[k];
			}
		}
		else if(minpath == path)
		{
			/*
			char *S1 = (char*)malloc(sizeof(char) * n);
			char *S2 = (char*)malloc(sizeof(char) * n);
			int k;
			for(k = 0; k < n; k++)
			{
				S1[k] = char(minroute[k] + 65);
				S2[k] = char(route[k] + 65);
			}
			if(strcmp(S1, S2) > 0)
			{
				int l; 
				for(l = 0; l < n; l++)
				{
					minroute[l] = route[l];
					minpath = path;
				}
			}
			free(S1);
			free(S2);
			
			if(minroute[0] > route[0])
			{
				minpath = path;
				int k;
				for(k = 0; k < n; k++)
				{
					minroute[k] = route[k];
				}
			}
		}
	}
	else
	{
		if(row == -1)
			{
		row = m - 1;
		}
		if(row == m)
		{
			row = 0;
		}
		route[column] = row;
		int t = 3;
		while(t--)
		{
			switch(t)
			{
				case 3 : cross(row, column + 1, path + g[row][column], route); break;
				case 2 : cross(row - 1, column + 1, path + g[row][column], route); break;
				case 1 : cross(row + 1, column + 1, path + g[row][column], route); break;
			}
		}
	}
}

int main()
{
	cin>>m>>n;
	int i;
	int j;
	
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			cin>>g[i][j];
		}
	}
	int route[1000];
	for(i = 0; i < m; i++)
	{
		cross(i, 0, 0, route);
	}
	for(i = 0; i < n; i++)
	{
		cout<<minroute[i] + 1<<" ";
	}
	cout<<endl<<minpath;
	return 0;
}*/ 
#include<stdio.h>
#include<string.h>
int dp[11][111],path[11][111];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&dp[i][j]);
        for(int j=m-2;j>=0;j--)
            for(int i=0;i<n;i++)
            {
                int temp=i;
                if(dp[(i+1)%n][j+1]<dp[temp][j+1]||dp[(i+1)%n][j+1]==dp[temp][j+1]&&(i+1)%n<temp)
                    temp=(i+1)%n;
                if(dp[(i-1+n)%n][j+1]<dp[temp][j+1]||dp[(i-1+n)%n][j+1]==dp[temp][j+1]&&(i-1+n)%n<temp)
                    temp=(i-1+n)%n;
                dp[i][j]+=dp[temp][j+1];
                path[i][j]=temp;
            }
        int ans=1<<30,k;
        for(int i=0;i<n;i++)
            if(ans>dp[i][0])
            {
                ans=dp[i][0];
                k=i;
            }
        printf("%d",k+1);
        for(int i=0;i<m-1;i++)
        {
            printf(" %d",path[k][i]+1);
            k=path[k][i];
        }
        printf("\n%d\n",ans);
    }
    return 0;
}
