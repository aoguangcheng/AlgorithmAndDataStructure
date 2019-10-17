//main.cpp
//敖光成2017105909 
/*编写一个使用数组类模板Array对数组进行排序、
求最大值和求元素和的程序，并采用相关数据进行测试。*/

#include<iostream>

using namespace std;

template<class ElemType>

class ArrayAlg{

private:

ElemType *elem;

int size;

public:

ArrayAlg(int a[],int sz):elem(a),size(sz){}
static ElemType Max(ElemType elem[],int size);
static ElemType Sum(ElemType elem[],int size);
static void Sort(ElemType elem[],int size);
static void Show(ElemType elem[],int size);
//static void Creat(ElemType elem[],int size);

};

/*template <class ElemType>
void ArrayAlg<ElemType>::Create(ElemType elem[],int size){
cin>>size;
for(int i = 0; i <= size - 1; i++){
cin>>elem[i];
}
}*/

template <class ElemType>
ElemType ArrayAlg<ElemType>::Max(ElemType elem[],int size)
{
	ElemType max=elem[0];
    for(int i=1;i<size;i++)
    {
    	if(max<elem[i])
        max=elem[i];
    }

    return max;

}

 

template <class ElemType>
ElemType ArrayAlg<ElemType>::Sum(ElemType elem[],int size)
{   
   ElemType sum=0;
   for(int i=0;i<size;i++)
   {
   	   sum+=elem[i];
   }
    return sum;
}

 

template<class ElemType>
void ArrayAlg<ElemType>::Sort(ElemType elem[],int size)
{
	for(int i=0;i<size-1;i++)
    {
    	for(int j=0;j<size-i;j++)
	       if(elem[j]>elem[j+1])
           {   int tem;
               tem=elem[j];
               elem[j]=elem[j+1];
               elem[j+1]=tem;
			   }
	}

}

template <class ElemType>
void ArrayAlg<ElemType>::Show(ElemType elem[],int size)
{
	for(int i=0;i<size;i++)
        cout<<" "<<elem[i]<<" ";
        cout<<endl;
}

int main()
{
	int a[]={1,2,3,4,5,4,3,2,1,0};
    ArrayAlg<int>obj(a,10);
    cout<<"原数组各元素的值:";
    obj.Show(a,10);
    cout<<"最大值为"<<obj.Max(a,10)<<endl;
    cout<<"元素之和为"<<obj.Sum(a,10)<<endl;
    obj.Sort(a,10);
    cout << "排序后数组各元素的值:";
    obj.Show(a,10);
}
