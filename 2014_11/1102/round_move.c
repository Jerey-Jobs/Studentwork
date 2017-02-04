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

int my_strcpy(char *ptr,char *src)
{
    while(*src != '\0')
    {
        *ptr = *src;
        ptr++;
        src++;
    }
}

int my_strcat(char *dest,char *src,char *p)
{
    char *tmp = dest + strlen(dest);

    while(src != p)
    {
        *tmp = *src;
        tmp++;
        src++;
    }
    
    *tmp = '\0';

}

char round_move(char *src,int n)
{
    char *p = NULL;
    static char tmp[MAX];

    n = n % strlen(src);

    p = src + strlen(src) - n;
   
    my_strcpy(tmp,p);

    my_strcat(tmp,src,p);

    my_strcpy(src,tmp);

}

int main()
{
    int num;
    char src[MAX];

    printf("please input the string : ");
    scanf("%s",src);

    printf("please input number :");
    scanf("%d",&num);

    round_move(src,num);
 
    printf("the  result  is : %s\n",src);

    return 0;
}
