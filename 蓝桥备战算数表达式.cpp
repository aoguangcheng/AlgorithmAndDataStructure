/*
118.�������ʽ��ֵ (15��)
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
 ����һ�������֡�+��-��*��/ ��ɵ��������ʽ������ֵ��
��������
һ�����ʽ������ÿ��������Ϊ������

�������
������������2λС��

��������
1+12*3-4/2

�������
35.00



#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int n;
	int i;
	char S[100];
	double result;
	
	gets(S);
	i = 0;
	int add = 0;
	int h = 1;
	int j = i;
	while(S[j] >= 48 && S[j] <= 57 && S[j] != '\0')
	{
		j++;
	}
	int k = j - 1;
	for(k; k >= i; k--)
	{
		add = (S[k] - 48) * h + add;
		h = h * 10;
	}
	result = add;
	i = j;
	
	while(S[i] != '\0')
	{
		int j = i + 1;
		while(S[j] >= 48 && S[j] <= 57 && S[j] != '\0')
		{
			j++;
		}
		int add = 0;
		int h  = 1;
		int k = j - 1;
		for(k; k > i; k--)
		{
			add = (S[k] - 48) * h + add;
			h = h * 10;
		}
		switch(S[i])
		{
			case '+': result += add; break;
			case '-': result -= add; break;
			case '*': result *= add; break;
			case '/': result /= add; break;
		}
		i = j;
	}
	printf("%.2lf", result);
	return 0;
 } */
#include<iostream> 
#include<algorithm>
#include<vector>
#include<string>
#include<memory.h>
#include<queue>
#include<cmath>
#include<iomanip>
#include<stack>
using namespace std;
string str;
stack<double> n;
stack<char> o;

bool is_num(char a)
{
	if(a <= '9' && a >= '0') return true;
	return false;
}

int get(char c)
{
	if(c == '*' || c == '/') return 2;
	return 1;
}

double cal(double a, char c, double b)
{
	if(c == '+') return a + b;
	if(c == '-') return a - b;
	if(c == '*') return a * b;
	return a / b;
}

double solve()
{
	int len = str.length();
	for(int i = 0; i < len; i++)
	{
		if(is_num(str[i]))				//���������ַ�Ҫȡ������������
		{
			int temp = 0;
			while(i < len && is_num(str[i]))
				temp = temp * 10 + str[i++] - '0';
			i--;
			n.push(temp);
		}
		else
		{
			if(o.empty())       		//ope is empty
				o.push(str[i]);
			else
			{
				while(!o.empty() && get(o.top()) > get(str[i]))    
				{
					double num1 = n.top();
					n.pop();
					double num2 = n.top();
					n.pop();
					n.push(cal(num2, o.top(), num1));
					o.pop();
				}
				o.push(str[i]);
			}
		}
	}

	while(!o.empty())
	{
		double num1 = n.top();
		n.pop();
		double num2 = n.top();
		n.pop();
		n.push(cal(num2, o.top(), num1));
		o.pop();
	}

	return n.top();
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> str;
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<solve();
}
