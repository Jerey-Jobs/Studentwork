/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int my_getns(char *str,int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        str[i] = getchar();

        if(str[i] == '\n')
        {
            str[i] = '\0';
            break;
        }

    }

    str[n - 1] = '\0';

    return 0;
}
