#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	int a[100][26];
	int i,j,k,p,n,length,sum,b[100]={0};
	cin>>n;
	for(p=0;p<n;p++){
		cin>>s;
		sum=0;
		length = s.length();
		for(i=1;i<=26;i++)
			a[1][i]=1;
		for(i=2;i<=length;i++)
			for(j=1;j<=26;j++){
				a[i][j]=0;
				if(26-j>=i-1){
					for(k=j+1;k<=26;k++)
						a[i][j]+=a[i-1][k];
				}
			}
			for(i=1;i<length;i++)
				for(j=1;j<=26;j++)
					sum+=a[i][j];
				for(i=1;i<=s[0]-'a';i++)
					sum+=a[length][i];
				for(i=1;i<length;i++)
					for(j=s[i-1]-'a'+1;j<s[i]-'a';j++)
						sum+=a[length-i][j];
			b[p]=sum+1;
	}   
	for(p=0;p<n;p++)
		  cout<<b[p]<<endl;
	return 0;		
}


 
