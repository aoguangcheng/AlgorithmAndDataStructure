/*
644.扩展gcd-时间复杂性 (10分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
计算循环语句的执行频次 for(i=A; i!=B ; i+=C) x+=1;
其中A,B,C,i都是k位无符号整数。
输入描述
A B C k, 其中0<k<32

输出描述
输出执行频次数，如果是无穷，则输出“forever”

输入样例
3 7 2 16

输出样例
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
    //b改成b = 1 << k就会出错
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
    ex_gcd(a,b,x,y);    //返回ax + by = gcd(a,b)的解
    x = x * (n / gc);   //得到通解x即：ax + by = n
    LL nn = b / gc;     //通解x的最小周期
    x = (x % nn + nn) % nn; //得到最小解
    cout << x << endl;
    return 0;
}
