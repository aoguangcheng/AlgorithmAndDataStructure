/*�������ַ�ʽ���ѧ����Ϣ����ϵͳ�е�ѧ����Ϣ��
���ýṹ��������ʽṹ���Ա��
�ṹ�������.��Ա��

�������������ַ�ʽ��
(*�ṹ��ָ�������).��Ա��
�ṹ��ָ�������->��Ա��
���磺
int score;
score = (*p).math;    //����ѧ�ɼ���ֵ��score 
score = p->english;   //��Ӣ��ɼ���ֵ��score 
*/#include<stdio.h>
int main()
{
	struct stu_type
{
	char num[15];       //ѧ�� 
	char name[10];      //���� 
	int age;          //���� 
	int c;            //C���Գɼ� 
	int math;         //��ѧ�ɼ� 
	int eng;          //Ӣ��ɼ� 
	int sum;          //�ܳɼ� 
	float ave;        //ƽ����
	 
 } ;
 struct stu_type stu1 = {"2017105909", "�����", 20, 90, 90, 90},*p = &stu1;
 stu1.sum = stu1.c + stu1.eng +stu1.math;
 stu1.ave = stu1.sum /3;
 printf("ѧ��ѧ��\t����\t����\tC����\t��ѧ\tӢ��\t�ܷ�\tƽ����\n"); 
 printf("%-16s%s\t%d\t%d\t%d\t%d\t%d\t%5.f\n", stu1.num, stu1.name, stu1.age, stu1.c, stu1.math, stu1.eng, stu1.sum, stu1.ave);
 printf("%-16s%s\t%d\t%d\t%d\t%d\t%d\t%5.f\n", (*p).num, (*p).name, (*p).age, (*p).c, (*p).math, (*p).eng, (*p).sum, (*p).ave);
 printf("%-16s%s\t%d\t%d\t%d\t%d\t%d\t%5.f\n", p->num, p->name, p->age, p->c, p->math, p->eng, p->sum, p->ave);
}


