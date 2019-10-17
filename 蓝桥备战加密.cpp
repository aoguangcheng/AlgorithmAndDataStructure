/*
89.加密 (15分)
C时间限制：3 毫秒 |  C内存限制：3000 Kb
题目内容：
一种Playfair密码变种加密方法如下：首先选择一个密钥单词（称为pair）（字母不重复，且都为小写字母），然后与字母表中
其他字母一起填入至一个5x5的方阵中，填入方法如下：
1.首先按行填入密钥串。
2.紧接其后，按字母序按行填入不在密钥串中的字母。
3.由于方阵中只有25个位置，最后剩下的那个字母则不需变换。
如果密钥为youandme，则该方阵如下： 
y o u a n
d m e b c
f g h i j
k l p q r
s t v w x
在加密一对字母时，如am，在方阵中找到以这两个字母为顶点的矩形：
o u a 
m e b 

这对字母的加密字母为该矩形的另一对顶点，如本例中为ob。
请设计程序，使用上述方法对输入串进行加密，并输出加密后的串。
另外有如下规定：
1、一对一对取字母，如果最后只剩下一个字母，则不变换，直接放入加密串中；
2、如果一对字母中的两个字母相同，则不变换，直接放入加密串中；
3、如果一对字母中有一个字母不在正方形中，则不变换，直接放入加密串中；
4、如果字母对出现在方阵中的同一行或同一列，如df或hi，则只需简单对调这两个字母，即变换为fd或ih；
5、如果在正方形中能够找到以字母对为顶点的矩形，假如字母对为am，则该矩形的另一对顶点字母中，与a同行的字母应在前
面，在上例中应是ob；同样若待变换的字母对为ta，则变换后的字母对应为wo；
6、本程序中输入串均为小写字母，并不含标点、空格或其它字符。
解密方法与加密相同，即对加密后的字符串再加密，将得到原始串。
输入描述
从控制台输入两行字符串，第一行为密钥单词（长度小于等于25，字母不重复，且都为小写字母），第二行为待加密字符串（长度
小于等于50），两行字符串末尾都有一个回车换行符，并且两行字符串均为小写字母，不含其它字符。

输出描述
在标准输出上输出加密后的字符串。

输入样例
youandme
welcometohangzhou
输出样例
vbrmmomvugnagzguu
*/
#include<cstring>
#include<stdio.h>
#include<iostream>
using namespace std;

char A[5][5];

int fun1(char S[], char ch)//若字符串S中不含字符ch，则返回1，否则返回零 
{
	int flag = 1;
	int i;
	for(i = 0; i < strlen(S); i++)
	{
		if(ch == S[i])
		{
			flag = 0;
			break;
		}
	}
	return flag;
}

int main()
{	
	int i;
	int j;
	int k;
	int l;
	char ch;
	char S[25];
	char T[50];
	char R[25];
	gets(S);
	gets(T);
	
	for(l = 0, ch = 'a'; ch <= 'z'; ch ++)
	{
		if(fun1(S, ch) == 1)
		{
			R[l] = ch;
			l++;
		}
	}
	for(l = 0, k = 0, i = 0; i < 5; i++)
	{
		int flag = 0;
		for(j = 0; j < 5; j++)
		{
			if(flag == 0)
			{
				if(S[k] != '\0')
				{
					A[i][j] = S[k];
					k++;
				}
				else
				{
					flag = 1;
					j--;
				} 
			}
			else
			{
				A[i][j] = R[l];
				l++;
			}
		}
	}
	/*
	for (i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	int n = strlen(T);
	if(n % 2 == 0)
	{
		for(i = 0; i < n - 1; i = i + 2)
		{
			int i1 = -1;
			int j1 = -1;
			int i2 = -1;
			int j2 = -1;
			for(k = 0; k < 5; k++)
			{
				for(l = 0; l < 5; l++)
				{
					if(T[i] == A[k][l])
					{
						i1 = k;
						j1 = l;
					}
					if(T[i + 1] == A[k][l])
					{
						i2 = k;
						j2 = l;
					}
				}
			}
			if(i1 != -1 && i2 != -1)
			{
				if(i1 == i2 || j1 == j2)
				{
					cout<<T[i + 1]<<T[i];
				}
				else
				{
					cout<<A[i1][j2]<<A[i2][j1];
				}
			} 
			else
			{
				cout<<T[i]<<T[i + 1];
			}
		}
	}
	else
	{
		for(i = 0; i < n - 2; i = i + 2)
		{
			int i1 = -1;
			int j1 = -1;
			int i2 = -1;
			int j2 = -1;
			for(k = 0; k < 5; k++)
			{
				for(l = 0; l < 5; l++)
				{
					if(T[i] == A[k][l])
					{
						i1 = k;
						j1 = l;
					}
					if(T[i + 1] == A[k][l])
					{
						i2 = k;
						j2 = l;
					}
				}
			}
			if(i1 != -1 && i2 != -1)
			{
				if(i1 == i2 || j1 == j2)
				{
					cout<<T[i + 1]<<T[i];
				}
				else
				{
					cout<<A[i1][j2]<<A[i2][j1];
				}
			} 
			else
			{
				cout<<T[i]<<T[i + 1];
			}
		}
		cout<<T[n - 1];
	}
//	cout<<'\0'; 
	return 0;
} 
