/*
116.Ӣ����ĸ���� (20��)
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
��дһ�����򣬵�����Ӣ���ַ���ʱ�����������������е�Ӣ����ĸ���ֵ���ĸ˳���������У����к�ĵ��ʵ�
����Ҫ��ԭʼ�����еĳ�����ͬ������Ҫ��ֻ�ԣ����ڵ���ĸ�������У������ַ�����ԭ����״̬��
��������
һ���ַ�����������дӢ����ĸ���Լ������ַ�

�������
�ַ������������У�ֻ�Ǵ�д��ĸ���ֵ�˳��������ĸ����ԭλ

��������
�ԣȣ� �Уңɣã� �ϣƣ£ңţ��� �ɣ� ���� ���� �Уţ� �УϣգΣ�

�������
���£� �ģģţţ� �ţƣȣɣɣΣ� �ϣ� ���� ���� �УУ� �ңңӣԣ�



#include<stdio.h>

int fun(char ch)
{
	if(ch >= 65 && ch <= 90)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int main()
{
	char S[100];
	int i;
	int j; 
	int n;
	gets(S);
	i = 0;
	while(S[i] != '\0')
	{
		i++;
	}
	n = i;
	for(i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n - i - 1;)
		{
			if(fun(S[j]))
			{
				int k = j + 1;
				while(fun(S[k]) == 0 && k < n - i)
				{	
					k++;
				}
				if(k < n - i )
				{
					if(S[j] > S[k])
					{
						char ch = S[k];
						S[k] = S[j];
						S[j] = ch;
					}
					j = k;	
				}
				else
				{
					break;
				}
			}
			else
			{
				j++;
			}
		}
	}
//	printf("%s", S);	puts(S);

	for(i = 0; i < n; i++)
	{
		printf("%c", S[i]);
	}
	return 0;
}
*/

#include<stdio.h>
#include<string.h>

int main()
{
	char A[100];
	char B[100];
	int i;
	int j;
	int k;
	gets(A);
	int n = strlen(A);
	for(i = 0, j = 0; i < n; i++)
	{
		if(A[i] >= 65 && A[i] <= 90)
		{
			B[j] = A[i];
			j++;
		}
	}
	for(k = 0; k < j - 1; k++)
	{
		for(i = 0; i < j - k - 1; i++)
		{
			if(B[i] > B[i + 1])
			{
				char temp = B[i];
				B[i] = B[i + 1];
				B[i + 1] = temp;
			}
		}
	}
	for(i = 0, k = 0; i < n; i++)
	{
		
		if(A[i] >= 65 && A[i] <= 90)
		{
			A[i] = B[k];
			k++;
		}
	}
	puts(A);
	return 0;
}
