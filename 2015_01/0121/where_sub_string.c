/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>
#include <string.h>

int check(char *str,char *ptr)
{
    while(*ptr != '\0')
    {
        if(*ptr != *str)
        {
            return 1;
        }
        ptr++;
        str++;
    }

    return 0;
}

int find_position(char *str,char *ptr)
{
    int locate = 1;

    while(*str != '\0')
    {
        if(check(str,ptr) == 0)
        {
            return locate;
        }
        str++;
        locate++;
    }
}

int main()
{
    int num;
    char str[100];
    char ptr[100];

    scanf("%s%s",str,ptr);

    num = find_position(str,ptr);

    printf("%d",num);

    return 0;
}

