/*
87.Ǯ����� (15��)
Cʱ�����ƣ�3 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
�����㹻���1��2��5��ֵ��Ǯ�ң�����һ��Ǯ��n�����һ������ʹ�ܹ���������е���ϣ�
��������
Ǯ��N

�������
���е�������ĸ���

��������
20

�������
29

*/ 
/*
#include<stdio.h>

int main()
{
	int A[100];
	A[0] = 0;
	A[1] = 1;
	A[2] = 2;
	A[3] = 2;
	A[4] = 3;
	A[5] = 4;
	int n;
	
	scanf("%d", &n);
	if(n <= 5)
	{
		printf("%d", A[n]);
		return 0;
	}
	int i = 6;
	while(i <= n)
	{
		A[i] = A[i - 1] + A[i - 2] + A[i - 5];
//		printf("%d\n", A[i]);
		i++;
	}
	printf("%d", A[n]);
	return 0;
}
*/
#include<stdio.h>

int main()
{
	int i;
	int j;
	int k;
	
	int n;
	int sum = 0;
	scanf("%d", &n);
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= n / 2; j++)
		{
			for(k = 0; k <= n / 5; k++)
			{
				if(i + j * 2 + k * 5 == n)
				{
					sum ++;
				}
			}
		}
	}
	printf("%d", sum);
	return 0;
}
