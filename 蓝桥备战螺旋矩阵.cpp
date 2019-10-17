/*
ÂÝÐý¾ØÕó 
*/

#include <cstdio>
#include <iostream>
using namespace std;
 
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a[100][100];
		int sum,k=0,i,j;
		sum = n*n;
		while(k<=n/2)
		{
			for(i = k; i <= n-k-1; i++)
				a[k][i] = sum--;
			for(i=k+1; i<=n-k-1; i++)
				a[i][n-k-1]=sum--;
			for(i = n-k-2; i>=k; i--)
				a[n-k-1][i] = sum--;
			for(i =n-k-2; i>=k+1;i--)
				a[i][k] = sum--;
			k++;
		} 
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				if(j==0)
				printf("%d",a[i][j]);
				else
				printf("%5d",a[i][j]);
			}
			cout<<endl;
		}
		
	}
	return 0;
}
