/*
78.圣诞广场 (15分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
Angel最近无聊，去了圣诞岛(CX *^_^*)，他喜欢无目的的乱逛，当然，他不会轻易地回头。Angel想

去广场，那么，他什么时候才能到呢？你已经得到了CX的地图，地图上有N(N <= 100)个交叉路口，交

叉路口之间有马路相连接(不超过1000条马路)。因为CX的人遵循奇怪的规则，道路都是单向的，不同

的道路之间有一定的距离，我们假设Angel所在的地点为点1，广场所在点为N。假设Angel走一单位距

离需要一单位时间。问Angel最早和最迟什么时候到达广场？ 
输入描述
本题有多组数据，第一行N, M，M是边的数量,以后M行，每行3个整数X, Y, Weight，代表一条从X

城市到Y城市，长度为Wweight的边。

输出描述
每组数据，第一行是最少时间，第二行是最迟时间，要是可怜的Angel可能永远到不了广场，输

出一行Never。

输入样例
5 5
1 2 1
1 4 10
2 3 1
3 4 1
4 5 1

输出样例
4
11

*/
#include<iostream>   
  
using namespace std;   
  
  
class Path   
{   
private:   
    int X,Y,Weight;   
  
public:   
    void Input()   
    {   
        cin>>X;   
        cin>>Y;   
        cin>>Weight;   
    }   
       
    int GetX() const {return X;}   
    int GetY() const {return Y;}   
    int GetWeight() const {return Weight;}   
};   
  
void Travel(Path* p,int state,int end,int M,int &sum,int& shortest,int& longest,int& path)   
{   
    //Path* p1=p;   
    for(int i=0;i<M;i++)   
    {   
           
        if(state==(p+i)->GetX())   
        {   
            sum+=(p+i)->GetWeight();   
            //cout<<(p+i)->GetX()<<" "<<(p+i)->GetY()<<" "<<(p+i)->GetWeight()<<" "<<sum<<endl;   
            if(end==(p+i)->GetY())   
            {   
                path++;   
                if(sum<shortest)   
                    shortest=sum;   
                if(sum>longest)   
                    longest=sum;   
                //cout<<shortest<<endl;   
                //cout<<longest<<endl;   
            }   
            else  
            {                  
                Travel(p,(p+i)->GetY(),end,M,sum,shortest,longest,path);   
                sum-=(p+i)->GetWeight();   
            }   
               
        }   
  
    }   
}   
  
int main()   
{   
    int start,end,path,M;   
    start=1;//默认起点为1   
    path=0;   
  
    cin>>end;   
    cin>>M;   
  
    Path* p=new Path[M];   
  
    for(int i=0;i<M;i++)   
        p[i].Input();   
  
    int shortest,longest,sum;   
    longest=0;   
    shortest=0;   
    sum=0;   
  
    for(int i=0;i<M;i++)   
        shortest+=p[i].GetWeight();   
  
    Travel(p,1,end,M,sum,shortest,longest,path);   
  
    if(path==0)   
        cout<<"Never"<<endl;   
    else  
    {   
        cout<<shortest<<endl;   
        cout<<longest-1<<endl;   
    }   
    delete[] p;   
    return 0;   
}
