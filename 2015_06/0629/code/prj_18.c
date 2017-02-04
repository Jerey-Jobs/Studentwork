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

    pthread_create(&thread, NULL, read_from_file, NULL);

	while(1)
	{
        buf = getchar();
		if(buf == 'E')
		{
			pthread_cancel(thread);   //kill sub thread
			
            exit(0);
		}
		sleep(1);
	}
	
	return 0;
}






