/*





*/
#include<stdio.h>
#include<stdlib.h> 
#define MAXSIZE 100
typedef struct
{
	int elem[MAXSIZE];
	int last;
	
	
}SeqList;
//定义线性表的存储

int Locate(SeqList L, int e)
{
	int i = 0;
	while((i <= L.last) && (L.elem[i] != e))
	i++;
	if(i <= L.last)
	return(i+1);
	else 
	return(-1);
 } 
//按内容查找Locate( L, e)

#define OK 1
#define ERROR 0
int InsList(SeqList *L, int i, int e)
{
	int k;
	if((i < 1) || (i > L->last+2))
	{
		printf("插入位置不合法！"); 
		return(ERROR); 
	}
	if(L->last >= MAXSIZE-1)
	{
		printf("表已满，无法插入！");
		return(ERROR); 
	}
	for(k = L->last; k >= i - 1; k--)
	L->elem[k+1] = L->elem[k];
	L->elem[i-1] = e;
	L->last++;
	return(OK); 
 } 
 //顺序表的插入运算
 
 int DelList(SeqList *L, int i, int *e)
 {
 	int k;
 	if((i < 1) || (i > L->last+1))
 	{
 		printf("删除位置不合法！");
		return(ERROR); 
	 }
	 *e = L->elem[i-1];
	 for(k = i; i <= L->last; k++)
	 L->elem[k-1] = L->elem[k];
	 L->last--;
	 return(OK);
  } 
  //顺序表的删除操作 
  
void mergeList(SeqList *LA, SeqList *LB, SeqList *LC)
{
	int i , j, k, l;
	i = 0; j = 0, k = 0;
	while(i <= LA->last && j <= LB->last)
	if(LA->elem[i] <= LB->elem[j])
	{
		LC->elem[k] = LA->elem[i];
		i++, k++;
	}
	else
	{
		LC->elem[k] = LB->elem[j];
		j++, l++;
	}
	while(i <= LA->last)
	{
		LC->elem[k] = LA->elem[i];
		i++, k++;
	}
	while(j <= LB->last)
	{
		LC->elem[k] = LB->elem[j];
		j++, k++;
	}
	LC->last = LA->last + LB->last + 1;
}
//线性表的合并运算（保留相同元素）

int input(SeqList &L)
{
	int n, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &elem[i]);
		L.last++;
	}
//输入线性表，先输入元素总数n，再输入n个元素 

int output(SeqList L)
{
	int i;
	for(i = 0; i < L.last; i++)
	{
		printf("%d", elem[i]);
	}
}
//完成输出线性表的所有元素

int main()
{
	int n, i;
	intput(SeqList &L);
	output(SeqList L);
	return 0 ;
 } 
 //主函数 
}
