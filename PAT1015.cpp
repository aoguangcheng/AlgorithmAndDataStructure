/*
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
输出样例：

 12
 10000013 90 99
 10000012 80 100
 10000003 85 80
 10000011 85 80
 10000004 80 85
 10000007 90 78
 10000006 83 76
 10000005 82 77
 10000002 90 60
 10000014 66 60
 10000008 75 79
 10000001 64 90
*/
#include<stdio.h>
#include<string.h>

typedef struct node
{
	char S[8];
	int moral;
	int ability;
	int sum;
}Stu;

void sort(Stu stuu[], int a, int b)
{
	int i;
	int j;
	for(i = a; i < b; i++)
	{
		for(j = a; j < b - i; j++)
		{
			if ((stuu + j)->sum < (stuu + j + 1)->sum)
			{
				Stu temp = *(stuu + j);
				*(stuu + j) = *(stuu + j + 1);
				*(stuu + j + 1) = temp;
				/*temp.ability = stuu[j].ability;
				temp.moral = stuu[j].moral;
				strcpy(temp.S, stuu[j].S);
				stuu[j].ability = stuu[j + 1].ability;
				stuu[j].moral = stuu[j + 1].moral;
				strcpy(stuu[j].S, stuu[j + 1].S);
				stuu[j + 1].ability = temp.ability;
				stuu[j + 1].moral = temp.moral;
				strcpy(stuu[j + 1].S, temp.S);*/
			}
		}
	}
	for(i = a; i < b; i++)
	{
		for(int c = 0; c < 8; c++)
		{
			printf("%c", (stuu + i)->S[c]);
		}
		printf(" ");
		printf("%d %d\n", (stuu + i)->moral, (stuu + i)->ability);
	}
}

int main ()
{
	const int N = 100;
	int L;
	int H;
	int n;
	scanf("%d", &n);
	scanf(" %d", &L);
	scanf(" %d\n", &H);
	Stu stu[N];
	int i;
	int j;
	for(i = 0; i < n; i++)
	{
		scanf("%s %d %d", &stu[i].S, &stu[i].moral, &stu[i].ability);
	}
	for(j = 0; j < n; j++)
	{
		stu[j].sum = stu[j].moral + stu[j].ability;
	}
	Stu stuu[N];
	j = 0;//德才兼备
	for(i = 0; i <= n; i++)
	{
		if(stu[i].ability >= H && stu[i].moral >= H)
		{
			*(stuu + j) = *(stu + i);
			/*strcpy(stuu[j].S, stu[i].S);
			stuu[j].ability = stu[i].ability;
			stuu[j].moral = stu[i].moral;
			stuu[j].sum = stu[i].sum;*/
			stu[i].sum = 0;
			j++;
		}
	}
	int k = 0;//德胜才
	for(i = 0; i <= n; i++)
	{
		if(stu[i].moral >= H && stu[i].ability >= L && stu[i].ability < H && stu[i].sum != 0)
		{
			*(stuu + k + j) = *(stu + i);
			/*strcpy(stuu[k + j].S, stu[i].S);
			stuu[k + j].ability = stu[i].ability;
			stuu[k + j].moral = stu[i].moral;
			stuu[k + j].sum = stu[i].sum;*/
			stu[i].sum = 0;
			k++;
		}
	}
	int p = 0;//德才兼失但德胜才
	for(i = 0; i <= n; i++)
	{
		if(stu[i].ability >= L && stu[i].moral >= stu[i].ability && stu[i].moral <= H && stu[i].sum != 0)
		{
			*(stuu + j + k + p) = *(stu + i);
			/*strcpy(stuu[p + j + k].S, stu[i].S);
			stuu[p + j + k].ability = stu[i].ability;
			stuu[p + j + k].moral = stu[i].moral;
			stuu[p + j + k].sum = stu[i].sum;*/
			stu[i].sum = 0;
			p++;
		}
	}
	int q = 0;//愚人
	for(i = 0; i <= n; i++)
	{
		if(stu[i].ability >= L && stu[i].moral >= L && stu[i].sum != 0)
		{
			*(stuu + j + k + p + q) = *(stu + i);
			/*strcpy(stuu[q + j + k + p].S, stu[i].S);
			stuu[q + j + k + p].ability = stu[i].ability;
			stuu[q + j + k + p].moral = stu[i].moral;
			stuu[q + j + k + p].sum = stu[i].sum;*/
			stu[i].sum = 0;
			q++;
		}
	}
	printf("%d\n", j + k + p + q);
	sort(stuu, 0, j);
	sort(stuu, j, j + k);
	sort(stuu, j + k , j + k + p);
	sort(stuu, j + k + p, j + k + p + q);
	return 0;
}