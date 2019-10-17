#include<stdio.h>
#include<string.h>

int main ()
{
  char s[50];
  gets(s);
  int n = strlen(s);
  int i = 0;
  while(s[i] != '\0')
  {
	switch(s[i])
    {
      case '1' : printf("yi"); break;
      case '2' : printf("er"); break;
      case '3' : printf("san"); break;
      case '4': printf("si"); break;
      case '5' : printf("wu"); break;
      case '6' : printf("liu");break;
      case '7' : printf("qi"); break;
      case '8' : printf("ba"); break;
      case '9' : printf("jiu");break;
      case '0' : printf("ling");break;
      default : printf("fu"); break;
    }
	if(i + 1 < n)
	{
		printf(" ");
	}
    i++;
  }
  return 0;
}