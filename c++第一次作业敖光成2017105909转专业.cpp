/*
*copyright by ��Ͽ��ѧ���������ϢѧԺ�ƿ��İ�
*All right reserved. 
*������ڣ�2018.4.12
*ԭ���ߣ� �����2017105909
*/
/*	����һ��������ʾ�����˻������ݳ�Ա���������������˺ţ�ʹ���ַ������ʹ���Ա����ִ�����²�����
1��	�����ʼ����
2��	��ʾ�����������˺źʹ�
3��	�������ָ���Ĵ�
4��	ȡ�������ƶ��Ŀ��
���ṩ�����������ʵ�֡�����д���������в��ԡ�
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
	cout<<"����:"<<name<<endl;
	cout<<"�˺�:"<<account<<endl;
	cout<<"���:"<<balance<<endl;
}

void Move::Deposit(double deposit)
{
	balance = balance + deposit;
	cout<<"���"<<balance<<endl; 
	
 } 
 
 void Move::Withdrawl(double withdrawl)
 {
 	balance = balance - withdrawl;
 	cout<<"���"<<balance<<endl;
 	
 }
 
 int main()
 {
 	Move A("�����", "2017105909", 10000);
	 double deposit;
	 double withdrawl;
	 
	 A.ShowMove();
	 cout<<"�����Ǯ������\n"<<endl;
	 cin>>deposit;
	 
	 A.Deposit(deposit);
	 cout<<"ȡ����Ǯ������\n"<<endl;
	 cin>>withdrawl;
	 
	 A.Withdrawl(withdrawl);
	 
	 return 0 ; 
 }
 
 
