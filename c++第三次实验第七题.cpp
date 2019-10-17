//main.cpp
//敖光成2017105909 
/*对数组进行排序、求最大值和求元素和
的算法都编写为函数模板，采用相关数据进行测试。
*/
#include<iostream> 
using namespace std;

template <class ElemType> 
void sort(ElemType elem[],int size){  
    for(int i=0;i<size;i++){  
    int p=i;  
    for(int j=i;j<size;j++)  
    if(elem[p]>elem[j])  
        p=j;  
    int t=elem[i];  
    elem[i]=elem[p];  
    elem[p]=t;  
    }  
} 

template<class ElemType>
void Show(ElemType elem[], int size)
{
    cout<<"排序后的数组为："<<endl;
	for(int i=0;i<size;i++)
	cout<<" "<<elem[i]<<" "; 
	
 } 
template<class ElemType>  
ElemType Sum(ElemType elem[],int size )
{  
    ElemType sum=0;  
    for(int i=0;i<size;i++){  
        cout<<elem[i]<<"\t";  
        sum+=elem[i];  
    }
    return sum;
}  
template<class ElemType>  
ElemType Max(ElemType elem[],int size){  
    ElemType max=elem[0];  
    int j;  
    for(j=1;j<size;j++){  
    if(max<elem[j])  
        max=elem[j];  
    else  
        continue;  
    }  
    return max; 
}  

int main()
{  	
    //int size;
	//cin>>size>>endl;
    int elem[]={5,1,3,4,9,7,6,2,8}; 
	//for(int i=0;i<size;i++)
	//cin<<" "<<elem[i]<<"";       
    sort(elem,8);  
    Show(elem,8);  
    Max(elem,8);
    
    return 0 ;

}  

/*template <class ElemType>
ElemType Max(ElemType elem[], int n);	// 返回数组元素的最大值

template <class ElemType>
ElemType Sum(ElemType elem[], int n);	// 返回数组元素之和

template <class ElemType>
void Sort(ElemType elem[], int n);		// 排序

template <class ElemType>
void Show(ElemType elem[], int n);		// 显示数组所有元素*/
