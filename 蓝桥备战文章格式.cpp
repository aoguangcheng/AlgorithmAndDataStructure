/*
62.���¸�ʽ (15��)
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
 ��д����ʵ�ֽ�һ�����¸�ʽ����ӡ��������ӡʱÿ�еĳ���Ϊ20���ַ���
���һ�е����һ�����ʳ����˱��е�20���ַ��ķ�Χ����Ӧ�����Ƶ���һ�С�
������ÿ������֮������һ���ո����һ������ǰ�������Ҫ���Ӷ���ո�
ʹÿ�е�ĩβ׼ȷ�ش��ڵ�20��λ�ô���
��������
����n�����ʣ��������룬ÿ�����ʲ��ܳ���20����ĸ�����ʼ��ÿո����������
Ҫ��Ϊת�У�Ҳ����˵�������ĵ��ʳ���һ��Ҳ��Ҫ��Enter��

�������
������n�����ʷ��д�ӡ��ÿ��20���ַ������һ��ֻ�ܷ�һ�������򵥴ʺ��ÿո���䣬
��һ�пɷŶ�����ʣ���ĩβ����Ϊ���ʣ���һ�����ʲ��ܿ��������

��������
The relationship between XML functional dependencies and XML keys are also discussed
0 2 4 15 17 23 25 27 29 38 40 51 53 55 57 59 61 64 66 68 70 73 75 84

�������
The     relationship
between          XML
functional          
dependencies and XML
keys are        also
discussed

*/ 
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char S[100];
	int A[30];
	
	gets(S);
	int i = 1;
	int j = 2;
	A[1] = 0;
	int len = strlen(S);
//	cout<<len;
	
	while(i < len)
	{
//		cout<<S[i];
		if(S[i] == ' ')
		{
			A[j++] = i - 1;
			A[j++] = i + 1;
		}
		i++; 
	}
	A[j++] = len;
	
	for(i = 1; i < j; i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	
	int start = 0;
	int end;
	int startempty;
	int endempty;
	int emptycount;
	for(i = 1; i < j;)
	{
		if(A[i] - start <= 20 && A[i + 1] - start >= 20)
		{
			end = A[i - 1];
			endempty = A[i - 2] - 1;
			emptycount = 19 - ((end - start) % 20);
			if(endempty - emptycount + 1> A[i - 3])
			{
				startempty = endempty - emptycount + 1;
			
			}
			else
			{
				startempty = A[i - 3];
				emptycount++; 
			}
			int k;
			
			for(k = start; k <= startempty; k++)
			{
				cout<<S[k];	
			} 
			for(k = 0; k <= emptycount; k++)
			{
				cout<<" ";
			}
			for(k = startempty + 1; k <= end; k++)
			{
				cout<<S[k];
			}
			cout<<endl;
			start = A[i];
		}
		else
		{
			i = i + 2;
		}
	}
	return 0;
}























