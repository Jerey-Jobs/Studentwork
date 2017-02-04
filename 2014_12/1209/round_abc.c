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
pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

void *print_a(void)
{
    int i;
    for(i = 0; i< 10; i++)
    {
        printf("A!\n");
        pthread_mutex_lock(&mutex1);
        sleep(1);
    }
}

void *print_b(void)
{
    int i;
    for(i = 0; i< 10; i++)
    {
        pthread_mutex_lock(&mutex1);
        printf("B!\n");
        sleep(1);
        pthread_mutex_lock(&mutex2);
    }
}

void *print_c(void)
{
    int i;
    for(i = 0; i< 10; i++)
    {
        pthread_mutex_unlock(&mutex2);
        printf("C!\n");
        sleep(1);
    }
}


int main()
{
    pthread_t id[3];
    int ret;
    int i;

    pthread_mutex_init(&mutex1,NULL);
    pthread_mutex_init(&mutex2,NULL);

    ret = pthread_create(&id[1],NULL,(void *)print_a,NULL);
    ret = pthread_create(&id[2],NULL,(void *)print_b,NULL);
    ret = pthread_create(&id[3],NULL,(void *)print_c,NULL);

    pthread_join(id[0],NULL);
    pthread_join(id[1],NULL);
    pthread_join(id[2],NULL);

    return 0;
}
