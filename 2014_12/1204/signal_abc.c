/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <myhead.h>
void print_b(int sig_n)
{
    printf("B\n");
}

void print_c(int sig_n)
{
    printf("C\n");
}

int main()
{
    int pid1;
    int pid2;
    
    pid1 = fork();
    
    if(pid1 > 0)
    {
        sleep(1);
        while(1)
        {
            printf("A\n");
            kill(pid1,SIGUSR1);
            sleep(2);
        }
    }
    else if(pid1 == 0)
    {
        pid2 = fork();

        if(pid2 > 0)
        {
            signal(SIGUSR1,print_b);
            sleep(2);
            while(1)
            {
                kill(pid2,SIGUSR2);
                sleep(2);
            }

        }
        else if(pid2 == 0)
        {
                signal(SIGUSR2,print_c);
            while(1)
            {
                //signal(SIGUSR2,print_c);
                sleep(2);
            }
        }
    }
    
    return 0;
}
