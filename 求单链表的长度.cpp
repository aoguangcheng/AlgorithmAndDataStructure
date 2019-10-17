#include<stdio.h>
int ListLength(LinkList L)
{
	Node *p;
	p = L->next;
	j = 0;
	while(p != NULL)
	{
		p = p -> next;
		j++;
	}
	return j ;
 } 
