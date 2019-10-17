#include<stdio.h>

int main()
{
	int n;
	int high;
	int low;					
	int i;
	char a[100];
	char s[100];

	scanf("%d\n", &n);
	for(i = 0; i < n - 1; i++)
	{
		scanf("%c\n", &s[i]);
	}

	scanf("%c", &s[i]);
	i++;
	
	s[i] = '\0';

	low = 0;
	i = 0;
	high = n - 1;

	while(low < high)
	{
		if(s[high] <= s[low])
		{
			a[i] = s[high];
			high--;
			i++;
		}
		else
		{
			a[i] = s[low];
			i++;
			low++;
		}
	}
	if(high == low)
	{
		a[i] = s[high];
		i++;
	}
	a[i] = '\0';
	printf("%s", a);
	return 0;
}