/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>
#include <string.h>

#define MAX 100

int my_strcmp(char *dest,char *p)
{
    int len = strlen(p);

    while(len > 0)
    {
        if(*dest != *p)
        {
            return 1;
        }
        dest++;
        p++;
        len--;
    }

    return 0;
}

char *my_strstr(char *dest,char *src)
{
    while(*dest != '\0')
    {
        if(my_strcmp(dest,src) == 0)
        {
            return dest;
        }

        dest++;
    }
    return NULL;
}

int main()
{
    char src[MAX];
    char ptr[MAX];
    char *p = NULL;

    printf("please input the first string : ");
    scanf("%s",src);

    getchar();

    printf("please input the point string : ");
    scanf("%s",ptr);
  
    p = my_strstr(src,ptr);
     
    printf("the result is : %s\n ",p);

    return 0;
}
