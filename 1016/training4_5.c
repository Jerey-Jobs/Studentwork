/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>


int my_strcmp(char *point, char *src)
{
    int len;
    int i;

    len = strlen(src);
    
    for(i = 0; i < len; i++)
    {
        if(*point != *src)
        {
            return 0;
        }
        point++;
        src++;
    }

    return 1;
}

int output_useful(char *str, char *head, char *tail)
{
    int tmp;
    char *start;
    char *end;

    while(*str != '\0')
    {
        tmp = my_strcmp(str, head);
        
        if(tmp == 1)
        {
            start = str;
        }

        str++;
    }

    str = start;


    while(*str != '\0')
    {
        tmp = my_strcmp(str, tail);

        if(tmp == 1)
        {
            *(str + strlen(tail)) = '\0';
        }

        str++;
    }

    printf("output : %s\n",start);

    return 0;
}

int main()
{
    char str[100];
    char head[100];
    char tail[100];

    printf("input string :");
    scanf("%s",str);

    printf("input head :");
    scanf("%s",head);

    printf("input tail :");
    scanf("%s",tail);
 
    output_useful(str,head,tail);


    return 0;
}
