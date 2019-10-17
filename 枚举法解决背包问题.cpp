#include<stdio.h>
#define N 4
int weight = 7;
int k = 0;
int wmax[16];
int vmax[16];

void fun (int *w, int *v, int *tag, int i)
{
	if(i == N)
	{
		int sumw = 0; 
		int sumv = 0;
		for(int j = 0; j < N; j++)
		{
			if(tag[j] == 1)
			{
				sumw = sumw + w[j];
				sumv = sumv + v[j];
			}	
		}
		if(weight >= sumw)
		{
			wmax[k] = sumw;
			vmax[k] = sumv;
			k++;
		}
		return ;
	}
	tag[i] = 1;
	fun(w, v, tag, i + 1);
	tag[i] = 0;
	fun(w, v, tag, i + 1);
}

int main()
{
	int w[] = {5, 3, 2, 1};
	int v[] = {4, 4, 3, 1};
	int tag[N];
	int vMAX;
	int l;
	fun(w, v, tag, 0);
	vMAX = vmax[0];
	l = 0;
	for(int i = 1; i < 16  ; i++)
	{
		if(vMAX < vmax[i])
		{
			vMAX = vmax[i];
			l = i;
		}
	}
	printf("最大价值为：%d\n此时的质量为：%d\n", vMAX, wmax[l]);
	return 0;
}