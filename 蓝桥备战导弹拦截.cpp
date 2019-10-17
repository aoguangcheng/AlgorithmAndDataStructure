/*
82.导弹拦截 (15分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
某国为了防御敌国的导弹袭击，研发出一套导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发拦截
炮弹能够到达任意的高度，但是以后每一发拦截炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的多枚导弹来
袭。
输入描述
输入的第一行为导弹的个数n (0<n<10000),接下来的一行为导弹依次飞来的高度h（不大于
30000 的正整数）

输出描述
输出最多拦截的导弹个数。

输入样例
6
5 3 2 4 1 3

输出样例
4

*/ 

#include<cstdio>
#include<cmath>
#include<cstring>
const int qq=1005;
int dp[qq];
int num[qq]; 
int main()
{
    int n;
    while(~scanf("%d",&n)){
        memset(dp,0,sizeof(dp));        // 5 6 7 8 1
        for(int i=0;i<n;++i)
        scanf("%d",&num[i]);
        dp[0]=1;
        int x=0;
        for(int j,i=0;i<n;++i){
            int maxn=0;
            for(j=0;j<i;++j)    //这里利用了递推的原理、 
                if(num[i]<num[j])    //由前面的最长递增子序列推出后面的最长递增子序列、 
                    maxn=maxn>dp[j]?maxn:dp[j];
            dp[i]=maxn+1; 
            if(dp[i]>x)    x=dp[i];    //x记录的是当前的最大值、 
        }
        printf("%d\n",x);
    }
    return 0;
}
