/*
86.取石子 (15分)
C时间限制：3 毫秒 |  C内存限制：3000 Kb
题目内容：
有两堆石子，数量任意，可以不同。游戏开始由两个人轮流取石子。游戏规定，每次有两种不同的取法，一是可以在任意的一堆中
取走任意多的石子；二是可以在两堆中同时取走相同数量的石子。最后把石子全部取完者为胜者。现在给出初始的两堆石子的数
目，如果轮到你先取，假设双方都采取最好的策略，问最后你是胜者还是败者。
输入描述
输入包含若干行，表示若干种石子的初始情况，其中每一行包含两个非负整数a和b，表示两堆石子的数目，a和b都不大于
1,000,000,000。

输出描述
输出对应也有若干行，每行包含一个数字1或0，如果最后你是胜者，则为1，反之，则为0。

输入样例
2 1
8 4
4 7

输出样例
0
1
0

*/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

//威佐夫博弈
int main () {
    int a, b;
    while (cin >> a >> b) {
        if (a > b) swap(a, b);
        int k = b - a;
        double x = (int)(k*(sqrt(5.0) + 1) / 2.0);
        if (a == x) {
            cout << "0" << "\n";
        } else {
            cout << "1" << "\n";
        }
    }
    return 0;
}
