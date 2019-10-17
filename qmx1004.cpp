#include<stdio.h>
#include<string.h>

int fun3(int n)
{
	int sum = 1;
	if(n == 0)
	{
		sum = 1;
	}
	else
	{	while(n > 0)
		{
			sum = sum * 2;
			n--;
		}
	}
	return sum;
}

void fun1(char S[])
{
	int n = strlen(S);	
	int i = n - 1;
	int j;
	int sum = 0;
	for(i, j = 0; S[i] != '='; i--, j++)
	{
		sum = sum + (S[i] - 48) * fun3(j);
	}
	printf("%d", sum);
}

void fun2(char S[])
{
	int n = strlen(S);
	int i = n - 1;
	int sum = 0;
	int j = 1;
	while(S[i] != '+')
	{
		sum = sum + j * (S[i] - 48);
		j = j * 10;
		i--;
	}
	int A;
	i = 9;
	int count = 0;
	j = 1;
	while(sum != 0)
	{
		A = sum % 2;
		sum = sum / 2;
		count = A * j + count;
		j = j * 10;
		i--;
	}
/*	for(j = 10 - count; j < 10; j++)
	{
		printf("%d", A[j]);
	}*/
	printf("%d", count);
}

int main()
{
	char S[10];
	gets(S);
	if(S[0] == '=') 
	{
		fun1(S);
	}
	else
	{
		fun2(S);
	}
	return 0;
}
