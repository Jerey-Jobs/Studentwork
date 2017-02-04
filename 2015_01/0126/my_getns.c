/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

int main()
{
    int n;
    int i;
    char str[20];

    for(i = 0; i < 20; i++)
    {
        str[i] = getchar();
        if(str[i] == '\n')
        {
            str[i] = '\0';
            break;
        }
    }

    str[19] = '\0'; 
    printf("%s\n",str);

    return 0;
}

