#include<stdio.h>

int connect(char *p1, char *p2)
{
	int i = 0;
	int j = 0;
	while(p1[i] != '\0')
	{
		i++;
	}
	while(p2[j] != '\0')
	{
		p1[i] = p2[j];
		i++;
		j++;
	}
	p1[i] = '\0';
	return 0;
}


int main()
{
	char s1[80];
	char s2[40];
	scanf("%s%s", s1, s2);
	connect(s1, s2);
	printf("%s", s1);
	return 0;
 } 
