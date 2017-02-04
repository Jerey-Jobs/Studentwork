/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>
#include <pthread.h>

int count = 10;
pthread_mutex_t mutex;

void *my_sell(void *arg)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        if(count > 0)
        {
            sleep(1);
            printf("have count ==>>> %d\n",--count);
        }
        else
        {
            printf("no have\n");
            pthread_mutex_unlock(&mutex);
            break;
        }
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_t id[5];
    int ret;
    int i;

    pthread_mutex_init(&mutex,NULL);

    for(i = 0; i < 5; i++)
    {
        ret = pthread_create(&id[i],NULL,(void *)my_sell,NULL);
    }

    for(i = 0; i < 5; i++)
    {
        pthread_join(id[i],NULL);
    }

    return 0;
}
