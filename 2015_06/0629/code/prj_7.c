/**
 * @author evan alu
 * @date 2015/06/24
 */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int timer[] = {0, 5, 2, 5};
int sec = 0;
int cnt = 0;

void handler()
{
	signal(SIGALRM, handler);
	sec += timer[cnt++];
    printf("%d\n", sec);
	alarm(timer[cnt]);
}

int main(int argc, char *argv[])
{
    handler();

	int i;
	for(i = 0; i < 12; i++)
	{
		sleep(1);
  	}
	
    return 0;
}






