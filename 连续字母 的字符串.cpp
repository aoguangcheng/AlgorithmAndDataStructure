#include<stdio.h>
#include<string.h>

int continueString(char s[])
{
	int i = 0;
	int ch = s[0];
	while(s[i] != '\0')
	{
		if(s[i] != (char)ch)
		{
			return 0;
		}
		ch = (ch + 1);
		i++;
	}
	return 1;
}

int main()
{
	char s[26];
	gets(s);
	if(continueString(s))
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
	return 0;
}