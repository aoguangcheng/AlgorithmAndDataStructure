/*����Ϊ10�ĵȲ������У��乫����Сֵ�Ƕ��٣�*/

#include<stdio.h>
#define N 10000

int fun2(int n)//�ж�����
{
	for(int i = 2; i < n; i++)
	{
		if(n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

void fun1(int a[])//����������
{
	int i = 1;
	int j;
	for(j = 3; i < N; j++)
	{
		if(fun2(j))
		{
			a[i] = j;
			i++;
		}
	}
}

int fun3(int a[], int m)
{
	for(int i = 0; i < N; i++)

	{
		if(a[i] == m)
			return i;
	}
	return -1;
}

int main()
{
	int a[N];//�洢������
	a[0] = 2;
	fun1(a);
	int i;
	/*for(i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
*/
	for(i  = 0; i < N; i++)//����
	{
		for(int j = 1; j < 1000; j++)//���ƹ���
		{
			int sum = 0;
			for(int k = i; k < N - 1;)
			{
				int m = fun3(a, a[k] + j);
				if(m != -1)
				{
					sum++;
					k = m;
				}
				else
				{
					break;
				}
				if(sum >= 9)
				{
					printf("%d %d", a[i], j);
				
				}
			}
		}
	}
//	return 0;
	return 0;
}