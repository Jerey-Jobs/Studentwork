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

	if (-1 == pipe(fd))
	{
		perror("Create pipe error ");
		exit(1);
	}

    if((pid = fork()) == 0)
	{
		close(fd[1]);        /* close write fd */
		len = read(fd[0], buf, sizeof(buf));
		buf[len] = 0;

		printf("Child read from pipe: %s\n", buf);
		close(fd[0]);
		exit(0);
	}
	else
	{
		close(fd[0]);        /* close read fd */
		printf("Father send \"hello world!\" to child!\n");
		write(fd[1], "hello world!", 12);
		close(fd[1]);
	}

	wait(NULL);
	return 0;
}


