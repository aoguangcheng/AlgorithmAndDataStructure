/*
67.ȡʯͷ (15��)
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
��һ��ʯ�ӣ�A��B������������ȡ��ʯ�ӣ�ÿ��ȡ����ʯ����Ŀֻ��Ϊ1��3��7��8�����һöʯ��˭ȡ�������䷽��
A,B���˶��㹻��������������������жϡ��ָ���һ����Ŀ��ʯ�ӣ�A��ȡʯ�ӣ�����A����������Ӯ��Ӯ��1��ʾ��
����0��ʾ.
��������
��һ��Ϊһ������n(0< n <=100),��ʾ��n�֣�������n��ÿ����һ����������ʾ��Ӧ�ľ��ṩ��ʯ������������
10000����

�������
������A��Ӧ��n����Ӯ���䣬Ӯ���1�������0.

��������
3
1
3
10

�������
0
0
1

*/
#include<stdio.h>

void fun()
{
	int n;
	int A[10000];
	scanf("%d", &n);
	A[1] = 0;
	A[2] = 1;
	A[3] = 0;
	A[4] = 1;
	A[5] = 0;
	A[6] = 1;
	A[7] = 0;
	A[8] = 1;
	int i = 9;
	for(i; i <= n; i++)
	{
		A[i] = !(A[i - 1] && A[i - 3] && A[i - 7] && A[i - 8]);
	}
	printf("%d", A[n]);
}

int main()
{
	int n;
	int i;
	
	scanf("%d", &n);
	i = 0;
	while(i < n)
	{
		fun();
		printf("\n");
		i ++;
	}
} 
/*
#include<stdio.h>

void fun1()
{
	int n;
	int i = 0;
	int j = 1;
	scanf("%d", &n);
	if(n % 2 == 0)
	{
		printf("%d", j);
	}
	else
	{
		printf("%d", i);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	n--;
	while(n--)
	{
		fun1();
		printf("\n");
	}
	fun1();
	return 0;
}
#include<stdio.h>
int fun1(int n)
{
	int i;
	int j;
	int k;
	int l;
	int flag = 0;
	for(i = 0; i <= n; i++)
	{
		for(j = 0; i <= n / 3; j++)
		{
			for(k = 0; k <= n / 7; k++)
			{
				for(l = 0; l <= n / 8; l++)
				{
					if(i + j * 3 + k * 7 + l * 8 == n)
					{
						if((i + j + k + l) % 2 == 0)
						{
							flag = 1;
						}
					}
				}
			}
		}
	}
	return flag;
}

int main()
{
	int n;
	scanf("%d", &n);
	int A[20];
	int i = 1;
	while(i <= n)
	{
		scanf("%d", &A[i]);
		i++;
	}
	i = 1;
	while(i < n)
	{
		printf("%d\n", fun1(A[i]));
		i++;
	}
	printf("%d", fun1(A[i]));
	return 0;
	
}
*/
