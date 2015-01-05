/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <myhead.h>

int main()
{
    int pid;
    int cpid;
    int fd_1[2];
    int fd_2[2];

    char buf1[10];
    char buf2[10];

    pipe(fd_1);

    pid = fork();
    if(pid > 0)
    {
        close(fd_1[0]);
        while(1)
        {
            printf("A\n");
            write(fd_1[1],"A",1);
            sleep(2);
        }
    }
    else if(pid == 0)
    {
        pipe(fd_2);
        cpid = fork();
        
        if(cpid > 0)
        {
            close(fd_1[1]);
            while(1)
            {
                read(fd_1[0],buf1,10);
                printf("B\n");
                write(fd_2[1],"B",1);
                sleep(2);
            }
        }
        if(cpid == 0)
        {
            while(1)
            {
                read(fd_2[0],buf2,10);
                printf("C\n");
                sleep(2);
            }

        }
    }

    return 0;
}
