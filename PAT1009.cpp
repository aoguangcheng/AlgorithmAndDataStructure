/*
����һ��Ӣ�Ҫ�����д���򣬽��������е��ʵ�˳��ߵ������
����������

Hello World Here I Come
���������

Come I Here World Hello
*/
#include<stdio.h>
#include<string.h>
int main()
{
	char S[80];
	gets(S);
	int i = strlen(S) - 1;
	int j = i;
	while(i >= 0)
	{
		if(S[i] != ' ')
			i--;
		else
		{
			int k = i + 1;
			for(k; k <= j; k++)
			{
				printf("%c", S[k]);
			}
			printf(" ");
			i--;
			j = i;
		}
	}
	int h = 0;
	for(h; h <= j; h++)
	{
		printf("%c", S[h]);
	}
	return 0;
}