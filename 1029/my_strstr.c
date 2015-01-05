/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>
#include <string.h>

int my_strcmp(char *str,char *p)
{
    int len = strlen(p);
    int i;

    for(i = 0; i < len; i++)
    {
        if(*(str + i) != *(p + i))
        {
            return 0;
        }
    }

    return 1;
}

char *my_strstr(char *str,char *p)
{
    int tmp = 0;

    while(*str != '\0')
    {
        tmp = my_strcmp(str,p);
        
        if(tmp == 1)
        {
            return str;
        }

        str++;
    }

    return NULL;
}

int main()
{
    char str[100];
    char ptr[100];
    char *p = NULL;
    
    printf("please input string :");
    scanf("%s",str);

    getchar();

    printf("please input the ch :");
    scanf("%s",ptr);

    p = my_strstr(str,ptr);

    printf("result: %s\n",p);

    return 0;
}
