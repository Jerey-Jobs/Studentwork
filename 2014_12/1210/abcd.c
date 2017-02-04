/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

int num = 0;
FILE *fp[4];
int file = 1;

void *write_func(void *arg)
{
    int i;
    int j;
    int count = (int)arg;

    for(i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex);

        while(count != num)
        {
            pthread_cond_wait(&cond,&mutex);
        }

        if(file > 4)
        {
            file = 4;
        }

        printf("线程%d在操作!写入文件中.....\n",count + 1);

        fp[0] = fopen("file1","a+");
        fp[1] = fopen("file2","a+");
        fp[2] = fopen("file3","a+");
        fp[3] = fopen("file4","a+");

        for(j = 0; j < file; j++)
        {
            putc('A' + count, fp[j]);
            putc('\n', fp[j]);
        }

        fclose(fp[0]);
        fclose(fp[1]);
        fclose(fp[2]);
        fclose(fp[3]);

        file++;

        num = (num + 1) % 4;

        pthread_mutex_unlock(&mutex);
        pthread_cond_broadcast(&cond);

        sleep(1);
    }
}

int main()
{
    int i;
    pthread_t fd[4];

    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);
    
    for(i = 0; i < 4; i++)
    {
        pthread_create(&fd[i],NULL,(void *)write_func,(void *)i);
    }

    for(i = 0; i < 4; i++)
    {
        pthread_join(fd[i],NULL);
    }
    return 0;
}
