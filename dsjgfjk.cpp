#include<stdio.h>
const int N = 5; 
void build(int *a,int *tag,int n)
{
    if(n==N)
    {
        printf("{");
        for(int i=0;i<N;++i)
        if(tag[i]==1)
        printf("%d",a[i]);
        printf("}");
        printf("\n");
        return ;
    }
    tag[n]=0;//���Ϊ0֮�󣬿�ʼ������һ��
    build(a,tag,n+1);
    tag[n]=1;//���Ϊ1֮�󣬿�ʼ������һ��
    build(a,tag,n+1);
} 
int main()
{
    int a[5];
    for(int i=0;i<N;++i)
    scanf("%d",&a[i]); 
    int tag[N];
    build(a,tag,0);
    return 0;
}
