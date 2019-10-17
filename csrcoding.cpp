/*
�������ݣ�
10
5.0
0.1
5 5.11 5.0 5.11 4.9 4.99 5.2 4.8 4.9 5.0
*/
#include<stdio.h>
#include<math.h>
#define N 20

void input(int n, double A[])
{
	for(int i = 0; i < n; i++)
	{
		scanf("%lf", &A[i]);
	}
}

double average(int n, double A[])
{
	double sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum = sum + A[i];
	}
	return sum / n;
}

double variance(int n, double A[], int ave)
{
	double sum = 0;
	for(int i = 0; i <n; i++)
	{
		sum = sum + (A[i] - ave) * (A[i] - ave);
	}
	return sqrt(sum / (n - 1));
}

int main()
{
	double A[N];
	printf("�����׼���Ƿ���֪��Y or N\n");
	char flag;
	scanf("%c", &flag);
	if(flag == 'Y')
	{
		int n;
		printf("�������������ݵĸ�����");
		scanf("%d", &n);
		printf("����������ľ�ֵ�ļ�������\n");
		double u;
		scanf("%lf", &u);
		printf("����������ı�ע�");
		double stand;
		scanf("%lf", &stand);
		printf("������%d���������ݣ�\n", n);
		input(n, A);
		double ave;
		double standard;
		ave = average(n, A);
		standard = variance(n, A, ave);
		printf("average = %lf\n", ave);
		printf("��׼��Ϊ %lf\n", standard);
		printf("u������Ϊ %lf\n", (ave - u) * sqrt(n) / stand);
	}
	else
	{
		int n;
		printf("�������������ݵĸ�����");
		scanf("%d", &n);
		printf("����������ľ�ֵ�ļ�������\n");
		double u;
		scanf("%lf", &u);
		//		printf("����������ı�ע�");
		//		double stand;
		//		scanf("%lf", &stand);
		printf("������%d���������ݣ�\n", n);
		input(n, A);
		double ave;
		double standard;
		ave = average(n, A);
		standard = variance(n, A, ave);
		printf("average = %lf\n", ave);
		printf("standard = %lf\n", standard);
		printf("t������Ϊ %lf\n", (ave - u) * sqrt(n) / standard);
	}
	return 0;
}
