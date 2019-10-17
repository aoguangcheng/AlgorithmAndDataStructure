/*
116.英文字母排序 (20分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
编写一个程序，当输入英文字符串时，计算机将这个句子中的英文字母按字典字母顺序重新排列，排列后的单词的
长度要与原始句子中的长度相同，并且要求只对Ａ到Ｚ的字母重新排列，其它字符保持原来的状态。
输入描述
一个字符串，包括大写英文字母，以及其他字符

输出描述
字符串的重新排列，只是大写字母按字典顺序，其他字母保持原位

输入样例
ＴＨＥ ＰＲＩＣＥ ＯＦＢＲＥＡＤ ＩＳ ￥１ ２５ ＰＥＲ ＰＯＵＮＤ

输出样例
ＡＢＣ ＤＤＥＥＥ ＥＦＨＩＩＮＯ ＯＰ ￥１ ２５ ＰＰＲ ＲＲＳＴＵ



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
