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

#define FIFO "./tmp"

int main()
{
    char buffer[100] = "no msg";
    int fd;
    int pid;

    unlink(FIFO);
    mkfifo(FIFO,0666);

    pid = fork();

    if(pid > 0)
    {
        fd = open(FIFO,O_RDWR);
        while(1)
        {
            scanf("%s",buffer);
            write(fd,buffer,sizeof(buffer));
        }
        close(fd);
    }

    else if(pid == 0)
    {
        fd = open(FIFO,O_RDONLY | O_NONBLOCK);
        
        while(1)
        {
            read(fd,buffer,100);
            printf("buffer = %s\n",buffer); 
            sleep(2);
        }
        close(fd);
    }

    return 0;
}
