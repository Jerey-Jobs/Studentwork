/**
 * @author evan lau
 * @date 2015/06/13
 */

#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void signal_handler(int signo)
{
	char buf[16];
	printf("Do you want to quit? (y/N): ");
	scanf("%s", buf);
	if(strcmp("y", buf) == 0)
	{
        exit(0);
	}
}

int main(int argc, char **argv)
{
    signal(SIGINT, signal_handler);    /* SIGINT : Ctrl-c */

	while (1)
	{
		printf("hello world!\n");
		sleep(1);
	}
	
    return 0;
}






