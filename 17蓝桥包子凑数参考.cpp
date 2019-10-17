#include <bits/stdc++.h>
using namespace std;

bool judge(int x,int y)
{
    int t;
    while(y>0)
    {
        t=x%y;
        x=y;
        y=t;
    }
    if(x==1)
        return true;
    return false;
}

int a[110],n;
bool dp[10010];
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    int  flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(judge(a[i],a[j]))
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
    }
    if(flag!=1)
    {
        printf("INF\n");
        return 0;
    }
    dp[0]=1;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j+a[i]<10000; j++)
            if(dp[j])
                dp[j+a[i]]=1;
    }
    int ans=0;
    for(int i=0; i<10000; i++)
    {
        if(dp[i]!=1)
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}
