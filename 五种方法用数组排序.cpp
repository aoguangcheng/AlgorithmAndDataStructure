#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int max, min;
	
 } Date;
 
 int MIN;
 
 int fun1(int a[],int n)
 {
 	int i , max;
    max = MIN = a[0];
    
	for(i = 1; i < n; i++)
    {
	    if(max < a[i])
		max = a[i];
		if(MIN > a[i])
		MIN = a[i];    
	} 
	return (max);
 }
 
 
 int *fun2(int a[], int n)
 {
 	static int b[2];
 	b[0] = b[1] = a[0];
 	int i;
 	for(i = 1; i < n; i++)
 	{
 		if(a[i] > b[0])
 		b[0] = a[i];
		if(a[i] < b[1])
	    b[1] = a[i];	 
	}
	return(b);
 }
 
 
 
 
 Date *fun3(int a[], int n)
 {
 	Date *p;
 	int i;
 	p = (Date * )malloc(sizeof(Date));
 	p->max = p->min = a[0];
 	for(i = 1; i < n; i++)
 	{
 		if(a[i] > p->max)
 		p->max = a[i];
 		if(a[i] < p->min)
 		p->min = a[i];
	 }
	 return(p);
 }
 
 
 
 Date fun4(int a[], int n)
 {
 	Date p;
 	int i;
 	p.max = p.min = a[0];
 	for(i = 1; i < n; i++)
 	{
 		if(a[i] > p.max)
 		p.max = a[i];
 		if(a[i] < p.min)
 		p.min = a[i];
	 }
	 return(p);
 }
 
 
 
 void fun5(int a[], int n, int *p, int *q)
 {
 	int i;
 	*p = *q = a[0];
 	for(i = 1; i < n; i++)
 	{
 		if(*p < a[i])
		*p = a[i];
		if(*q > a[i]) 
		*q= a[i];
	 }
 }
 
 
 
 int main()
 {
 	int a[10] = {1,3,9,8,4,2,5,0,7,6},max, *p;
 	Date *q;
 	Date z;
 	int x, y;
 	
 	max = fun1(a, 10);
 	printf("max = %d min = %d\n", max, MIN);
 	
 	p = fun2(a, 10);
 	printf("max = %d min = %d\n", p[0], p[1]);
 	
 	q = fun3(a, 10);
 	printf("max = %d min = %d\n", q->max, q->min);
 	
 	z = fun4(a,10);
 	printf("max = %d min = %d\n", z.max, z.min);
 	
 	fun5(a, 10, &x, &y);
 	printf("max = %d min = %d\n", x, y);
 }
