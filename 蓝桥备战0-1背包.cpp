/*

给定n种物品和一个背包，物品i的重量是Wi，其价值为Vi，问如何选择装入背包的物品，使得装入背包的物品的总价值最大？
在选择装入背包的物品时，对每种物品i只能有两种选择，装入或者不装入，不能装入多次，也不能部分装入。

输入描述


第一行输入物品的个数n。
第二行输入物品的重量序列w。(中间有空格）
第三行输入物品的价值序列v。（中间有空格）
第四行输入背包容量c。


输出描述


第一行输出装入背包的物品。（用0表示未和1表示装入，中间无空格）
第二行输出最大价值。


输入样例


3
3 4 5
4 5 6
10


输出样例


011
11

*/


#include <iostream>
#include <cstdio>
using namespace std;
int dp[1000][1000];
int w[1000], v[1000];
int a[1000];
int main(){
    int m, c;
    cin >> m;
    for(int i = 1; i <= m; i++)
        cin >> w[i]; 
    for(int i = 1; i <= m; i++)
        cin >> v[i];
        
        cin>>c;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j <= c; j++){   //背包可以为0
            if(i != 1)
                dp[i][j] = dp[i - 1][j];
            if(j >= w[i])
                dp[i][j] = (dp[i][j] > dp[i - 1][j - w[i]] + v[i] ? dp[i][j] : dp[i - 1][j - w[i]] + v[i]);
        }
    }  

    int b = c;
    for(int i = m; i >= 1; i--){
        if(dp[i][b] > dp[i - 1][b]){
            a[i] = 1;
            b -= w[i];
        }  
    }
    for(int i = 1; i <= m; i++)
    {
       	cout << a[i];
	}
	cout<<endl;
    cout << dp[m][c];
    return 0;
}
