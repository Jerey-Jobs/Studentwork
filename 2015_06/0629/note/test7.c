#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int count;
//每次在函数里都加1  然后判断是第多少次
void handler(int n)
{
	count++;
	printf("handler%d\n",n);

	if(count == 5)
	{
		printf("five\n");
	}
	else if(count == 7)
	{
		printf("7shou\n");
	}
	else if(count == 12)
	{
		printf("12\n");
	}
	alarm(1);       //每次结束继续定时1秒
}


int main(int argc, char const *argv[])
{
	signal(SIGALRM,handler);  //设置自定义信号处理
	
	alarm(1);            //给个信号

	getchar();               //不让程序退出
	getchar();

	return 0;

}

