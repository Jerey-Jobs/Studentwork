/**
 * @author evan lau
 * @date 2015/06/13
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *timer(void *arg)
{
    int sec = (int)arg;

	sleep(sec);

	printf("%d !!!\n", sec);
}

int main(int argc, char **argv)
{
	pthread_t thread[3];
	int time[] = {5, 7, 12};
    int i;

	for (i = 0; i < 3; i++)
	{
		pthread_create(&thread[i], NULL, timer, (void *)time[i]);
	}
	

	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);
	pthread_join(thread[2], NULL);
	
    return 0;
}




