/*
75.穿越矩阵 (15分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
 现在有一个 m * n 的整数矩阵，请你编写一个程序计算出一条从左到右穿过矩阵的路径，并使此路径的费用最小。路径从矩阵
的左侧的第一列的任意单元格开始，逐步穿过矩阵到达最右侧的一列的任意单元格。每一步是指从某单元格进入它一列的相邻单元
格（如下图，可以是横向或斜向）。矩阵的第一行和最后一行实际是相邻的，你可以想象矩阵是包裹在一个横放的圆柱体外面（这点很重要）。 
路径的花费是指这条路径所穿越的所有单元格中的数字之和。
输入描述
输入包括一系列矩阵描述。每个矩阵描述的第一行是 m 和 n，即矩阵的行数和列数；之后的 m 行，每行包括 n 个以空格分开的
整数，则是当前矩阵的值，注意矩阵的值未必是正数。 
矩阵的行数 m 和列数 n 的范围是：1 <=m<=10、 1<=n<=100；所有路径的费用值都可以用 30bit 的整数表示。

输出描述
针对每一个矩阵，找出费用最小的路径，并将其输出。每个矩阵的输出包括两行，第一行是路径本身，即输出每一步所在的行，第
二行则是该路径的费用。 
如果对于同一个矩阵有多条不同的费用最小路径，则输出左端行号较小的一条。

输入样例
5 6
3 4 1 2 8 6
6 1 8 2 7 4
5 9 3 9 9 5
8 4 1 3 2 6
3 7 2 1 2 3

输出样例
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
