/*
��������
��������һ������ a_1, a_2, ..., a_n������ a_1 ����������û���������� a_1 ��ȡ�
�������ڴӵڶ�������ʼ��ÿ���� a_i�����ҵ�λ���� a_i ֮ǰ�ұ� a_i ��ģ�λ���Ͼ��� a_i ������� a_j���� i-j Ϊ a_i ��ǰ����롣
�������ڸ��������У��������������ǰ�����֮�͡�
�����ʽ
��������ĵ�һ�а���һ������ n����ʾ���еĳ��ȡ�
�����ڶ��а��� n ����������Ϊ���������С�
�����ʽ
�������һ����������ʾ��������������ǰ�����֮�͡�
��������
8
9 1 3 5 2 7 6 3
�������
14
*/

#include <iostream>
#include <malloc.h>
using namespace std;

int fun(int a[], int index)
{
	int j;
	for (j = index - 1; j; j--)
	{
		if (a[index] < a[j])
		{
			break;
		}
	}
	return (index - j);
}

int main()
{
	int length;
	long long count = 0;
	cin >> length;
	int *a = (int *)malloc(sizeof(int) * length);
	for (int i = 0; i < length; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i < length; i++)
	{
		count += fun(a, i);
	}
	cout << count;
	return 0;
}
