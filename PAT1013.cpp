/*
1013 ������ ��20 point(s)��
�����M����N֮�����е�������M<=N<=10000��
������һ���и��� M �� N������Կո�ָ���
�����ʽ��
������������ÿ 10 ������ռ 1 �У�����Կո�ָ�������ĩ�����ж���ո�
����������

5 27
���������

11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/

#include<stdio.h>
int fun1(int n)
{
	int k;
	for(k = 2; k < n; k++)
	{
		if(n % k == 0)
			return 0 ;
	}
	if(k >= n)
		return 1;
}
int main()
{
	int M;
	int N;
	int i = 0;
	int j = 2;

	scanf("%d %d", &M, &N);
	while(i <= N)
	{
		if(fun1(j) == 1)
		{
			i++;
			if(i >= M && i <= N)
			{
				printf("%d", j);
				if(i != N)
				{
					if((i - M + 1) % 10 == 0)
						printf("\n");
				    else
						printf(" ");
				}
			}
		}
		j++;
	}
	return 0;
}