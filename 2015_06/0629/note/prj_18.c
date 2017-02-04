/**
 * @author evan
 * @date 2015/06/27
 */

#include <stdio.h>
#include <pthread.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void *read_from_file(void *arg)
{
    int fd;             //file descriptor
	char buf[1024];

	//打开文件开始读啊骚年
	if((fd = open("prj_18.c", O_RDONLY)) < 0)
	{
        perror("Open file error");
		exit(0);
	}


	/**
	 * 读的很快，所以每次读一个，好让你输入E
	 */
	while(read(fd, buf, 1))
	{
        printf("%s", buf);
		sleep(1);
	}

	close(fd);
}


int main(int argc, char *argv[])
{
    pthread_t thread;
	char buf;

	//创建线程
    pthread_create(&thread, NULL, read_from_file, NULL);

	while(1)
	{
        buf = getchar();            //获取输入字符
		if(buf == 'E')             //判断是否为E 
		{
			pthread_cancel(thread);   //kill sub thread
			
            exit(0);
		}
		sleep(1);       //这个延时1秒我认为没必要
	}
	
	return 0;
}






