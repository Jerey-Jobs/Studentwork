/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <myhead.h>

void func(int sign_no)
{
    if(sign_no == SIGINT)
    {
        printf("get sigint\n");
    }
    else if(sin_no == SIGQUIT)
    {
        printf("ger sigquit\n");
    }
}
int main()
{
    signal(SIGINT,func);
    signal(SIGQUIT,func);

    pause();
    exit();

    return 0;
}
