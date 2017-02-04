/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

#define MAX 100

int find_min(int *p)
{
    int i;
    int min;
    
    for(i = 0; i < 26; i++)
    {
        if(*(p + i) != 0)
        {
            min = *(p + i);
        }
    }

    for(i = 0; i < 26; i++)
    {
        if(*(p + i) < min && *(p + i) != 0)
        {
            min = *(p + i);
        }
    }
   
    return min;
}

char *del_char(char *src)
{
    int min;
    int count[26] = {0};
    char *flag = src;
    static  char result[MAX];
    char *p = result;
     
    while(*src != '\0')
    {
        count[*src - 'a']++;
        src++;
    }

    src = flag;

    min = find_min(count);
    
    while(*src != '\0')
    {
        if(count[*src - 'a'] > min)
        {
            *p = *src;
            p++;
        }

        src++;
    }

    *p = '\0';
    
    return result;
}

int main()
{
    char src[MAX];
    char *point;

    printf("please input the src string : ");
    scanf("%s",src);

    point = del_char(src);

    printf("the result  is :%s\n",point);

    return 0;
}
