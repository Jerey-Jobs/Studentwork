/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>
#include <pthread.h>

char buf[100] = "no msg";



void *my_scanf(void *arg)
{
    printf("num = %s\n",(char *)arg);
    while(1)
    {
        scanf("%s",buf);
        sleep(1);
    }
}

int main()
{
    pthread_t id;
    int ret;

    char *num = "hello";

    ret = pthread_create(&id,NULL,(void *)my_scanf,(void *)num);


    while(1)
    {
        printf("buf = %s\n",buf);
        sleep(1);
    }

    return 0;
}
