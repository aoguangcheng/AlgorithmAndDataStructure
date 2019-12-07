//获得代码的运行时间和空间可用类似下面的技术：
#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
int A[30000];
int main(){
	int i;
	double start,finish;
	start=(double) clock();  //获得开始 时间
	for (i=0;i<10000;i++)
	    printf("Hello,World");
	
	finish=(double)clock();  //获得结束 时间
    // 输出 时间差 毫秒 数：
    printf("\n%.4f ms",finish-start);
	system( "wmic process list MEMORY >>log.txt");
	//用system函数执行wmic命令，生成一个log.txt文件，
	//在log.txt里面查你的程序名对应的那一行，记录  PeakVirtualSize 数据 
}
