/*1088 ������ ��20 point(s)��

��Ի���������У�������ʦ�ɡ��������߶���֮���䲻���߶���֮����
��������ס��ҡ��������˵�����ֵ��ϵΪ���׵�����ֵȷ���� 2 λ��������
�Ѽ׵�����ֵ�� 2 �����ֵ���λ�þ����ҵ�����ֵ�����������������Ǳ�������ֵ�� X �����ҵ�����ֵ�Ǳ��� Y ����
����ָ��˭����ǿӦ����֮����˭������Ӧ����֮����
�����ʽ��

������һ���и���������������Ϊ��M�����Լ�������ֵ����X �� Y���������־�Ϊ������ 1000 ����������
�����ʽ��

��һ������������׵�����ֵ�������������ס��ҡ�����������Ĺ�ϵ����������ǿ����� Cong��ƽ������� Ping��
����������� Gai������� 1 ���ո�ָ�������β�����ж���ո�
ע�⣺����ⲻΨһ�����Լ׵�����Ϊ׼�����жϣ�����ⲻ���ڣ������ No Solution��
�������� 1��

48 3 7
������� 1��

48 Ping Cong Gai
�������� 2��

48 11 6
������� 2��

No Solution*/

#include<stdio.h>
#include<math.h>
int fun1(int x)
{
	int i;
	int j;
	i = x % 10;
	j = x / 10;
	return 10 * i + j;
}

void fun2(int a, int b)
{
	if(a > b)
		printf("Cong");
	if(a == b)
		printf("Ping");
	if(a < b)
		printf("Gai");
}

int main()
{
	int m;
	int x;
	int y;
	int a = 0;
	int b;
	int c;
	int i;
	int j;     //a,b֮��
	
	scanf("%d%d%d", &m, &x, &y);
	for(i = 10; i <= 99; i++)
	{
		b = fun1(i);
		j = abs(i - b);
		if(j % x == 0)
		{
			c = j / x;
			if(c * y == b)
				a = i;
		}
	}
	if(a != 0)
	{
		b = fun1(a);
		c = abs(a - b) / x;
		printf("%d ", a);
		fun2(a, m);
		printf(" ");
		fun2(b, m);
		printf(" ");
		fun2(c, m);
	}
	else
	{
		printf("No Solution");
	}
	return 0;
}