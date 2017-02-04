#include <stdio.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <errno.h>
#include <unistd.h>

int main()
{
    int pipe1_fd[2];
    int pipe2_fd[2];

    pid_t pid1;
    pid_t pid2;

    char buf1[10];
    char buf2[10];

    pipe(pipe1_fd);
    pid1 = fork();

    if(pid1 == 0)
    {
        pipe(pipe2_fd);
        pid2 = fork();

        if(pid2 == 0)
        {
            while(1)
            {
                printf("A\n");
                write(pipe2_fd[1], buf2, 10);
                sleep(1);
            }
        }
        else
        {
            while(1)
            {
                read(pipe2_fd[0], buf2, 10);
                printf("B\n");
                write(pipe1_fd[1], buf1, 10);
                sleep(1);
            }
        }
    }
    else
    {
        while(1)
        {
            read(pipe1_fd[0], buf1, 10);
            printf("C\n");
            sleep(1);
        }
    }

    return 0;
}
