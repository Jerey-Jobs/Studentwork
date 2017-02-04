#include <stdio.h>
#include <pthread.h>


#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

int count = 0;

pthread_mutex_t mutex;
pthread_cond_t cond;

void *pthread1_func(void *arg)
{  
	int num = (int)arg;
	int i;
	for(i = 0; i < 10; i++)
	{
		pthread_mutex_lock(&mutex);
        printf("pthread %d running\n",num);
        sleep(1);
        pthread_mutex_unlock(&mutex);
        sleep(1);            
    }
}


int main()
{
    pthread_t pid1;
    pthread_t pid2;
    pthread_t pid3;

    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);

    pthread_create(&pid1,NULL,(void *)pthread1_func,(void *)1);
    pthread_create(&pid2,NULL,(void *)pthread1_func,(void *)2);
    pthread_create(&pid3,NULL,(void *)pthread1_func,(void *)3);  

    pthread_join(pid1,NULL);
    pthread_join(pid2,NULL);
    pthread_join(pid3,NULL);

	return 0;
}



