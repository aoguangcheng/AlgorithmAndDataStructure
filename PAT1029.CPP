/*7_This_is_a_test
_hs_s_a_es
abc
ab*/
#include<stdio.h>
#include<string.h>
char A[80];
char B[80];

int f(char D[], char c)
{
	int i = 0;
	while(i <= strlen(D))
	{
		if(c == D[i])
		{
			return 0;
			break;
		}
		i++;
	}
	if(i > strlen(D))
		return 1;
}

int main()
{
	scanf("%s", &A);
	scanf("%s", &B);
	int a = strlen(A);
	int b = strlen(B);
	int i = 0;
	int j = 0;
	int k = 0;
	char C[80];
	while(i <= a)
	{
		if(f(B, A[i]) == 1)
		{
			C[k] = A[i];
			k++;
		}
		i++;
	}
	C[k] = '\0';
	int c = strlen(C);
	i = 0;
	while(i <= c)
	{
		if(C[i]>= 97 && C[i] <= 123)
			C[i] = char(C[i] - 32);
		i++;
	}
	char D[80];
	i = 0;
	j = 0;
	while(i <= strlen(C))
	{
		if(f(D, C[i]) == 1)
		{
			printf("%c", C[i]);
			D[j] = C[i];
			j++;
			D[j] = '\0';
		}
		i++;
	}
	return 0;
}