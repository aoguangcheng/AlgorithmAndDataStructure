#include<iostream>
using namespace std;
/*
凯撒密码是一种替换加密的技术，单词中的所有字母都在字母表上向后偏移3位后被替换成密文。即a变为d，b变为e，...，w变为z，x变为a，y变为b，z变为c。
　　例如，lanqiao会变成odqtldr。
输入格式
　　输入一行，包含一个单词，单词中只包含小写英文字母。
输出格式
　　输出一行，表示加密后的密文。
*/
int main(){
	char s[100];
    char t[100];
    int length = 0;
    int i = 0;
    cin >>s;
    while (s[i] != '\0')
    {
        i ++;
    }
    length = i;
    for(i = 0; i < length; i++)
    {
        t[i] = char(s[i] + 3);
    }
    t[i] = '\0';
    cout << t<<endl;
    return 0;
}
