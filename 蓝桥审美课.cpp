/*
�����ʽ
������һ��������n��m����ʾѧ������ͼ������
������������һ��n*m��01����A��
�������aij=0����ʾѧ��i���õ�j������С���ѻ��ģ�
�������aij=1����ʾѧ��i���õ�j��������߻��ġ�
�����ʽ
�������һ����ans����ʾ�ж��ٶ�ͬѧ�Ĵ���ȫ�෴��
��������
3 2
1 0
0 1
1 0
�������
2
*/ 

#include<stdio.h>
#define N 5000
#define M 20
int main()
{
	int stu;
	int pai;
	int A[N][M];
	int sum = 0;
	scanf("%d %d\n", &stu, &pai);
	int i;
	int j;
	for(i = 1; i <= stu; i++)
	{
		for(j = 1; j <= pai; j++)
		{
			scanf("%d", &A[i][j]);
		}
//		scanf("%d\n", &A[i][j]);
	}
	
	for(i = 1; i < stu; i++)
	{
		int k = i + 1;
		for(k ; k <= stu; k++)
		{
			int flag = 1;
			for(j = 1; j <= pai; j++)
			{
				if(A[i][j] == A[k][j])
				{
					flag = 0;
					break;
				}
			}
			if(flag == 1)
			{
				sum += 1;;
			}
		}
	}
	printf("%d", sum);
	return 0;
}
