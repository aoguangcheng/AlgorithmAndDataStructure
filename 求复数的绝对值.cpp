/*������������ṹ�������ľ���ֵ*/
#include<iostream>
#include<cmath>
using namespace std; 

class Complex
{
	
	private:
		double real;
		double imag;
	public:	
		void init(double r, double i)
		{
			real = r;
			imag = i; 
		}
		
		double absComplex()
		{
			double t;
			t = real * real + imag * imag;
			return sqrt(t);
		}
	
 };
 
 int main()
 {
 	Complex A;
 	A.init(1.1, 2.2);
 	cout<<"�����ľ���ֵ�ǣ�"<<A.absComplex()<<endl;
 	return 0 ;
 }
