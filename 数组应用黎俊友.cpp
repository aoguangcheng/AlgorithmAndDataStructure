/*�Ӽ�������15�������������У�
�������ֵ����Сֵ�������ĸ�������ƽ��ֵ��������λС����
//�迡�� 2017105934
*/
#include<stdio.h>
#define N 15           //�������鳤�� 
int main()
{
	int a[N];          // �������� 
	int i;          
	int max;           // ���ֵ 
	int min;           // ��Сֵ 
	int j = 0;
	int sum = 0;
	double ave = 0;    // ƽ���� 
	
	printf("������ʮ���������\n"); 
	for(i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	
	min = a[0];
	max = a[0];
	for(i = 0; i < N; i++)
	{
		if(a[i] < min)
		min = a[i];
		if(a[i] > max)
		max = a[i];
	}
	printf("���ֵΪ��%d\n", max);     //forѭ����ifǶ�������ֵ 
	printf("��СֵΪ��%d\n", min);     //forѭ����ifǶ������Сֵ 
	
	for(i = 0; i < N; i++)
	{
		if(a[i] > 0)
		{
			j++;
		}
	}
	printf("�����ĸ���Ϊ��%d\n", j);   //forѭ����ifǶ������������
	
	for(i = 0; i < N; i++)
	{
		sum = sum + a[i];
	}
	ave = (double)sum / N; 
    printf("ƽ����Ϊ��%.2lf\n", ave);  //forѭ����ƽ��ֵ 
	
    return 0 ;
}
