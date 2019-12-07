/*
问题描述
　　输入一个单词，请输出这个单词中第一个出现的元音字母。
　　元音字母包括 a, e, i, o, u，共五个。
输入格式
　　输入一行，包含一个单词，单词中只包含小写英文字母。
输出格式
　　输出一行包含一个字母，为单词中第一个出现的元素字母。若单词中不存在元音字母，输出字母n。
样例输入
hello
样例输出
e
*/

#include<iostream>

using namespace std;

int main(){
    char s[100];
    cin >> s;
    int i = 0;
    while (s[i] != '\0')
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            cout<<s[i];
            return 0;
        }
        i++;
    }

    cout<<"n";
    return 0;
}