/*
*copyright by 三峡大学计算机与信息学院计科四班
*All right reserved. 
*完成日期：2018.4.12
*原作者： 敖光成2017105909
*/
/*	定义一个类来表示银行账户。数据成员包括储户姓名、账号（使用字符串）和存款。成员函数执行如下操作：
1）	对象初始化；
2）	显示储户姓名、账号和存款；
3）	存入参数指定的存款；
4）	取出参数制定的款项。
请提供类声明及类的实现。并编写主函数进行测试。
*/
#include<iostream>
#include<string>
using namespace std; 
class Move
{
	private:
		string name;
		string account;
		double balance;
		
	public:
		Move (string na = '\0', string ac = '\0', double ba = 0.0)
		{
			name = na;
			account = ac;
			balance = ba;
		}
		
		void ShowMove();
		void Deposit(double deposit);
		void Withdrawl(double withdrawl);
		
 } ;

void Move::ShowMove()
{
	cout<<"姓名:"<<name<<endl;
	cout<<"账号:"<<account<<endl;
	cout<<"存款:"<<balance<<endl;
}

void Move::Deposit(double deposit)
{
	balance = balance + deposit;
	cout<<"存款"<<balance<<endl; 
	
 } 
 
 void Move::Withdrawl(double withdrawl)
 {
 	balance = balance - withdrawl;
 	cout<<"存款"<<balance<<endl;
 	
 }
 
 int main()
 {
 	Move A("敖光成", "2017105909", 10000);
	 double deposit;
	 double withdrawl;
	 
	 A.ShowMove();
	 cout<<"存入的钱款数：\n"<<endl;
	 cin>>deposit;
	 
	 A.Deposit(deposit);
	 cout<<"取出的钱款数：\n"<<endl;
	 cin>>withdrawl;
	 
	 A.Withdrawl(withdrawl);
	 
	 return 0 ; 
 }
 
 
