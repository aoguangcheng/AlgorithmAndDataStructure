#include<stdio.h>

int main ()
{
	double price = 1;
	double discount = 0;
	char S[10];
	double sum = 0;
	while(price != 0)
	{
		sum = price * discount * 0.01 + sum;
		scanf("%s %lf %lf", &S, &price, &discount);
	}
	printf("%lf\n", sum);
}