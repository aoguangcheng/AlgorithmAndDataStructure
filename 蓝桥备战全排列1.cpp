/*
76.������� (15��)
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
���ַ��������֣���ĸ�����ţ�����ȫ���У���ͳ��ȫ���е�����
��������
����һ���ַ���

�������
����ַ�����ȫ���У�ÿ�����ռһ�У����һ�����ȫ���еĸ���

��������
123

�������
123
132
213
231
312
321
6
 

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int count = 0;
void fun1(char S[], int i, int len)
{
	if(i == len - 1)
	{
		int k;
		for(k = 0; k < len; k++)
		{
			cout<<S[k];
		}
		count++;
		cout<<endl;
	}
	else
	{
		int j;
		for(j = i; j < len; j++)
		{
			swap(S[j], S[i]);
			fun1(S, i + 1, len);
			swap(S[i], S[j]);
		}
	}
}

int main()
{
	char S[100];
	cin>>S;
	int len = strlen(S);
	fun1(S, 0, len);
	cout<<count;
	return 0;
 } 
*/
#include <cstdio>  
#include <cstring>  
#include <algorithm>
#include <iostream>  
 using namespace std;  
 int sum=0;  
 string s[105];
 string str;
   
 void swap(int a,int b)  {  
     char temp;
     temp = str[a];
     str[a] = str[b];
     str[b] = temp;  
 }  
   
 bool isSwap(int k, int m)  {  
     for(int i=k;i<m;i++)  
     if(str[m]==str[i])  
         return false;  
     return true;  
 }  
   
 void Perm(int k, int m)  {  
     if(k==m){  
        // cout<<s<<endl;  
         s[sum++] = str;
     } else {  
         for(int i=k;i<=m;i++){  
             if(isSwap(k,i)){  
                 swap(k,i);  
                 Perm(k+1,m);  
                 swap(k,i);  
             }     
         }  
     }  
 }  
   
 int main(){   
     while(cin>>str){  
         sum=0;  
         int len=str.length();  
         Perm(0,len-1); 
         sort(s,s+sum);
         for(int i=0;i<sum;i++)
             cout<<s[i]<<endl; 
         cout<<sum<<endl;      
     }  
     return 0;  
 } 

