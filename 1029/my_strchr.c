/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

char *my_strchr(char *str,char ch)
{
    while(*str != '\0')
    {
        if(*str == ch)
        {
            return str;
        }
        str++;
    }

    return NULL;
}

int main()
{
    char str[100];
    char c;
    char *p = NULL;
    
    printf("please input string :");
    scanf("%s",str);

    getchar();

    printf("please input the ch :");
    scanf("%c",&c);

    p = my_strchr(str,c);

    printf("result: %s\n",p);

    return 0;
}
