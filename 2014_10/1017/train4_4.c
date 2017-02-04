/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

int reverse(char *head, char *tail)
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

int reverse_str(char *str)
{
    char *head = str;
    char *tail;

    while(*str != '\0')
    {
        if(*str == ' ' || *str == '\0')
        {
            tail = str - 1;
            reverse(head, tail);
            head = str + 1;
        }

        str++;
    }
}

int main()
{
    char str[100];
        
    printf("input a string : ");
    gets(str);

    reverse(str, str + strlen(str) - 1);
    reverse_str(str);

    printf("output str :%s\n",str);

    return 0;
}
