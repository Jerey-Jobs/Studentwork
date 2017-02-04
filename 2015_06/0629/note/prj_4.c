/**
 * @author evan lau
 * @date 2015/06/13
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int fd[2];      /* fd[0]: read; fd[1]: write. */
	int pid;
	int len;
	char buf[128];

    /*创建API*/
	if (-1 == pipe(fd))
	{
		perror("Create pipe error ");
		exit(1);
	}

    pid = fork();  //创建进程

    if(pid == 0)    //子进程代码
	{
		close(fd[1]);        /* 关闭写端 */
		len = read(fd[0], buf, sizeof(buf));     //开始读
		buf[len] = 0;      //读完记得在后面加结束符号

		printf("Child read from pipe: %s\n", buf);      
		close(fd[0]);  //关闭读端
		exit(0);
	}
	else          //父进程代码 
	{
		close(fd[0]);        /* close read fd */
		printf("Father send \"hello world!\" to child!\n");
		write(fd[1], "hello world!", 12);            //向管道写
		close(fd[1]);
	}

	wait(NULL);
	return 0;
}


