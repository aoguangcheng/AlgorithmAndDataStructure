/*
62.文章格式 (15分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
 编写程序实现将一段文章格式化打印出来。打印时每行的长度为20个字符。
如果一行的最后一个单词超过了本行的20个字符的范围，则应把它移到下一行。
另外在每个单词之间增加一个空格，最后一个单词前面可能需要增加多个空格，
使每行的末尾准确地处在第20个位置处。
输入描述
输入n个单词（连续输入，每个单词不能超过20个字母，单词间用空格隔开，但不
要人为转行，也就是说如果输入的单词超过一行也不要按Enter）

输出描述
将上面n个单词分行打印，每行20个字符，如果一行只能放一个单词则单词后用空格填充，
若一行可放多个单词，则末尾必须为单词，且一个单词不能跨行输出。

输入样例
The relationship between XML functional dependencies and XML keys are also discussed
0 2 4 15 17 23 25 27 29 38 40 51 53 55 57 59 61 64 66 68 70 73 75 84

输出样例
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























