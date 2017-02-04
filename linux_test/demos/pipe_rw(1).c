#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/stat.h>

#include <fcntl.h>

int main()
{
	int pipe_fd[2];
	pid_t pid;
	char buf_r[100] = "no message";
	char* p_wbuf;
	int r_num;
	char buffer[100];
	
//	memset(buf_r,0,sizeof(buf_r));
	

	/*创建管道*/
	if(pipe(pipe_fd)<0)
	{
		printf("pipe create error\n");
		return -1;
	}
	
	/*创建子进程*/
	if((pid=fork())==0)  //子进程 OR 父进程？
	{
		int count = 0;

		int flag = fcntl(pipe_fd[0],F_GETFL);

		fcntl(pipe_fd[0],F_SETFL,flag | O_NONBLOCK);

		while(1)
		{
		    count = read(pipe_fd[0],buf_r,100);
		    printf("count = %d\n",count);
		    buf_r[count] = '\0';
		   
		    printf("buf = %s\n",buf_r);
		    sleep(2);
		}
		
		#if 0
		printf("\n");
		close(pipe_fd[1]);
//		sleep(2); /*为什么要睡眠*/
		if((r_num=read(pipe_fd[0],buf_r,100))>0)
		{
			printf(   "%d numbers read from the pipe is %s\n",r_num,buf_r);
		}	
		close(pipe_fd[0]);
		exit(0);
		#endif
  	}
	else if(pid>0)
	{
		
		while(1)
		{
		    scanf("%s",buf_r);

		    write(pipe_fd[1],buf_r,strlen(buf_r));
		}
		
		#if 0
		sleep(5);
		close(pipe_fd[0]);
		if(write(pipe_fd[1],"Hello",5)!=-1)
			printf("parent write1 Hello!\n");
		if(write(pipe_fd[1]," Pipe",5)!=-1)
			printf("parent write2 Pipe!\n");
		close(pipe_fd[1]);
		sleep(3);
		waitpid(pid,NULL,0); /*等待子进程结束*/
		exit(0);
		#endif
	}
	return 0;
}

