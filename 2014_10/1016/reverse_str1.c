/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/
#include<stdio.h>

char *reverse_word(char *str)
{
    
    char *reverse_str(char *head, char *end);
    char *head;
    char *tail;

    head = str;
    
    while(*str != '\0')
    {
        if(*str == ' '||*str == '\0')
        {
            tail = str - 1;
            reverse_str(head, tail);
            head = str + 1;
        } 

        str++;
    }
}

char *reverse_str(char *head, char *end)
{ 
    char tmp;

    while(head < end)
    {
        tmp = *head;
        *head = *end;
        *end = tmp;
        head++;
        end--;
    }
   
}
int main()
{
    char str[100];
    printf("input:  ");
    gets(str);

    reverse_str(str, str + strlen(str) - 1);
    reverse_word(str);

    printf("output : %s\n",str);

    return 0;
}
