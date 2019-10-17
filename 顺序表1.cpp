/*输入n个整数构成顺序表，然后输出其奇数位置上的元素。
 输入描述
 先输入n,随后是n个元素。
*/ 
#include <stdio.h>
#define MAXSIZE 100
typedef struct
{
	int elem[MAXSIZE];
	int last;
}Seplist;
void creat(Seplist &L)
{
	int n,i=0;
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &L.elem[i]);
		L.last++;
	}
}
void list(Seplist L)
{
	int m=0;
	for(m=0; m<L.last; m++)
	{
		if(m%2==0)
		printf("%d ", L.elem[m]);
	}
	
}
int main()
{
	Seplist L;
	L.last=0;
	creat(L);
	list(L);
	return 0;	
}
