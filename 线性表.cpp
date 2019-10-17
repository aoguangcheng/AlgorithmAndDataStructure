#include<stdio.h>
#include<std>#define MAXSIZE 100
typedef struct 
{
	int elem[MAXSIZE];
	int last;
	
	
 } SeqList;
 
 int Locate(SeqList L , int e)
 {
 	i = 0;
 	while((i <= L.last)&&(L.elem[i] != e))
 	i++;
 	if(i < L.last)
 	return(i + 1)£»
	 else
	 return(-1); 
  } 
  

  
 

