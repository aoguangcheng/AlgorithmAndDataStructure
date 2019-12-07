/*
问题描述
　　小明有一块空地，他将这块空地划分为 n 行 m 列的小块，每行和每列的长度都为 1。
　　小明选了其中的一些小块空地，种上了草，其他小块仍然保持是空地。
　　这些草长得很快，每个月，草都会向外长出一些，如果一个小块种了草，则它将向自己的上、下、左、右四小块空地扩展，这四小块空地都将变为有草的小块。
　　请告诉小明，k 个月后空地上哪些地方有草。
输入格式
　　输入的第一行包含两个整数 n, m。
　　接下来 n 行，每行包含 m 个字母，表示初始的空地状态，字母之间没有空格。如果为小数点，表示为空地，如果字母为 g，表示种了草。
　　接下来包含一个整数 k。
输出格式
　　输出 n 行，每行包含 m 个字母，表示 k 个月后空地的状态。如果为小数点，表示为空地，如果字母为 g，表示长了草。
样例输入
4 5
.g...
.....
..g..
.....
2
//////////////////////////////
5 5
.....
.....
..g..
.....
.....
1
样例输出
gggg.
gggg.
ggggg
.ggg.
评测用例规模与约定
　　对于 30% 的评测用例，2 <= n, m <= 20。
　　对于 70% 的评测用例，2 <= n, m <= 100。
　　对于所有评测用例，2 <= n, m <= 1000，1 <= k <= 1000。
*/

#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<string.h>
using namespace std;

int main()
{
    int n;
    int m;
    int i;
    int j;
    int k;
    char ch;

    cin>>n;
    cin>>m;
    /*char grass[1000][1000];*/
    char **grass = (char **)malloc(sizeof(char*) * (n + 2));
	for (i = 0; i < n + 2; ++i)
	{
		grass[i] = (char *)malloc(sizeof(char) * (m + 2));
	}
    
    for(i = 1; i < n + 1; i++)
    {
        char *s = (char *)malloc(sizeof(char) * m);
        //char s[1000];
        cin>>s;
        //puts(s);
        for (j = 1; j < m + 1; j ++)
        {
            grass[i][j] = s[j - 1];
        }
    }
    for(i = 0; i < n + 2; i ++)
    {
        grass[i][0] = '.';
        grass[i][m + 1] = '.';
    }
    for(i = 0; i < m + 2; i++)
    {
        grass[0][i] = '.';
        grass[n + 1][i] = '.';
    }
    
    cin>>k;
    while(k--)
    {
        for(i = 1; i < n + 1; i++)
        {
            for(j = 1; j < m + 1; j++)
            {
                if(grass[i][j] == 'g')
                {
                    grass[i-1][j] = 'g';
                    grass[i][j-1] = 'g';
                    if(grass[i][j + 1] != 'g')
                    {
                    	grass[i][j+1] = 'h';
					}
					if(grass[i + 1][j] != 'g')
					{
						grass[i+1][j] = 'h';
					}
					
                }
                else if (grass[i][j] == 'h')
                {
                	grass[i][j] = 'g';
				}
            }
        }
    }
    for ( i = 1; i < n + 1; i++)          
    {
        for ( j = 1; j < m + 1; j++)
        {
            cout<<grass[i][j];
        }
        cout<<endl;
    }
    return 0;
}
