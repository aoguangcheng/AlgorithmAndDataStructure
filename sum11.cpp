#include<stdio.h>
int add(int a, int b)
{
	int s;
	s = a + b;
	return s;
}
 int main()
 {
 	int x, y;
 	int sum;
	scanf("%d%d", &x, &y);
    sum = add(x,y);
	printf("%d", sum); 	
 }
