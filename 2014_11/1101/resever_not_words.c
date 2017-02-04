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

int reverse(char *head,char *tail)
{
    char tmp;

    while(head < tail)
    {
        tmp = *head;
        *head = *tail;
        *tail = tmp;
        head++;
        tail--;
    }
}

int reverse_not_words(char *src)
{
    reverse(src,src + strlen(src) - 1);
    char *head = src;
    char *tail = NULL;

    while(*src != '\0')
    {
        if(*src == ' ' || *src == '\0' )
        {
            tail = src - 1;
            reverse(head,tail);
            head = src + 1;
        }
        src++;
    }

}

int main()
{
    char src[MAX];

    printf("please input the first string : ");
    gets(src);

    reverse_not_words(src);
    
    printf("the result  is : %s\n",src);

    return 0;
}
