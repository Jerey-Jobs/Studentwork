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
    char buf[100] = "no date";
    int num;
    while(1)
    {
        lseek(fd,0,SEEK_SET);
        num = read(fd,buf,sizeof(buf));

        buf[strlen(buf)] = '\0';
       
        printf("buf%d = %s\n",num,buf);

        sleep(2);
    }

    return 0;
}

int write_pipe(int fd)
{
    char buf[100];

    memset(buf,0,sizeof(buf));

    while(1)
    {
        scanf("%s",buf);
        write(fd,buf,strlen(buf));
    }

}

int main()
{
    int pid;
    int fd;

    fd = open("pp",O_RDWR | O_CREAT,0755);

    pid = fork();
    if(pid > 0)
    {
        write_pipe(fd);
    }
    else if(pid == 0)
    {
        read_pipe(fd);
    }

    return 0;
}
