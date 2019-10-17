/*采用三种方式输出学生信息管理系统中的学生信息，
采用结构体变量访问结构体成员：
结构体变量名.成员名

或者是以下两种方式：
(*结构体指针变量名).成员名
结构体指针变量名->成员名
例如：
int score;
score = (*p).math;    //将数学成绩赋值给score 
score = p->english;   //将英语成绩赋值给score 
*/#include<stdio.h>
int main()
{
	struct stu_type
{
	char num[15];       //学号 
	char name[10];      //姓名 
	int age;          //年龄 
	int c;            //C语言成绩 
	int math;         //数学成绩 
	int eng;          //英语成绩 
	int sum;          //总成绩 
	float ave;        //平均分
	 
 } ;
 struct stu_type stu1 = {"2017105909", "敖光成", 20, 90, 90, 90},*p = &stu1;
 stu1.sum = stu1.c + stu1.eng +stu1.math;
 stu1.ave = stu1.sum /3;
 printf("学生学号\t姓名\t年龄\tC语言\t数学\t英语\t总分\t平均分\n"); 
 printf("%-16s%s\t%d\t%d\t%d\t%d\t%d\t%5.f\n", stu1.num, stu1.name, stu1.age, stu1.c, stu1.math, stu1.eng, stu1.sum, stu1.ave);
 printf("%-16s%s\t%d\t%d\t%d\t%d\t%d\t%5.f\n", (*p).num, (*p).name, (*p).age, (*p).c, (*p).math, (*p).eng, (*p).sum, (*p).ave);
 printf("%-16s%s\t%d\t%d\t%d\t%d\t%d\t%5.f\n", p->num, p->name, p->age, p->c, p->math, p->eng, p->sum, p->ave);
}


