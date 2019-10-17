#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int n = 10;
	sort(a, a +n);
	for(int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}