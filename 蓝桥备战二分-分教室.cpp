//

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define fo(i,j,k) for(i=j;i<=k;i++)
using namespace std;
const int z=1000002;
int s[z],n,mid,m,c[z],q[z],h[z];  //c:第i天和第i-1天需要教室数的差值 
struct dan
{
    int d,s,e,f;
}a[z];
bool ok(int r)
{
    int i;bool b=0;
    fo(i,1,n) h[i]=q[i];  //记录改动之前
    memset(q,0,sizeof q);
    fo(i,mid,r)
    {
        c[a[i].s]-=a[i].d;
        c[a[i].e+1]+=a[i].d;
    }    //删除mid之后的订单
    fo(i,1,n)
    {
        q[i]=q[i-1]+c[i];
        if(q[i]>s[i])   //如果在mid之前的订单就需修改，那么b=1
          b=1;
    }
    if(b) return 1;
    else
    {
        fo(i,mid,r)   //恢复
        {
            c[a[i].s]+=a[i].d;
            c[a[i].e+1]-=a[i].d;
        }
        fo(i,1,n)
          q[i]=h[i];
        return 0;
    }
}
int fz(int l,int r)
{
    int i,j;
    while(l<r)
    {
        mid=((l+r)/2)+1;
        if(ok(r))
          r=mid-1;
        else
          l=mid;
    }
    return l;
}
int main()
{
    int i,j,k;
    scanf("%d%d",&n,&m);
    fo(i,1,n)
      scanf("%d",&s[i]);
    fo(i,1,m)
    {
        scanf("%d%d%d",&a[i].d,&a[i].s,&a[i].e);
        a[i].f=i;
        int x=a[i].s,y=a[i].e;
        c[x]+=a[i].d;
        c[y+1]-=a[i].d;
    }
    fo(i,1,n)
      q[i]=q[i-1]+c[i];
    fo(i,1,n) if(q[i]>s[i]) break;
    if(i==n+1)
    {
        printf("0\n");
		return 0;
    }
    printf("%d\n",fz(1,m));
    return 0;
}

