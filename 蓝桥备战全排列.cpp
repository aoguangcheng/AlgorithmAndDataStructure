#include<iostream>
using namespace std;

void fun1(int A[], int k)
{
	int i;
	int temp;
	if(k ==  3)
	{
		for(int i = 0; i < 4; i++)
		{
			cout<<A[i]<<" ";
		}
		cout<<endl; 
	}
	else
	{
		for(i = k; i < 4; i++)
		{
			temp = A[i];
			A[i] = A[k];
			A[k] = temp;
			fun1(A, k + 1);
		}
	}
}

int main()
{
	int A[4] = {1, 2, 3, 4};
	fun1(A, 0);
	return 0;
 } 
