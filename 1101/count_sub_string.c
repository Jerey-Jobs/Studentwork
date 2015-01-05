/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

#define MAX 100

int my_strcmp(char *dest,char *p)
{
    while(*p != '\0')
    {
        if(*dest != *p)
        {
            return 1;
        }

        p++;
        dest++;
    }

    return 0;
}

int count_sub_string(char *src,char *sub)
{
    int count = 0;
    
    while(*src != '\0')
    {
        if(my_strcmp(src,sub) == 0)
        {
            count++;
        }

        src++;
    }

    return count;
}

int main()
{
    char src[MAX];
    char sub[MAX];
    int count;

    printf("please input the first string : ");
    scanf("%s",src);

    printf("please input the point string : ");
    scanf("%s",sub);

    count = count_sub_string(src,sub);

    
    printf("the count of sub-string  is :%d\n",count);


    return 0;
}
