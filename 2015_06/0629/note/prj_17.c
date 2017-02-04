/**
 * @author evan lau
 * @date 2015/06/13
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *timer(void *arg)
{
    int sec = (int)arg;    //强制转换参数为int

	sleep(sec);       //睡眠参数秒

	printf("%d !!!\n", sec);    //打印看看.............
	
}

int main(int argc, char **argv)
{
	pthread_t thread[3];        //3个线程的描述符
	int time[] = {5, 7, 12};    //3个传入参数
    int i;

	for (i = 0; i < 3; i++)        //创建三哥线程
	{
		pthread_create(&thread[i], NULL, timer, (void *)time[i]);
	}
	
    //等待3个线程退出
	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);
	pthread_join(thread[2], NULL);
	
    return 0;
}




