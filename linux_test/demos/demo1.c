#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

FILE *fd[4];
int num = 0;

void *writeThread(void *arg)
{
    int i;
    int tnum = (int)arg;
    int count = tnum;

    for(i = 0; i < 12; i++)
    {
        pthread_mutex_lock(&mutex);
        
        while(tnum != num)
        {
            pthread_cond_wait(&cond, &mutex);
        }

        fd[0] = fopen("file1", "a+");
        fd[1] = fopen("file2", "a+");
        fd[2] = fopen("file3", "a+");
        fd[3] = fopen("file4", "a+");

        putc('A' + tnum, fd[count]);

        fclose(fd[0]);
        fclose(fd[1]);
        fclose(fd[2]);
        fclose(fd[3]);

        num = (num + 1) % 4;

        count = (count + 3) % 4;

        pthread_mutex_unlock(&mutex);
        pthread_cond_broadcast(&cond);
    }
}

int main()
{
    int i;
    pthread_t id[4];

    for(i = 0; i < 4; i++)
    {
        if(pthread_create(&id[i], NULL, (void *)writeThread, (void *)i))
        {
            printf("create id[%d] error!\n");
        }
    }

    for(i = 0; i < 4; i++)
    {
        pthread_join(id[i], NULL);
    }

    return 0;
}
