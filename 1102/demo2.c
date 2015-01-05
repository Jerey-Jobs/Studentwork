/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

int main(int argc,char *argv[])
{
    int i;

    printf("argc = %d\n",argc);

    for(i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n",i,argv[i]);
    }

    return 0;
}
