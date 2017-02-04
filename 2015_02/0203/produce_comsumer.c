#include <stdio.h>
#include <pthread.h>

#define MAX 100

int store_num;
pthread_mutex_t mutex;
pthread_cond_t cond;

void *consumer(void *arg)
{
    printf("开始消费\n");
    int need= (int)arg;

    pthread_mutex_lock(&mutex);
    while(need > store_num)
    {
        pthread_cond_wait(&cond,&mutex);
    }

    store_num = store_num - need;
    printf("消费者消耗了%d 目前剩余 %d\n",need,store_num);
    pthread_mutex_unlock(&mutex);
}

void *producer(void *arg)
{
    int p_num = (int)arg;
    pthread_mutex_lock(&mutex);
    while(p_num + store_num > MAX)
    {
    	printf("生产数量 %d 超过仓库容量 %d  不能生产\n",p_num,p_num + store_num - MAX);
    	pthread_cond_wait(&cond,&mutex);
    }
    
    store_num = store_num + p_num;
    printf("生产了 %d 仓库余量 %d\n",p_num,store_num);
    pthread_mutex_unlock(&mutex);
    pthread_cond_broadcast(&cond);
}

int main()
{
	pthread_t con_id;
    pthread_t pro_id;
    pthread_t store_id;

    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);

    store_num = 30;
    pthread_create(&con_id,NULL,(void *)consumer,(void *)10);
    pthread_create(&con_id,NULL,(void *)consumer,(void *)30);
    pthread_create(&con_id,NULL,(void *)consumer,(void *)50);

    pthread_create(&pro_id,NULL,(void *)producer,(void *)10);
    pthread_create(&pro_id,NULL,(void *)producer,(void *)10);
    pthread_create(&pro_id,NULL,(void *)producer,(void *)10);
    pthread_create(&pro_id,NULL,(void *)producer,(void *)10);
    pthread_create(&pro_id,NULL,(void *)producer,(void *)10);
    pthread_create(&pro_id,NULL,(void *)producer,(void *)40);
    pthread_create(&pro_id,NULL,(void *)producer,(void *)80);

    sleep(10);
    printf("ssssss");
}
