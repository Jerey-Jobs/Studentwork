/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

#define MAX 100

int my_strcpy(char *src,char *dest)
{
    while(*dest != '\0')
    {
        *src = *dest;
        src++;
        dest++;
    }
    *src = '\0';
}

int my_strlen(char *p)
{
    int len = 0;

    while(*p != '\0')
    {
        len++;
        p++;
    }
    return len;
}

int my_strcmp(char *src,char *p)
{
    while(*p != '\0')
    {
        if(*src != *p)
        {
            return 1;
        }
        p++;
        src++;
    }
    return 0;
}

char rm_str(char *src,char *p)
{
    int len = my_strlen(p);

    while(*src != '\0')
    {
        if(my_strcmp(src,p) == 0)
        {
            my_strcpy(src,src+len);
        }
        
        src++;
    }
    
}

int main()
{
    char src[MAX];
    char ptr[MAX];

    printf("please input the first string : ");
    scanf("%s",src);

    printf("please input the point string : ");
    scanf("%s",ptr);

    rm_str(src,ptr);

    printf("the result  is :%s\n ",src);


    return 0;
}
