/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

#define MAX 100

char my_strcpy(char *dest,const char *src)
{
    while(*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
    
}

char my_strcat(char *dest,const char *src)
{
    while(*dest != '\0')
    {
        dest++;
    }

    while(*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
}


int main()
{
    char src[MAX];
    char dest[MAX];
    char ptr[MAX];

    printf("please input the src string : ");
    scanf("%s",src);

    printf("please input the dest string : ");
    scanf("%s",dest);

    printf("please input the ptr string : ");
    scanf("%s",ptr);
    
    my_strcpy(src,ptr);

    my_strcat(dest,ptr);

    printf("my_strcpy  is : %s\n",src);

    printf("my_strcat  is : %s\n",dest);


    return 0;
}
