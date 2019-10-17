/*
644.��չgcd-ʱ�临���� (10��)
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
����ѭ������ִ��Ƶ�� for(i=A; i!=B ; i+=C) x+=1;
����A,B,C,i����kλ�޷���������
��������
A B C k, ����0<k<32

�������
���ִ��Ƶ���������������������forever��

��������
3 7 2 16

�������
2


#include<iostream>
using namespace std;

int main()
{
	int A ;
	int B;
	int C;
	int k;
	cin>>A>>B>>C>>k;
	int i;
	int j;
	int count = 0;
	
	for(i = A; i != B; i += C)
	{
		if(count > 10000)
		{
			cout<<"forever";
			return 0;
		} 
		count++;
	}
	
	cout<<count;
	return 0;
}*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
//#define LL long long
typedef long long LL;
LL gcd(LL a, LL b)
{
    return b == 0 ? a : gcd(b, a%b);
}
  
LL ex_gcd(LL a, LL b, LL &x, LL &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    LL ans = ex_gcd(b, a%b, x, y);
    LL temp = x;
    x = y;
    y = temp - a / b*y;
    return ans;
}
 
int main(){
    LL A, B, C, k;
    cin >> A >> B >> C >> k;
    LL a = C,  n = B - A, x, y; //b = pow(2,k),
    //b�ĳ�b = 1 << k�ͻ����
    LL d = 1;
    LL b = d << k;
    cout << "b: " << b << endl;
    int gc = gcd(a,b);
    if(A == 0 && B == 0){
        cout << 0 << endl;
        return 0;
    }
    if(C == 0 || gc == 0 || n % gc != 0){
        cout << "forever" << endl;
        return 0;
    }
    ex_gcd(a,b,x,y);    //����ax + by = gcd(a,b)�Ľ�
    x = x * (n / gc);   //�õ�ͨ��x����ax + by = n
    LL nn = b / gc;     //ͨ��x����С����
    x = (x % nn + nn) % nn; //�õ���С��
    cout << x << endl;
    return 0;
}
