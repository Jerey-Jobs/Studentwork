#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond;
int num = 0;

void *my_print(void *arg)
{
    int count= (int)arg;
    while(1)
    {
        pthread_mutex_lock(&mutex);

        while(count != num)
        {
            pthread_cond_wait(&cond,&mutex);
        }
        
      
        printf("%c\n",'a' + num);

        num = ++num % 4;

        pthread_mutex_unlock(&mutex);
        pthread_cond_broadcast(&cond);

        sleep(1);
    }
}

int main()
{
    int i = 0;
    int j;
	pthread_t id[4];

    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);
    
    for(j = 0; j < 4; j++)
    {
	    pthread_create(&id[j],0,(void *)my_print,(void *)j);
    }

    sleep(10);

	return 0;
}
