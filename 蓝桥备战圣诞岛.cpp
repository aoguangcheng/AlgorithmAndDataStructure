/*
78.ʥ���㳡 (15��)
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
Angel������ģ�ȥ��ʥ����(CX *^_^*)����ϲ����Ŀ�ĵ��ҹ䣬��Ȼ�����������׵ػ�ͷ��Angel��

ȥ�㳡����ô����ʲôʱ����ܵ��أ����Ѿ��õ���CX�ĵ�ͼ����ͼ����N(N <= 100)������·�ڣ���

��·��֮������·������(������1000����·)����ΪCX������ѭ��ֵĹ��򣬵�·���ǵ���ģ���ͬ

�ĵ�·֮����һ���ľ��룬���Ǽ���Angel���ڵĵص�Ϊ��1���㳡���ڵ�ΪN������Angel��һ��λ��

����Ҫһ��λʱ�䡣��Angel��������ʲôʱ�򵽴�㳡�� 
��������
�����ж������ݣ���һ��N, M��M�Ǳߵ�����,�Ժ�M�У�ÿ��3������X, Y, Weight������һ����X

���е�Y���У�����ΪWweight�ıߡ�

�������
ÿ�����ݣ���һ��������ʱ�䣬�ڶ��������ʱ�䣬Ҫ�ǿ�����Angel������Զ�����˹㳡����

��һ��Never��

��������
5 5
1 2 1
1 4 10
2 3 1
3 4 1
4 5 1

�������
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
    start=1;//Ĭ�����Ϊ1   
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
