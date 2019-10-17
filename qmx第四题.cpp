#include<stdio.h>
#include<math.h>
//0 0 0 1 1 0 0.5 0.5
//0 0 0 1 1 0 0.25 0.25

float fun1(float p1, float p2, float a1, float a2)
{
	return sqrt((p1 - a1) * (p1 - a1) + (p2 - a2) * (p2 - a2));
}

float fun2(float a, float b, float c)
{
	float p = (a + b + c) / 2;
	return sqrt(p * ( p - a) * (p - b) * (p - c)); 
}

int main()
{
	float a;
	float b;
	float c;
	float a1;
	float a2;
	float b1;
	float b2;
	float c1;
	float c2;
	float p1;
	float p2;
	float pa;
	float pb;
	float pc;
	float sa;
	float sb;
	float sc;
	float s;

	scanf("%f %f %f %f %f %f\n %f %f", &a1, &a2, &b1, &b2, &c1, &c2, &p1, &p2);
	pa = fun1(p1, p2, a1, a2);
	pb = fun1(p1, p2, b1, b2);
	pc = fun1(p1, p2, c1, c2);
	a = fun1(a1, a2, b1, b2);
	b = fun1(b1, b2, c1, c2);
	c = fun1(c1, c2, a1, a2);
	s = fun2(a, b, c);
	sa = fun2(a, pa, pb);
	sb = fun2(b, pb, pc);
	sc = fun2(c, pa, pc);
//	printf("%f %f\n", sa + sb +sc, s);
//	printf("%f\n", sa + sb + sc - s);
	if(sa + sb + sc - s <= 0.00001)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
	return 0;
}