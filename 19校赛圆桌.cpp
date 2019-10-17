#include<iostream>
using namespace std;

int main()
{
	int A[100]; 
	int n;
	cin>>n;
	int j = 0;
	for(j; j < n; j++)
	{
		cin >>A[j];
	}
	j = 0;
	while(j < n)
	{
		int i = 1;
		int sum = 1;
		for(i; i < A[j]; i++)
		{
			sum *= i;
		}
		cout<<sum<<" ";
		j++;
	}
	return 0;
}
