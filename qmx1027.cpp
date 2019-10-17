//输出全排列的方法数 
#include<stdio.h> 

int fun1(int n)
{
	int sum = 1;
	int i;
	for(i = 1; i <= n; i++)
	{
		sum *= i;
	}
	return sum;
}

int  main()
{
	int n ;
	char A[100];
	int B[100] = {0};//字符数组C[]中字符出现的次数 
	char C[100] = {'!'};
	int i;
	int j;
	int count = 0; 
	int sum;
	
	scanf("%d", &n);
	scanf("%s", &A);
	sum = fun1(n);
	for(i = 0; A[i] != '\0'; i++)
	{
		int flag = 0;
		for(j = 0; j < 100; j++)
		{
			if(C[j] == A[i])
			{
				flag = 1;
				B[j] ++;
				break;
			}
		}
		if(flag == 0)
		{
			C[count] = A[i];
			B[count]++;
			count ++;
		}
	}	
	for(i = 0; i < count; i++)
	{
		sum = sum / fun1(B[i]);
	}
	printf("%d", sum);
	return 0;
 } 
