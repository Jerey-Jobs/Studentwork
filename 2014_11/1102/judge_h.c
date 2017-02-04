/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

#define MAX 100
#define NO 0
#define YES 1

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

int my_judge(char *head)
{
    char *tail = head + my_strlen(head) - 1;

    while(head < tail)
    {
        if(*head != *tail)
        {
            return NO;
        }

        head++;
        tail--;
    }

    return YES;
}


int main()
{
    char src[MAX];

    printf("please input the  string : ");
    scanf("%s",src);
    
    if(my_judge(src) == YES)
    {
        printf("the  string is yes\n");
    }
   
    if(my_judge(src) == NO)
    {
        printf("the  string is no\n ");
    }

    return 0;
}
