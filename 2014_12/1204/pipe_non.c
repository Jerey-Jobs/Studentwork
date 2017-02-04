/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include <unistd.h>

int read_pipe(int fd)
{
    char buf_r[100] = "no date";
    int num;

    int flag = fcntl(fd,F_GETFL);
    fcntl(fd, F_SETFL, flag | O_NONBLOCK);
 
    while(1)
    {
        num = read(fd,buf_r,sizeof(buf_r));

        buf_r[num] = '\0';
       
        printf("buf = %s\n",buf_r);

        sleep(2);
    }

    return 0;
}

int write_pipe(int fd)
{
    char buf[100];

    while(1)
    {
        memset(buf,0,sizeof(buf));
        scanf("%s",buf);
        write(fd,buf,strlen(buf));
    }

}

int main()
{
    int pid;
    int fd[2];

    pipe(fd);

    pid = fork();
    if(pid > 0)
    {
        close(fd[0]);
        write_pipe(fd[1]);
    }
    else if(pid == 0)
    {
        close(fd[1]);
        read_pipe(fd[0]);
    }

    return 0;
}
