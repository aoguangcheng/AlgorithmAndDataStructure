/*
103.用户品牌 (15分)
C时间限制：1 毫秒 |  C内存限制：3000 Kb
题目内容：
 馅饼同学是一个在百度工作，做用户请求（query）分析的同学，他在用户请求中经常会遇到一些很奇葩的词汇。在比方说
“johnsonjohnson”、“duckduck”，这些词汇虽然看起来是一些词汇的单纯重复，但是往往都是一些特殊品牌的词汇，不能被
拆分开。为了侦测出这种词的存在，你今天需要完成我给出的这个任务——“找出用户请求中循环节最多的子串”。
输入描述
输入数据包括多组，每组为一个全部由小写字母组成的不含空格的用户请求（字符串），占一行。用户请求的长度不大于
100,000。

输出描述
对于每组输入，输出这组用户请求中循环节最多的子串。如果一个用户请求中有两个循环节数相同的子串，请选择那个字典序最小
的。

输入样例
duckduckgo

输出样例
duckduck
*/
#include<math.h>
#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100010;
const int inf=5000000;
int w[maxn],wa[maxn],wb[maxn],wv[maxn];
int sa[maxn],rank[maxn],height[maxn];
int a[maxn],f[maxn][20],n,ft[maxn],len[maxn];
int num;
char s[maxn];
int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for (i=0; i<m; i++) w[i]=0;
    for (i=0; i<n; i++) w[x[i]=r[i]]++;
    for (i=1; i<m; i++) w[i]+=w[i-1];
    for (i=n-1; i>=0; i--) sa[--w[x[i]]]=i;
    for (p=1,j=1; p<n; m=p,j*=2)
    {
        for (p=0,i=n-j; i<n; i++) y[p++]=i;
        for (i=0; i<n; i++) if (sa[i]>=j) y[p++]=sa[i]-j;
        for (i=0; i<m; i++) w[i]=0;
        for (i=0; i<n; i++) w[wv[i]=x[y[i]]]++;
        for (i=1; i<m; i++) w[i]+=w[i-1];
        for (i=n-1; i>=0; i--) sa[--w[wv[i]]]=y[i];
        for (t=x,x=y,y=t,x[sa[0]]=0,p=1,i=1; i<n; i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return;
}
void cal(int *r,int *sa,int n)
{
    int i,j,k=0;
    for (i=1; i<=n; i++) rank[sa[i]]=i;
    for (i=0; i<n; height[rank[i++]]=k)
        for (k?k--:0,j=sa[rank[i]-1]; r[i+k]==r[j+k]; k++);
    return;
}
int nmin(int a,int b)
{
    return a<b?a:b;
}
void rmq(int n)
{
    int i,j;
    for (i=1; i<=n; i++)
        f[i][0]=height[i];
    for (j=1; j<20; j++)
        for (i=1; i+(1<<j)-1<=n; i++)
            f[i][j]=nmin(f[i][j-1],f[i+(1<<j-1)][j-1]);
    return;
}
int lcp(int a,int b)
{
    int x=rank[a],y=rank[b];
    if (x>y)
    {
        int t=x;
        x=y;
        y=t;
    }
    x++;
    int t=ft[y-x+1];
    return nmin(f[x][t],f[y-(1<<t)+1][t]);
}
int main()
{
    int cas=1;
    int i;
    char x;
    for (i=0; i<maxn; i++) ft[i]=int(double(log(i*1.00))/log(2.00));
    int y = 1; 
    while (y--)
    {
    	gets(s);
        n=strlen(s);
        for (i=0; i<n; i++)  a[i]=(int)s[i];
        a[n]=0;
        da(a,sa,n+1,128);
        cal(a,sa,n);
        rmq(n);
        int k,max=0,r=0,t;
        num=0;
        for(int l=1; l<n; l++)//枚举长度
            for(int i=0; i+l<n; i+=l)
            {
                k=lcp(i,i+l);
                r=k/l+1;//注意为什么是k/l+1
                t=i-(l-k%l);
                if (t>=0&&k%l!=0)
                    if (lcp(t,t+l)>=k) r++;
                if (r>max)
                {
                    num=0;
                    len[++num]=l;
                    max=r;
                }
                else
                if(r==max)
                {
                    len[++num]=l;
                }
                //printf("l=%d  r=%d  i=%d  i+l=%d/n",l,r,i,i+l);
            }
       // printf("%d/n",max);
       int start,l;
        for(int i=1;i<n;++i)//sa应从1开始，因为sa[0]是0
        {
            int ts=sa[i];//枚举这个开始
            for(int j=1;j<=num;++j)
            {
                int tl=len[j];
                if(lcp(ts,ts+tl)>=(max-1)*tl)
                {
                    start=ts;
                    l=tl*max;
                    i=n;
                    break;
                }
            }
        }
        for (int i = 0; i < l; i++) printf("%c", s[start+ i]);
        cout<<endl;
    }
    return 0;
}
