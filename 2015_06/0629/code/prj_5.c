/**
 * @author evan lau
 * @date 2015/06/13
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	pid_t pid;

	if((pid = fork()) == 0)
	{
		/**
         * Child process.
         */
		printf("Child.\n");
		sleep(5);
		exit(0);
	}
	else
	{
		/**
         * Father process.
         */
		printf("Father!\n");
	}

	wait(NULL);
	printf("Child process exits!\n");
	return 0;
}


