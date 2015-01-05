/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

#define MAX 100

char *my_strchr(char *dest,int ch)
{
    while(*dest != '\0')
    {
        if(*dest == ch)
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
    char ch;
    char *p = NULL;

    printf("please input the first string : ");
    scanf("%s",src);

    getchar();

    printf("please input the point string : ");
    scanf("%c",&ch);
  
    p = my_strchr(src,ch);
     
    printf("the result is : %s\n ",p);

    return 0;
}
