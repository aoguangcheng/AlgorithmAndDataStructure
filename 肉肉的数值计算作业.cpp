#include<stdio.h>
#include<math.h>

void fun(double d)
{
	int i = 1;
	double sum = 0;
	double a = 1;
	double b = 1;
	double c = 1;
	while(fabs(c) >= d)
	{
		sum = sum + c;
		i++;
		b = b + 2;
		if(i % 2 == 0)
		{
			c = (a / b) * (-1);
		}
		else
		{
			c = a / b;
		}
//		printf("%.30lf\n", c);
	}
	printf("���� %d ��\n", i);
	printf("����ֵΪ�� %.16lf\n", sum * 4);
}

int main ()
{
	double e = 0.0001;
	printf("����Ϊexp��-4����\n");
	fun(e);
	double f = 0.00000001;
	printf("\n����Ϊexp��-8����\n");
	fun(f);
	return 0;
}