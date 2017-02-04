/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

#include <unistd.h>

int main()
{
    char *a[] = {"ls","-al",NULL};
 
    execv("/bin/ls",a);

    return 0;
}
